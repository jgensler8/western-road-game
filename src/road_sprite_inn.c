#pragma bank 2
#include "road_sprite.h"
#include "gen/png2asset/sp_inn.h"
#include "gen/metasprite_fix/sp_inn.h"

#define SP_INN_SHEET {                           \
    .tiles = sp_inn_tiles,                       \
    .tiles_len = sp_inn_TILE_COUNT,              \
    .sheet_start = SP_EVENT_SLOT,                \
    .sheet_frames = 1,                           \
    .sheet_frame_width_tiles = sp_inn_WIDTH / 8, \
    .sheet_width_tiles = sp_inn_WIDTH / 8,       \
    .palettes = sp_inn_palettes,                 \
    .palettes_len = sp_inn_PALETTE_COUNT,        \
    .palette_start = 2,                          \
    .palette_map = sp_inn_palette_map,           \
}
 const struct SpriteAnimationConst rs_inn_frame_0 = {
    .sheet = SP_INN_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 1,
    .tile_height = 1,
    .screen_x = 36,
    .screen_y = 22,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 0),
};
 const struct SpriteAnimationConst rs_inn_frame_1 = {
    .sheet = SP_INN_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 34,
    .screen_y = 28,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 2, 0),
};
 const struct SpriteAnimationConst rs_inn_frame_2 = {
    .sheet = SP_INN_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 2,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 26,
    .screen_y = 34,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 2, 2),
};
 const struct SpriteAnimationConst rs_inn_frame_3 = {
    .sheet = SP_INN_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 2,
    .tile_width = 2,
    .tile_height = 2,
    .screen_x = 18,
    .screen_y = 50,
    .sp_index_start = ROAD_EVENT_SP_START,
    .frame_tiles = ANI_FRAMES(SHEET_SLOT(2), 4, 4, 0, 2),
};