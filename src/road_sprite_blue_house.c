#pragma bank 2
#include "road_sprite.h"
#include "gen/png2asset/sp_road_blue_house.h"
#include "gen/metasprite_fix/sp_road_blue_house.h"

#define SP_ROAD_BLUE_HOUSE_SHEET {                           \
    .tiles = sp_road_blue_house_tiles,                       \
    .tiles_len = sp_road_blue_house_TILE_COUNT,              \
    .sheet_start = SP_EVENT_SLOT,                            \
    .sheet_frames = 1,                                       \
    .sheet_frame_width_tiles = sp_road_blue_house_WIDTH / 8, \
    .sheet_width_tiles = sp_road_blue_house_WIDTH / 8,       \
    .palettes = sp_road_blue_house_palettes,                 \
    .palettes_len = sp_road_blue_house_PALETTE_COUNT,        \
    .palette_start = 2,                                      \
}

const struct SpriteAnimationConst rs_road_blue_house_frame_0 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 60,
    .screen_y = 5,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 0),
};
const struct SpriteAnimationConst rs_road_blue_house_frame_1 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 60,
    .screen_y = 5,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 0),
};
const struct SpriteAnimationConst rs_road_blue_house_frame_2 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 60,
    .screen_y = 5,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 0),
};
const struct SpriteAnimationConst rs_road_blue_house_frame_3 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 60,
    .screen_y = 5,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 0),
};