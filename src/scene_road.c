#pragma bank 2
#include "scene_road.h"
#include "gen/png2asset/bg_road.h"
#include "gen/png2asset/sp_cacti.h"

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

#define SP_CACTI_SHEET {                           \
    .tiles = sp_cacti_tiles,                       \
    .tiles_len = sp_cacti_TILE_COUNT,              \
    .sheet_start = 0,                              \
    .sheet_frames = 1,                             \
    .sheet_frame_width_tiles = sp_cacti_WIDTH / 8, \
    .sheet_width_tiles = sp_cacti_WIDTH / 8,       \
    .palette_start = 0,                            \
    .palettes = sp_cacti_palettes,                 \
    .palettes_len = sp_cacti_PALETTE_COUNT,        \
}
struct SpriteAnimation sp_cacti_frame_0 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 3,
    .sheet_tile_y = 1,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 0,
    .screen_x = 36,
    .screen_y = 22,
    .state.frame = 0,
};
struct SpriteAnimation sp_cacti_frame_1 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 3,
    .sheet_tile_y = 2,
    .tile_width = 1,
    .tile_height = 2,
    .sp_index_start = 1,
    .screen_x = 34,
    .screen_y = 28,
    .state.frame = 0,
};
struct SpriteAnimation sp_cacti_frame_2 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 1,
    .tile_width = 1,
    .tile_height = 3,
    .sp_index_start = 3,
    .screen_x = 26,
    .screen_y = 44,
    .state.frame = 0,
};
struct SpriteAnimation sp_cacti_frame_3 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 4,
    .sp_index_start = 6,
    .screen_x = 14,
    .screen_y = 60,
    .state.frame = 0,
};

void render_cactus_frame(uint8_t frame)
{
    // assume contiguous sprites
    animation_hide_range(sp_cacti_frame_0.sp_index_start, sp_cacti_frame_3.sp_index_start + 8);
    switch (frame)
    {
    case 0:
        animation_move_sprite(&sp_cacti_frame_0);
        break;
    case 1:
        animation_move_sprite(&sp_cacti_frame_1);
        break;
    case 2:
        animation_move_sprite(&sp_cacti_frame_2);
        break;
    case 3:
        animation_move_sprite(&sp_cacti_frame_3);
        break;
    }
}
static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        // palettes
        palette_util_init_bkg(PALETTE_UTIL_BG(bg_road));

        // sprites
        set_bkg_data(SCENE_BG_TILE_DATA_START, 64, bg_road_tiles);
        struct PaletteArgs pargs = {
            .metasprites = ANIMATE_DEFAULT_METASPRITE(bg_road),
            .palette_start = 1,
        };
        set_bkg_offset(4, 4, 8, 8, SCENE_BG_TILE_DATA_START, &pargs);
        text_draw_frame("A TO STEP", EMPTY);

        animation_init_sprite_sheet(&sp_cacti_frame_0.sheet);
        animation_init_sprite_animation(&sp_cacti_frame_0, ANIMATE_DEFAULT_METASPRITE(sp_cacti));
        animation_init_sprite_animation(&sp_cacti_frame_1, ANIMATE_DEFAULT_METASPRITE(sp_cacti));
        animation_init_sprite_animation(&sp_cacti_frame_2, ANIMATE_DEFAULT_METASPRITE(sp_cacti));
        animation_init_sprite_animation(&sp_cacti_frame_3, ANIMATE_DEFAULT_METASPRITE(sp_cacti));
        cactus_animation_frame = 0;
    }
    render_cactus_frame(cactus_animation_frame);
}
BANKREF(scene_road_ref)
struct Scene scene_road = {
    .process_input = process_input,
    .render = render,
};