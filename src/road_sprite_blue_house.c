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
    .palette_map = sp_road_blue_house_palette_map,           \
}

const struct SpriteAnimationConst rs_road_blue_house_frame_0 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = RS_LEFT_X_0,
    .screen_y = RS_LEFT_Y_0,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 0),
};
const struct SpriteAnimationConst rs_road_blue_house_frame_1 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = RS_LEFT_X_1,
    .screen_y = RS_LEFT_Y_1,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 2, 0),
};
const struct SpriteAnimationConst rs_road_blue_house_frame_2 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 2,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = RS_LEFT_X_2,
    .screen_y = RS_LEFT_Y_2,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 2, 2),
};
const struct SpriteAnimationConst rs_road_blue_house_frame_3 = {
    .sheet = SP_ROAD_BLUE_HOUSE_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 2,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = RS_LEFT_X_3,
    .screen_y = RS_LEFT_Y_3,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 2),
};