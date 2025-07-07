#include "scene_shop.h"
#include "scene_road.h"
#include <stdio.h>

static uint8_t cursor_index = 0;
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
            cursor_index--;
        }
    }
    else if (joypad_down_pressed)
    {
        cursor_index++;
    }
    if (cursor_index > 2)
    {
        cursor_index = 2;
    }
    if (joypad_a_pressed)
    {
        set_focus(PURCHASE_CONFIRM);
    }
}
static void process_input_purchase_confirm(void)
{
    if (menu_process_input(&confirm_purchase_menu) || joypad_b_pressed)
    {
        switch (confirm_purchase_menu.selection)
        {
        case 0:
            // do the purchase
            break;
        case 1:
            break;
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
    if(joypad_b_pressed)
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

#define SHOP_LINES 12
static void render_cursor(void)
{
    // clear cursor column
    for (uint8_t i = 0; i < SHOP_LINES; i++)
    {
        xy_printf(1, 1 + i, " ");
    }
    // render cursor
    xy_printf(1, 1 + cursor_index, ">");
}

static void render_item_hover_details(void)
{
    draw_frame(0, SHOP_LINES + 2, 15, 4);
}

char static_fixed[4];
static char *fixed_itoa(uint8_t value)
{
    sprintf(static_fixed, "%u", value);
    return static_fixed;
}

static void render_item(uint8_t line, char *name, uint8_t cost)
{
    xy_printf(2, 1 + line, name);
    xy_printf(12, 1 + line, fixed_itoa(cost));
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        set_focus(SHOP);
        cursor_index = 0;
    }
    if (focus_changed)
    {
        clear_bkg_frame();
        focus_changed = 0;
    }
    // render money in the top right
    draw_frame(15, 0, 5, 3);
    xy_printf(17, 1, "12");
    // item cabinet
    draw_frame(0, 0, 15, SHOP_LINES + 2);
    render_item(0, "OVERALLS", 0);
    render_item(1, "BAG", 5);
    render_item(2, "CRYSTAL", 10);

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