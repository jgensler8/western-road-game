#include "text.h"
#include <string.h>
#include <gbdk/platform.h>
#include "lankygitmono.h"
#include "sframe7.h"
#include "sound.h"
#include "input.h"

#define ALPHABET_TILE_START 0
void xy_printf(uint8_t screen_x, uint8_t screen_y, char *word)
{
    uint8_t len = strlen(word);
    for (uint8_t c = 0; c < len; c++)
    {
        set_bkg_tile_xy(screen_x + c, screen_y, ALPHABET_TILE_START + word[c] - ' ');
    }
}

void xy_printf_progress(uint8_t screen_x, uint8_t screen_y, char *word, uint8_t *progress)
{
    set_bkg_tile_xy(screen_x + *progress, screen_y, ALPHABET_TILE_START + word[*progress] - ' ');
}

void draw_frame(uint8_t screen_x, uint8_t screen_y, uint8_t width, uint8_t height)
{
    uint8_t frame_tile_start = 'Z' - ' ' + 1;
    // corners
    set_bkg_tile_xy(screen_x, screen_y, frame_tile_start + 0);
    set_bkg_tile_xy(screen_x + width - 1, screen_y, frame_tile_start + 2);
    set_bkg_tile_xy(screen_x, screen_y + height - 1, frame_tile_start + 6);
    set_bkg_tile_xy(screen_x + width - 1, screen_y + height - 1, frame_tile_start + 8);
    // row
    for (uint8_t c = 1; c < width - 1; c++)
    {
        // top
        set_bkg_tile_xy(screen_x + c, screen_y, frame_tile_start + 1);
        // bottom
        set_bkg_tile_xy(screen_x + c, screen_y + height - 1, frame_tile_start + 7);
    }
    // columns
    for (uint8_t c = 1; c < height - 1; c++)
    {
        // left
        set_bkg_tile_xy(screen_x, screen_y + c, frame_tile_start + 3);
        // right
        set_bkg_tile_xy(screen_x + width - 1, screen_y + c, frame_tile_start + 5);
    }
}

void clear_bkg(void)
{
    // this is the space tile
    uint8_t tile = 0;
    fill_bkg_rect(0, 0, 31, 31, tile);
}

void clear_bkg_frame(void)
{
    // this is the space tile
    uint8_t tile = 0;
    fill_bkg_rect(0, 14, 31, 4, tile);
}

void init_font_vram(void)
{
    set_bkg_1bpp_data(0, 'Z' - ' ' + 1, lankygitmono_tiles);
}

void init_frame_vram(void)
{
    set_bkg_1bpp_data('Z' - ' ' + 1, 9, sframe7_tiles);
}

void text_init(void)
{
    init_font_vram();
    init_frame_vram();
}

void draw_frame_text(char *line_1, char *line_2)
{
    clear_bkg_frame();
    draw_frame(0, 14, 20, 4);
    xy_printf(1, 15, line_1);
    xy_printf(1, 16, line_2);
    SHOW_BKG;
}

void frame_progress_init(char *line_1, char *line_2, struct ProgressableFrame *frame)
{
    frame->wait = 0;
    frame->line_1 = line_1;
    frame->line_1_len = strlen(line_1);
    frame->line_2 = line_2;
    frame->line_2_len = strlen(line_2);
    frame->l1_progress = 0;
    frame->l2_progress = 0;
}
// return 1 if progress happened, return 0 if no progress is left
uint8_t draw_frame_progress(struct ProgressableFrame *frame)
{
    if (frame->wait > 0)
    {
        frame->wait -= 1;
        return 1;
    }
    if (frame->l1_progress == 0 && frame->l2_progress == 0)
    {
        // only run this once
        clear_bkg_frame();
        draw_frame(0, 14, 20, 4);
    }
    if (frame->l1_progress < frame->line_1_len)
    {
        xy_printf_progress(1, 15, frame->line_1, &frame->l1_progress);
        frame->l1_progress += 1;
        frame->wait = PROGRESS_FRAME_WAIT;
        return 1;
    }
    else if (frame->l2_progress < frame->line_2_len)
    {
        xy_printf_progress(1, 16, frame->line_2, &frame->l2_progress);
        frame->l2_progress += 1;
        frame->wait = PROGRESS_FRAME_WAIT;
        return 1;
    }
    return 0;
}

uint8_t menu_process_input(struct Menu *menu)
{
    if (joypad_down_pressed)
    {
        if (menu->selection != menu->max_option)
        {
            menu->selection += 1;
            play_sfx_blip();
        }
    }
    else if (joypad_up_pressed)
    {
        if (menu->selection != 0)
        {
            menu->selection -= 1;
            play_sfx_blip();
        }
    }
    if (joypad_a_pressed)
    {
        return 1;
    }
    return 0;
}

uint8_t menu_render_last_render_menu_selection = 1;
uint8_t menu_render_drew_frame = 0;
void menu_reset_state(void)
{
    menu_render_last_render_menu_selection = MENU_MAX_OPTIONS + 1;
    menu_render_drew_frame = 0;
}
void menu_render(struct Menu *menu)
{
    if (!menu_render_drew_frame)
    {
        draw_frame_text(menu->options[0], menu->options[1]);
        menu_render_drew_frame = 1;
    }
    // render cursor
    if (menu->selection != menu_render_last_render_menu_selection)
    {
        for (uint8_t possible_sel = 0; possible_sel <= menu->max_option; possible_sel++)
        {
            if (possible_sel == menu->selection)
            {
                set_bkg_tile_xy(0, 15 + possible_sel, 'X' - ' ');
            }
            else
            {
                set_bkg_tile_xy(0, 15 + possible_sel, 0);
            }
        }
        menu_render_last_render_menu_selection = menu->selection;
    }
}
