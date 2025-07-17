#pragma bank 2
#include "road_sprite.h"
#include "gen/png2asset/sp_rock.h"
#include "gen/metasprite_fix/sp_rock.h"

#define SP_ROCK_SHEET {                           \
    .tiles = sp_rock_tiles,                       \
    .tiles_len = sp_rock_TILE_COUNT,              \
    .sheet_start = SHEET_SLOT(1),                 \
    .sheet_frames = 1,                            \
    .sheet_frame_width_tiles = sp_rock_WIDTH / 8, \
    .sheet_width_tiles = sp_rock_WIDTH / 8,       \
    .palettes = sp_rock_palettes,                 \
    .palettes_len = sp_rock_PALETTE_COUNT,        \
    .palette_start = 1,                           \
    .palette_map = sp_rock_palette_map,           \
}

const struct SpriteAnimationConst rs_rock_frame_0 = {
    .sheet = SP_ROCK_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 1,
    .tile_height = 1,
    .screen_x = 88,
    .screen_y = 24,
    .sp_index_start = 8,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(1), 4, 4, 0, 0),
};
const struct SpriteAnimationConst rs_rock_frame_1 = {
    .sheet = SP_ROCK_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 94,
    .screen_y = 28,
    .sp_index_start = 8,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(1), 4, 4, 2, 0),
};
const struct SpriteAnimationConst rs_rock_frame_2 = {
    .sheet = SP_ROCK_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 2,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 94,
    .screen_y = 40,
    .sp_index_start = 8,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(1), 4, 4, 2, 2),
};
const struct SpriteAnimationConst rs_rock_frame_3 = {
    .sheet = SP_ROCK_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 2,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 104,
    .screen_y = 60,
    .sp_index_start = 8,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(1), 4, 4, 0, 2),
};

struct RoadSprite rs_rock = {
    .frames = {
        {.con = &rs_rock_frame_0},
        {.con = &rs_rock_frame_1},
        {.con = &rs_rock_frame_2},
        {.con = &rs_rock_frame_3},
    },
    .sp_start = ROAD_EVENT_RIGHT_SP_START,
};
