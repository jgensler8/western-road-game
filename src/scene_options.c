#pragma bank 0
#include "scene_options.h"

static uint8_t submenu_swapped;
static uint8_t main_menu_cursor;
static uint8_t main_menu_cursor_last;
static uint8_t items_cursor;
static uint8_t items_cursor_last;
#define MAX_VIEWABLE_ITEMS 12
static uint8_t viewable_items[MAX_VIEWABLE_ITEMS] = {0};

static enum Focus {
    MAIN_MENU,
    VIEW_OBJETIVES,
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
                set_focus(VIEW_OBJETIVES);
                break;
            case 1:
                set_focus(VIEW_STATS);
                break;
            case 2:
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
    case VIEW_OBJETIVES:
        if (joypad_b_pressed)
        {
            set_focus(MAIN_MENU);
        }
        break;
    case VIEW_STATS:
        if (joypad_b_pressed)
        {
            set_focus(MAIN_MENU);
        }
        break;
    case VIEW_ITEMS:
        if (joypad_up_pressed)
        {
            if (items_cursor > 0)
            {
                items_cursor -= 1;
            }
        }
        else if (joypad_down_pressed)
        {
            if (items_cursor < MAX_VIEWABLE_ITEMS)
            {
                items_cursor += 1;
            }
        }
        else if (joypad_b_pressed)
        {
            set_focus(MAIN_MENU);
        }
        break;
    }
}

static void print_quest(void)
{
    const uint8_t quest_x = 1;
    const uint8_t quest_y = 2;
    switch (default_state.quest)
    {
    case QUEST_NONE:
        xy_printf_win(quest_x, quest_y, "NONE");
        break;
    case QUEST_CHERI_QUEST_1:
        xy_printf_win(quest_x, quest_y, "CHERI: SHACK");
        break;
    case QUEST_VERONICA_QUEST_1:
        xy_printf_win(quest_x, quest_y, "VERONICA: DELIVER");
        xy_printf_win(quest_x, quest_y + 1, "PACKAGE TO SHOP");
        break;
    }
}

static void print_goal(void)
{
    const uint8_t goal_x = 1;
    const uint8_t goal_y = 10;
    switch (default_state.goal)
    {
    case GOAL_NONE:
        xy_printf_win(goal_x, goal_y, "NONE");
        break;
    case GOAL_DEFAULT:
        xy_printf_win(goal_x, goal_y, "DEFAULT");
        break;
    case GOAL_100_STEPS:
        xy_printf_win(goal_x, goal_y, "100 STEPS");
        break;
    case GOAL_100_GOLD:
        xy_printf_win(goal_x, goal_y, "100 GOLD");
        break;
    case GOAL_MINUS_100_STEPS:
        xy_printf_win(goal_x, goal_y, "-100 STEPS");
        break;
    case GOAL_MINUS_100_GOLD:
        xy_printf_win(goal_x, goal_y, "-100 GOLD");
        break;
    }
}

static inline void print_stats(void)
{
    uint8_t row = 1;
    const uint8_t text_x = 1;
    const uint8_t stat_x = 16;
    for (uint8_t st = STAT_NONE + 1; st < STAT_COUNT && row < 9; st++, row++)
    {
        switch (st)
        {
        case STAT_STEPS:
            xy_printf_win(text_x, row, "STEPS");
            xy_printf_win(stat_x, row, fixed_itoa(default_state.stats[STAT_STEPS]));
            break;
        case STAT_DISTANCE:
            xy_printf_win(text_x, row, "DISTANCE");
            break;
        case STAT_GOLD:
            xy_printf_win(text_x, row, "GOLD");
            break;
        }
    }
}

static void print_items(void)
{
    uint8_t row = 0;
    const uint8_t text_x = 2;
    const uint8_t name_y = 1;
    for (uint8_t i = ITEM_NONE + 1; i < ITEM_COUNT && row < MAX_VIEWABLE_ITEMS; i++)
    {
        if (default_state.items[i] == 0)
        {
            continue;
        }
        viewable_items[row] = i;
        xy_printf_win(text_x, name_y + row, item_name(i));
        row += 1;
    }
}

static void print_item_cursor(void)
{
    if (items_cursor == items_cursor_last)
    {
        return;
    }
    xy_printf_win(1, 1 + items_cursor, ">");
    xy_printf_win(1, 1 + items_cursor_last, " ");
    items_cursor_last = items_cursor;
}

static void print_item_details(void)
{
    if (items_cursor == items_cursor_last)
    {
        return;
    }
    fill_win_rect(1, MAX_VIEWABLE_ITEMS + 3, 18, 2, 0);
    const uint8_t text_x = 1;
    const uint8_t details_y = MAX_VIEWABLE_ITEMS + 3;
    uint8_t item = viewable_items[items_cursor];
    xy_printf_win(text_x, details_y, item_details[item][0]);
    xy_printf_win(text_x, details_y + 1, item_details[item][1]);
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
            xy_printf_win(2, 1, "VIEW OBJECTIVES");
            xy_printf_win(2, 2, "VIEW STATS");
            xy_printf_win(2, 3, "VIEW ITEMS");
            break;
        case VIEW_OBJETIVES:
            // objective header
            draw_frame_win(0, 0, 20, 2);
            xy_printf_win(4, 0, "OBJECTIVES");
            // quest box
            draw_frame_win(0, 1, 20, 9);
            xy_printf_win(2, 1, "QUEST");
            print_quest();
            // goal box
            draw_frame_win(0, 9, 20, 9);
            xy_printf_win(2, 9, "GOAL");
            print_goal();
            break;
        case VIEW_STATS:
            draw_frame_win(0, 0, 20, 18);
            xy_printf_win(6, 0, "STATS");
            print_stats();
            break;
        case VIEW_ITEMS:
            items_cursor = 0;
            items_cursor_last = 254;
            draw_frame_win(0, 0, 20, MAX_VIEWABLE_ITEMS + 2);
            draw_frame_win(0, MAX_VIEWABLE_ITEMS + 2, 20, 4);
            xy_printf_win(6, 0, "ITEMS");
            print_items();
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
    case VIEW_OBJETIVES:
    case VIEW_STATS:
    case VIEW_ITEMS:
        print_item_details();
        print_item_cursor();
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