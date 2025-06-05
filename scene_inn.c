#pragma bank 3
#include "scene_inn.h"
#include "bg_store_owner.h"
#include "sp_store_owner.h"
#include "animate.h"

uint8_t is_talking = 0;
static void process_input(void)
{
    if (joypad_a_pressed)
    {
        is_talking = !is_talking;
    }
}

#define SP_STORE_OWNER_SHEET {           \
    .tiles = sp_store_owner_tiles,       \
    .tiles_len = 4 * 4 * 3,              \
    .sheet_start = 0,                    \
    .sheet_frames = 3,                   \
    .sheet_frame_width_tiles = 4,        \
    .sheet_width_tiles = 4 * 3,          \
    .palette_start = OAMF_CGB_PAL0,      \
    .palettes = sp_store_owner_palettes, \
    .palettes_len = 2,                   \
}
#define SP_STORE_OWNER_TILE_X 1
#define SP_STORE_OWNER_TILE_Y 1
#define SP_STORE_OWNER_SCREEN_X (SP_STORE_OWNER_TILE_X * 8)
#define SP_STORE_OWNER_SCREEN_Y (SP_STORE_OWNER_TILE_Y * 8)
#define SP_STORE_OWNER_FRAME_TIMINGS {128, 4, 4}
struct SpriteAnimation animation_left_eye = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 0,
    .screen_x = SP_STORE_OWNER_SCREEN_X + 18,
    .screen_y = SP_STORE_OWNER_SCREEN_Y + 25,
    .timings_len = 3,
    .timings = SP_STORE_OWNER_FRAME_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .state.frame = 0,
};
struct SpriteAnimation animation_right_eye = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 2,
    .screen_x = SP_STORE_OWNER_SCREEN_X + 40,
    .screen_y = SP_STORE_OWNER_SCREEN_Y + 25,
    .timings_len = 3,
    .timings = SP_STORE_OWNER_FRAME_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .state.frame = 0,
};
#define SYLABLE_TALKING_
struct SpriteAnimation animation_mouth_talking = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 4,
    .screen_x = SP_STORE_OWNER_SCREEN_X + 30,
    .screen_y = SP_STORE_OWNER_SCREEN_Y + 48,
    .timings_len = 3,
    .timings = {10, 2, 10},
    .style = ANIMATION_STYLE_ONCE,
    .state.frame = 0,
};
struct SpriteAnimation animation_mouth_passive = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 6,
    .screen_x = SP_STORE_OWNER_SCREEN_X + 30,
    .screen_y = SP_STORE_OWNER_SCREEN_Y + 48,
    .style = ANIMATION_STYLE_NONE,
    .state.frame = 2,
};

static void render(uint8_t swapped)
{
    if (swapped)
    {
        // owner bg
        uint8_t owner_xt = SP_STORE_OWNER_TILE_X, owner_yt = SP_STORE_OWNER_TILE_Y;
        set_bkg_data(SCENE_BG_TILE_DATA_START, 64, bg_store_owner_tiles);
        set_bkg_palette(BKGF_CGB_PAL1, 7, bg_store_owner_palettes);
        struct PaletteArgs pargs = {
            .metasprites = bg_store_owner_metasprites[0],
            .palette_start = BKGF_CGB_PAL1,
        };
        set_bkg_offset(owner_xt, owner_yt, 8, 8, SCENE_BG_TILE_DATA_START, &pargs);
        // owner sp
        animation_init_sprite_sheet(&animation_left_eye.sheet);
        animation_init_sprite_animation(&animation_left_eye);
        animation_init_sprite_animation(&animation_right_eye);
        animation_init_sprite_animation(&animation_mouth_passive);
        animation_init_sprite_animation(&animation_mouth_talking);
        SHOW_SPRITES;
        // frame
        draw_frame(0, 0, 10, 10);
        text_draw_frame("HELLO THERE", EMPTY);
    }
    else
    {
        maybe_animate(&animation_left_eye);
        maybe_animate(&animation_right_eye);
        if (is_talking)
        {
            maybe_animate(&animation_mouth_talking);
        }
        else
        {
            maybe_animate(&animation_mouth_passive);
        }
    }
}
BANKREF(scene_inn_ref)
struct Scene scene_inn = {
    .process_input = process_input,
    .render = render,
};