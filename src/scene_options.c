#pragma bank 0
#include "scene_options.h"

static void process_input(void)
{
    if (joypad_b_pressed || joypad_start_pressed)
    {
        scene_options_takeover = 0;
        HIDE_WIN;
        SHOW_SPRITES;
        return;
    }
}

static void render(struct SceneRenderOptions *options)
{
    if (scene_options_swapped)
    {
        SHOW_WIN;
        HIDE_SPRITES;
        draw_frame_win(0, 0, 20, 18);
        xy_printf_win(6, 0, "OPTIONS");
        scene_options_swapped = 0;
    }
}

uint16_t scene_options_swapped;
uint16_t scene_options_takeover;

BANKREF(scene_options_ref)
struct Scene scene_options = {
    .process_input = process_input,
    .render = render,
};