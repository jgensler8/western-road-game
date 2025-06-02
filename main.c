/*
    fonts.c
    Simple example of how to use multiple fonts on the GB
    Michael Hope, 1999.
*/

#include <stdio.h>
#include <string.h>
#include <gbdk/platform.h>
// #include <gb/gb.h>

#include "lankygitmono.h"
#include "sframe7.h"

#define ALPHABET_TILE_START 0
void xy_printf(uint8_t screen_x, uint8_t screen_y, char *word)
{
    uint8_t len = strlen(word);
    for (uint8_t c = 0; c < len; c++)
    {
        set_bkg_tile_xy(screen_x + c, screen_y, ALPHABET_TILE_START + word[c] - ' ');
    }
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

void draw_frame_text(char *line_1, char *line_2)
{
    clear_bkg_frame();
    xy_printf(1, 15, line_1);
    xy_printf(1, 16, line_2);
    draw_frame(0, 14, 20, 4);
    SHOW_BKG;
}

uint8_t press_wait = 0;
void wait_press(uint8_t button)
{
    if (press_wait)
    {
        while (joypad() & button)
        {
        }
        press_wait = 0;
    }
    while (!(joypad() & button))
    {
        // do nothing
        press_wait = 1;
    }
}

uint8_t prompt_menu_2(char *o1, char *o2)
{
    uint8_t menu_selection = 0;
    uint8_t last_render_menu_selection = 1;
    uint8_t min_option = 0;
    uint8_t max_option = 1;
    clear_bkg_frame();
    while (joypad())
    {
    }
    uint8_t drew_frame = 0;
    while (1)
    {
        // handle input
        if (joypad() & J_DOWN)
        {
            menu_selection += 1;
            menu_selection = menu_selection > max_option ? max_option : menu_selection;
        }
        else if (joypad() & J_UP)
        {
            menu_selection -= 1;
            // wrapped
            menu_selection = menu_selection > max_option + 1 ? min_option : menu_selection;
        }
        if (joypad() & J_A)
        {
            break;
        }
        // render frame
        if (!drew_frame)
        {
            draw_frame_text(o1, o2);
            drew_frame = 1;
        }
        // render cursor
        if (menu_selection != last_render_menu_selection)
        {
            for (uint8_t possible_sel = 0; possible_sel <= max_option; possible_sel++)
            {
                if (possible_sel == menu_selection)
                {
                    set_bkg_tile_xy(0, 15 + possible_sel, 'X' - ' ');
                }
                else
                {
                    set_bkg_tile_xy(0, 15 + possible_sel, 0);
                }
            }
            last_render_menu_selection = menu_selection;
        }
    }
    return menu_selection;
}

#define EMPTY "\0"
void main(void)
{
    init_font_vram();
    init_frame_vram();

    clear_bkg();
    draw_frame_text("HELLO!", "THERE...");
    wait_press(J_A);
    switch (prompt_menu_2("JUMP", "RUN"))
    {
    case 0:
        draw_frame_text("WISE!", EMPTY);
        break;
    case 1:
        draw_frame_text("BAD!", EMPTY);
        break;
    }
}
