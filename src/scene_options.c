#pragma bank 0
#include "scene_options.h"

static uint8_t submenu_swapped;
static uint8_t main_menu_cursor;
static uint8_t main_menu_cursor_last;

static enum Focus {
    MAIN_MENU,
    VIEW_STATS,
    VIEW_ITEMS,
};
static enum Focus focus;

static inline void set_focus(enum Focus new_focus)
{
    focus = new_focus;
    submenu_swapped = 1;
}

static void process_input(void)
{
    if (joypad_start_pressed)
    {
        scene_options_takeover = 0;
        HIDE_WIN;
        SHOW_SPRITES;
        return;
    }
    switch (focus)
    {
    case MAIN_MENU:
        if (joypad_up_pressed)
        {
            if (main_menu_cursor > 0)
            {
                main_menu_cursor_last = main_menu_cursor;
                main_menu_cursor--;
            }
        }
        else if (joypad_down_pressed)
        {
            if (main_menu_cursor < 2)
            {
                main_menu_cursor_last = main_menu_cursor;
                main_menu_cursor++;
            }
        }
        else if (joypad_a_pressed)
        {
            switch (main_menu_cursor)
            {
            case 0:
                set_focus(VIEW_STATS);
                break;
            case 1:
                set_focus(VIEW_ITEMS);
                break;
            }
        }
        else if (joypad_b_pressed)
        {
            scene_options_takeover = 0;
            HIDE_WIN;
            SHOW_SPRITES;
            return;
        }
        break;
    case VIEW_STATS:
        if (joypad_b_pressed)
        {
            set_focus(MAIN_MENU);
        }
        break;
    case VIEW_ITEMS:
        if (joypad_b_pressed)
        {
            set_focus(MAIN_MENU);
        }
        break;
    }
}

static void render(struct SceneRenderOptions *options)
{
    if (scene_options_swapped)
    {
        SHOW_WIN;
        HIDE_SPRITES;
        scene_options_swapped = 0;
        main_menu_cursor = 0;
        main_menu_cursor_last = 1;
        focus = MAIN_MENU;
        submenu_swapped = 1;
    }
    if (submenu_swapped)
    {
        fill_win_rect(0, 0, 20, 18, 0);
        switch (focus)
        {
        case MAIN_MENU:
            draw_frame_win(0, 0, 20, 18);
            xy_printf_win(6, 0, "OPTIONS");
            xy_printf_win(2, 1, "VIEW STATS");
            xy_printf_win(2, 2, "VIEW ITEMS");
            break;
        case VIEW_STATS:
            draw_frame_win(0, 0, 20, 18);
            xy_printf_win(6, 0, "STATS");
            break;
        case VIEW_ITEMS:
            draw_frame_win(0, 0, 20, 14);
            xy_printf_win(6, 0, "ITEMS");
            break;
        }
        submenu_swapped = 0;
    }
    switch (focus)
    {
    case MAIN_MENU:
        xy_printf_win(1, 1 + main_menu_cursor, ">");
        xy_printf_win(1, 1 + main_menu_cursor_last, " ");
        break;
    }
}

uint16_t scene_options_swapped;
uint16_t scene_options_takeover;

BANKREF(scene_options_ref)
struct Scene scene_options = {
    .process_input = process_input,
    .render = render,
};