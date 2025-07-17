#pragma bank 2
#include "road_sprite.h"
#include "gen/png2asset/sp_cacti.h"
#include "gen/metasprite_fix/sp_cacti.h"

#define SP_CACTI_SHEET {                           \
    .tiles = sp_cacti_tiles,                       \
    .tiles_len = sp_cacti_TILE_COUNT,              \
    .sheet_start = SHEET_SLOT(0),                  \
    .sheet_frames = 1,                             \
    .sheet_frame_width_tiles = sp_cacti_WIDTH / 8, \
    .sheet_width_tiles = sp_cacti_WIDTH / 8,       \
    .palettes = sp_cacti_palettes,                 \
    .palettes_len = sp_cacti_PALETTE_COUNT,        \
    .palette_start = 0,                            \
    .palette_map = sp_cacti_palette_map,           \
}

static const struct SpriteAnimationConst rs_cacti_frame_0 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 3,
    .sheet_tile_y = 1,
    .tile_width = 1,
    .tile_height = 1,
    .screen_x = 36,
    .screen_y = 22,
    .sp_index_start = 0,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(0), 4, 4, 3, 1),
};
static const struct SpriteAnimationConst rs_cacti_frame_1 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 3,
    .sheet_tile_y = 2,
    .tile_width = 1,
    .tile_height = 2,
    .screen_x = 34,
    .screen_y = 28,
    .sp_index_start = 0,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(0), 4, 4, 3, 2),
};
static const struct SpriteAnimationConst rs_cacti_frame_2 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 1,
    .tile_width = 1,
    .tile_height = 3,
    .screen_x = 22,
    .screen_y = 50,
    .sp_index_start = 0,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(0), 4, 4, 2, 1),
};
static const struct SpriteAnimationConst rs_cacti_frame_3 = {
    .sheet = SP_CACTI_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 4,
    .screen_x = 14,
    .screen_y = 60,
    .sp_index_start = 0,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(0), 4, 4, 0, 0),
};
struct RoadSprite rs_cacti = {
    .frames = {
        {.con = &rs_cacti_frame_0},
        {.con = &rs_cacti_frame_1},
        {.con = &rs_cacti_frame_2},
        {.con = &rs_cacti_frame_3},
    },
    .sp_start = ROAD_EVENT_LEFT_SP_START,
};