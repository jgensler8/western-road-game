#pragma bank 2
#include "scene_road.h"
#include "bg_road.h"
#include "sp_cacti.h"

uint8_t cactus_animation_frame;
static void process_input(void)
{
    if (joypad_a_pressed)
    {
        cactus_animation_frame++;
        if (cactus_animation_frame > 3)
        {
            cactus_animation_frame = 0;
        }
        play_sfx_blip();
        state_on_step();
    }
    state_maybe_handle_event();
}
void render_cactus_frame(uint8_t frame, uint8_t sprite_start, uint8_t tile_start)
{
    uint8_t x = 0;
    uint8_t y = 0;
    switch (frame)
    {
    case 0:
        set_sprite_tile(sprite_start, tile_start + 7);
        x = 36;
        y = 22;
        move_sprite(sprite_start, x + ADJUST_X, y + ADJUST_Y);
        hide_sprite(1);
        hide_sprite(2);
        hide_sprite(3);
        hide_sprite(4);
        hide_sprite(5);
        hide_sprite(6);
        hide_sprite(7);
        break;
    case 1:
        set_sprite_tile(sprite_start, tile_start + 11);
        set_sprite_tile(sprite_start + 1, tile_start + 15);
        x = 34;
        y = 28;
        move_sprite(sprite_start + 0, x + ADJUST_X, y + 0 + ADJUST_Y);
        move_sprite(sprite_start + 1, x + ADJUST_X, y + 8 + ADJUST_Y);
        hide_sprite(2);
        hide_sprite(3);
        hide_sprite(4);
        hide_sprite(5);
        hide_sprite(6);
        hide_sprite(7);
        break;
    case 2:
        set_sprite_tile(sprite_start, tile_start + 6);
        set_sprite_tile(sprite_start + 1, tile_start + 10);
        set_sprite_tile(sprite_start + 2, tile_start + 14);
        x = 26;
        y = 44;
        move_sprite(sprite_start + 0, x + ADJUST_X, y + 0 + ADJUST_Y);
        move_sprite(sprite_start + 1, x + ADJUST_X, y + 8 + ADJUST_Y);
        move_sprite(sprite_start + 2, x + ADJUST_X, y + 16 + ADJUST_Y);
        hide_sprite(3);
        hide_sprite(4);
        hide_sprite(5);
        hide_sprite(6);
        hide_sprite(7);
        break;
    case 3:
        set_sprite_tile(sprite_start, tile_start + 0);
        set_sprite_tile(sprite_start + 1, tile_start + 1);
        set_sprite_tile(sprite_start + 2, tile_start + 4);
        set_sprite_tile(sprite_start + 3, tile_start + 5);
        set_sprite_tile(sprite_start + 4, tile_start + 8);
        set_sprite_tile(sprite_start + 5, tile_start + 9);
        set_sprite_tile(sprite_start + 6, tile_start + 12);
        set_sprite_tile(sprite_start + 7, tile_start + 13);
        x = 14;
        y = 60;
        move_sprite(sprite_start + 0, x + 0 + ADJUST_X, y + 0 + ADJUST_Y);
        move_sprite(sprite_start + 1, x + 8 + ADJUST_X, y + 0 + ADJUST_Y);
        move_sprite(sprite_start + 2, x + 0 + ADJUST_X, y + 8 + ADJUST_Y);
        move_sprite(sprite_start + 3, x + 8 + ADJUST_X, y + 8 + ADJUST_Y);
        move_sprite(sprite_start + 4, x + 0 + ADJUST_X, y + 16 + ADJUST_Y);
        move_sprite(sprite_start + 5, x + 8 + ADJUST_X, y + 16 + ADJUST_Y);
        move_sprite(sprite_start + 6, x + 0 + ADJUST_X, y + 24 + ADJUST_Y);
        move_sprite(sprite_start + 7, x + 8 + ADJUST_X, y + 24 + ADJUST_Y);
        break;
    }
}
static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        // palettes
        palette_util_init_bkg(PALETTE_UTIL_BG(bg_road));
        palette_util_init_sp(PALETTE_UTIL_SP(sp_cacti));

        // sprites
        set_bkg_data(SCENE_BG_TILE_DATA_START, 64, bg_road_tiles);
        struct PaletteArgs pargs = {

            .metasprites = ANIMATE_DEFAULT_METASPRITE(bg_road),
            .palette_start = 1,
        };
        set_bkg_offset(4, 4, 8, 8, SCENE_BG_TILE_DATA_START, &pargs);
        text_draw_frame("A TO STEP", EMPTY);
        // TODO: technically only need to hold two animation in sprite memroy at a time
        set_sprite_data(0, 16, sp_cacti_tiles);
        cactus_animation_frame = 0;
    }
    render_cactus_frame(cactus_animation_frame, 0, 0);
}
BANKREF(scene_road_ref)
struct Scene scene_road = {
    .process_input = process_input,
    .render = render,
};