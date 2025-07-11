#pragma bank 3
#include "scene_shop.h"
#include "scene_road.h"
#include <stdio.h>

#define SHOP_LINES 12
static enum Item store_items[SHOP_LINES] = {0};

static void generate_store_items(void)
{
    store_items[0] = ITEM_OVERALLS;
    store_items[1] = ITEM_BAG;
    store_items[2] = ITEM_CRYSTAL;
}

static uint8_t cursor_index = 0;
static uint8_t cursor_index_last = 1;
static struct Menu confirm_purchase_menu = {
    .options = {
        "CONFIRM PURCHASE",
        "BACK TO SHOP",
    },
    .max_option = 1,
};
static struct Menu leave_confirm_menu = {
    .options = {
        "READY TO LEAVE",
        "BACK TO SHOP",
    },
    .max_option = 1,
};
static enum Focus {
    SHOP,
    PURCHASE_CONFIRM,
    LEAVE_CONFIRM,
};
static enum Focus focus;
static uint8_t focus_changed;
static void set_focus(enum Focus new_focus)
{
    focus = new_focus;
    focus_changed = 1;
    menu_reset_state();
}

BANKREF_EXTERN(scene_road_ref)
static void process_input_shop(void)
{
    if (joypad_b_pressed)
    {
        // queue_scene(&scene_road, BANK(scene_road_ref));
        set_focus(LEAVE_CONFIRM);
        return;
    }
    // cursor handling
    if (joypad_up_pressed)
    {
        // do not wrap cursor
        if (cursor_index > 0)
        {
            cursor_index_last = cursor_index;
            cursor_index--;
        }
    }
    else if (joypad_down_pressed)
    {
        cursor_index_last = cursor_index;
        cursor_index++;
    }
    if (cursor_index > 2)
    {
        cursor_index = 2;
    }
    if (joypad_a_pressed)
    {
        if (default_state.stats[STAT_GOLD] < item_price(store_items[cursor_index]))
        {
            return;
        }
        if (store_items[cursor_index] == ITEM_NONE)
        {
            return;
        }
        set_focus(PURCHASE_CONFIRM);
    }
}

static inline void do_purchase(void)
{
    if (store_items[cursor_index] == ITEM_NONE)
    {
        return;
    }
    default_state.stats[STAT_GOLD] -= item_price(store_items[cursor_index]);
    default_state.items[store_items[cursor_index]] += 1;
    store_items[cursor_index] = ITEM_NONE;
}

static void process_input_purchase_confirm(void)
{
    if (joypad_b_pressed)
    {
        set_focus(SHOP);
        confirm_purchase_menu.selection = 0;
    }
    if (menu_process_input(&confirm_purchase_menu))
    {
        if (confirm_purchase_menu.selection == 0)
        {
            do_purchase();
        }
        set_focus(SHOP);
        confirm_purchase_menu.selection = 0;
    }
}
static void process_input_leave_confirm(void)
{
    if (menu_process_input(&leave_confirm_menu))
    {
        switch (leave_confirm_menu.selection)
        {
        case 0:
            queue_scene(&scene_road, BANK(scene_road_ref));
            break;
        case 1:
            set_focus(SHOP);
            break;
        }
    }
    if (joypad_b_pressed)
    {
        set_focus(SHOP);
    }
}
static void process_input(void)
{
    switch (focus)
    {
    case SHOP:
        process_input_shop();
        break;
    case PURCHASE_CONFIRM:
        process_input_purchase_confirm();
        break;
    case LEAVE_CONFIRM:
        process_input_leave_confirm();
        break;
    }
}

static void render_cursor(void)
{
    xy_printf(1, 1 + cursor_index_last, " ");
    xy_printf(1, 1 + cursor_index, ">");
}

uint8_t last_details_render = 254;
static inline void render_item_hover_details(void)
{
    if (cursor_index != last_details_render)
    {
        draw_frame(0, SHOP_LINES + 2, 15, 4);
        fill_bkg_rect(1, SHOP_LINES + 3, 13, 2, 0);
        xy_printf(1, SHOP_LINES + 3, item_details[store_items[cursor_index]][0]);
        xy_printf(1, SHOP_LINES + 4, item_details[store_items[cursor_index]][1]);
        last_details_render = cursor_index;
    }
}

static inline void render_item(uint8_t line, char *name, uint8_t cost)
{
    xy_printf(2, 1 + line, name);
    xy_printf(12, 1 + line, fixed_itoa(cost));
}

static inline void draw_money(void)
{
    fill_bkg_rect(16, 1, 3, 1, 0);
    xy_printf(17, 1, fixed_itoa(default_state.stats[STAT_GOLD]));
}

static inline void draw_items(void)
{
    // item line (name, price)
    for (uint8_t i = 0; i < SHOP_LINES; i++)
    {
        if (store_items[i] == ITEM_NONE)
        {
            fill_bkg_rect(2, 1 + i, 12, 1, 0);
        }
        else
        {
            render_item(i, item_name(store_items[i]), item_price(store_items[i]));
        }
    }
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        set_focus(SHOP);
        cursor_index = 0;
        generate_store_items();
        // item frame
        draw_frame(0, 0, 15, SHOP_LINES + 2);
        // money frame
        draw_frame(15, 0, 5, 3);
    }
    if (focus_changed)
    {
        clear_bkg_frame();
        draw_money();
        draw_items();
        focus_changed = 0;
    }

    switch (focus)
    {
    case SHOP:
        render_cursor();
        render_item_hover_details();
        break;
    case PURCHASE_CONFIRM:
        menu_render(&confirm_purchase_menu);
        break;
    case LEAVE_CONFIRM:
        menu_render(&leave_confirm_menu);
        break;
    }
}

BANKREF(scene_shop_ref)
struct Scene scene_shop = {
    .process_input = process_input,
    .render = render,
};