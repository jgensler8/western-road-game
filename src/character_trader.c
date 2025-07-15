#pragma bank 2
#include "character_trader.h"
#include "gen/png2asset/bg_trader.h"
#include "gen/png2asset/sp_trader.h"
#include "gen/metasprite_fix/bg_trader.h"
#include "gen/metasprite_fix/sp_trader.h"
#include "character_simple.h"

#define SP_TRADER_SHEET {                    \
    .tiles = sp_trader_tiles,                \
    .tiles_len = sp_trader_TILE_COUNT,       \
    .sheet_start = 0,                        \
    .sheet_frames = 3,                       \
    .sheet_frame_width_tiles = 4,            \
    .sheet_width_tiles = 4 * 3,              \
    .palette_start = OAMF_CGB_PAL0,          \
    .palettes = sp_trader_palettes,          \
    .palettes_len = sp_trader_PALETTE_COUNT, \
    .palette_map = sp_trader_palette_map,    \
}
#define TRADER_FRAMES(tile_x, tile_y) ANI_FRAMES(0, (4 * 3), 4, tile_x, tile_y)
#define SP_TRADER_X 8
#define SP_TRADER_Y 8
#define TRADER_GLASSES_TIMINGS {140,4,4}
#define TRADER_GLASSES_TIMINGS_2 {138,5,5}
static const struct SpriteAnimationConst animation_left_eye_const = {
    .sheet = SP_TRADER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = TRADER_GLASSES_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_TRADER_X + 13,
    .screen_y = SP_TRADER_Y + 27,
    .frame_tiles = TRADER_FRAMES(0, 0),
};
static struct SpriteAnimation animation_left_eye = {
    .con = &animation_left_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_right_eye_const = {
    .sheet = SP_TRADER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .sp_index_start = 4,
    .timings_len = 3,
    .timings = TRADER_GLASSES_TIMINGS_2,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_TRADER_X + 29,
    .screen_y = SP_TRADER_Y + 27,
    .frame_tiles = TRADER_FRAMES(2, 0),
};
static struct SpriteAnimation animation_right_eye = {
    .con = &animation_right_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_talking_const = {
    .sheet = SP_TRADER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 2,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 8,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_TALK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_TRADER_X + 24,
    .screen_y = SP_TRADER_Y + 48,
    .frame_tiles = TRADER_FRAMES(0, 2),
};
static struct SpriteAnimation animation_mouth_talking = {
    .con = &animation_mouth_talking_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_passive_const = {
    .sheet = SP_TRADER_SHEET,
    .sheet_tile_x = 1,
    .sheet_tile_y = 2,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 9,
    .style = ANIMATION_STYLE_NONE,
    .screen_x = SP_TRADER_X + 24,
    .screen_y = SP_TRADER_Y + 48,
    .frame_tiles = TRADER_FRAMES(1, 2),
};
static struct SpriteAnimation animation_mouth_passive = {
    .con = &animation_mouth_passive_const,
    .state.frame = 0,
};

static const struct CharacterSimpleConst character_trader_simple_const = {
    // bg
    .bg_palette_count = bg_trader_PALETTE_COUNT,
    .bg_palettes = bg_trader_palettes,
    .bg_tile_count = bg_trader_TILE_COUNT,
    .bg_tiles = bg_trader_tiles,
    .bg_palette_map = bg_trader_palette_map,
    // sp
    .left_eye = &animation_left_eye,
    .right_eye = &animation_right_eye,
    .mouth_talking = &animation_mouth_talking,
    .mouth_passive = &animation_mouth_passive,
};

CHARACTER_SIMPLE_TEMPLATE(trader)