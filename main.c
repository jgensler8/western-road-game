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

uint8_t input_last = 0;
uint8_t joypad_a_pressed = 0;
uint8_t joypad_b_pressed = 0;
uint8_t joypad_start_pressed = 0;
uint8_t joypad_select_pressed = 0;
uint8_t joypad_up_pressed = 0;
uint8_t joypad_down_pressed = 0;
uint8_t joypad_left_pressed = 0;
uint8_t joypad_right_pressed = 0;
// stateful input using global variable
void scan_input(void)
{
    // exclusive or
    uint8_t input = joypad();
    if (!input)
    {
        input_last = 0;
    }
    if (input ^ input_last)
    {
        input_last = input;
        joypad_a_pressed = input & J_A;
        joypad_b_pressed = input & J_B;
        joypad_start_pressed = input & J_START;
        joypad_select_pressed = input & J_SELECT;
        joypad_up_pressed = input & J_UP;
        joypad_down_pressed = input & J_DOWN;
        joypad_left_pressed = input & J_LEFT;
        joypad_right_pressed = input & J_RIGHT;
    }
    else
    {
        joypad_a_pressed = 0;
        joypad_b_pressed = 0;
        joypad_start_pressed = 0;
        joypad_select_pressed = 0;
        joypad_up_pressed = 0;
        joypad_down_pressed = 0;
        joypad_left_pressed = 0;
        joypad_right_pressed = 0;
    }
}

#define MENU_MAX_OPTIONS 8
struct Menu
{
    uint8_t selection;
    uint8_t max_option;
    char *options[MENU_MAX_OPTIONS];
};

uint8_t menu_process_input(struct Menu *menu)
{
    if (joypad_down_pressed)
    {
        if (menu->selection != menu->max_option)
        {
            menu->selection += 1;
        }
    }
    else if (joypad_up_pressed)
    {
        if (menu->selection != 0)
        {
            menu->selection -= 1;
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

struct Scene
{
    void (*process_input)(void);
    void (*render)(uint8_t swapped);
};
struct Scene *current_scene = NULL;
struct Scene *next_scene = NULL;
void queue_scene(struct Scene *new_next_scene)
{
    next_scene = new_next_scene;
    menu_reset_state();
}

enum Stat
{
    STAT_NONE,
    STAT_STEPS,
    STAT_DISTANCE,
    STAT_GOLD,
    STAT_COUNT,
};

enum StatChange
{
    STAT_CHANGE_INC,
    STAT_CHANGE_DEC,
    STAT_CHANGE_MUL,
};

struct StatCalculation
{
    enum Stat src;
    enum Stat dst;
    enum StatChange change;
};

#define MAX_STAT_CALCULATIONS 32
struct State
{
    struct StatCalculation calculations[MAX_STAT_CALCULATIONS];
};
struct State default_state;

#define EMPTY "\0"

uint8_t scene_story_dialog_progress = 0;
char *dialogs[5] = {
    "YOU FEEL",
    "PRETTY WEIRD",
    "JUST WOKE UP",
    "TIME TO GET OUT\nOF BED!",
    "DONE\n",
};
void scene_story_process_input(void)
{
    if (scene_story_dialog_progress < 4)
    {
        if (joypad_a_pressed)
        {
            scene_story_dialog_progress++;
        }
    }
    else
    {
        // queue_scene();
    }
}
uint8_t scene_story_last_render_progress;
void scene_story_render(uint8_t swapped)
{
    if (swapped)
    {
        scene_story_dialog_progress = 0;
        scene_story_last_render_progress = 0xff;
    }
    if (scene_story_dialog_progress != scene_story_last_render_progress)
    {
        draw_frame_text(dialogs[scene_story_dialog_progress], EMPTY);
        scene_story_last_render_progress = scene_story_dialog_progress;
    }
}
struct Scene scene_story = {
    .process_input = scene_story_process_input,
    .render = scene_story_render,
};

struct Menu start_menu = {
    .options = {
        "START",
        "LOAD",
    },
    .max_option = 1,
    .selection = 0,
};
void scene_title_process_input(void)
{
    if (menu_process_input(&start_menu))
    {
        switch (start_menu.selection)
        {
        case 0:
            queue_scene(&scene_story);
            break;
        case 1:
            // TODO: save/load
            // queue_scene();
            break;
        }
    }
}
void scene_title_render(uint8_t swapped)
{
    if (swapped)
    {
        start_menu.selection = 0;
    }
    menu_render(&start_menu);
}

struct Scene scene_title = {
    .process_input = scene_title_process_input,
    .render = scene_title_render,
};
void main(void)
{
    init_font_vram();
    init_frame_vram();
    struct StatCalculation default_calculation = {
        .src = STAT_STEPS,
        .dst = STAT_DISTANCE,
        .change = STAT_CHANGE_INC,
    };
    default_state.calculations[0] = default_calculation;
    queue_scene(&scene_title);

    uint8_t swapped = 0;
    while (1)
    {
        scan_input();
        if (current_scene)
        {
            current_scene->process_input();
        }
        // maybe swap scene but do not immediately render it
        if (next_scene != NULL && next_scene != current_scene)
        {
            current_scene = next_scene;
            next_scene = NULL;
            swapped = 1;
        }
        else
        {
            if (current_scene)
            {
                current_scene->render(swapped);
            }
            if (swapped)
            {
                swapped = 0;
            }
        }
    }
}
