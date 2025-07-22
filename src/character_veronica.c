#pragma bank 7
#include "character_veronica.h"
#include "character_simple.h"
#include "gen/png2asset/bg_veronica.h"
#include "gen/png2asset/sp_veronica.h"
#include "gen/metasprite_fix/bg_veronica.h"
#include "gen/metasprite_fix/sp_veronica.h"

#define SP_VERONICA_SHEET {                    \
    .tiles = sp_veronica_tiles,                \
    .tiles_len = sp_veronica_TILE_COUNT,       \
    .sheet_start = 0,                          \
    .sheet_frames = 3,                         \
    .sheet_frame_width_tiles = 4,              \
    .sheet_width_tiles = 4 * 3,                \
    .palette_start = OAMF_CGB_PAL0,            \
    .palettes = sp_veronica_palettes,          \
    .palettes_len = sp_veronica_PALETTE_COUNT, \
    .palette_map = sp_veronica_palette_map,    \
}
#define VERONICA_FRAMES(tile_x, tile_y) ANI_FRAMES(0, (4 * 3), 4, tile_x, tile_y)
#define SP_VERONICA_X 8
#define SP_VERONICA_Y 8
static const struct SpriteAnimationConst veronica_left_eye_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_VERONICA_X + 17,
    .screen_y = SP_VERONICA_Y + 29,
    .frame_tiles = VERONICA_FRAMES(0, 0),
};
static struct SpriteAnimation veronica_left_eye = {
    .con = &veronica_left_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst veronica_right_eye_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 2,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_VERONICA_X + 33,
    .screen_y = SP_VERONICA_Y + 30,
    .frame_tiles = VERONICA_FRAMES(0, 0),
};
static struct SpriteAnimation veronica_right_eye = {
    .con = &veronica_right_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst veronica_mouth_talking_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 1,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 4,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_TALK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_VERONICA_X + 24,
    .screen_y = SP_VERONICA_Y + 46,
    .frame_tiles = VERONICA_FRAMES(0, 1),
};
static struct SpriteAnimation veronica_mouth_talking = {
    .con = &veronica_mouth_talking_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst veronica_mouth_passive_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 1,
    .sheet_tile_y = 1,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 5,
    .style = ANIMATION_STYLE_NONE,
    .screen_x = SP_VERONICA_X + 24,
    .screen_y = SP_VERONICA_Y + 46,
    .frame_tiles = VERONICA_FRAMES(1, 1),
};
static struct SpriteAnimation veronica_mouth_passive = {
    .con = &veronica_mouth_passive_const,
    .state.frame = 0,
};

static const struct CharacterSimpleConst character_veronica_simple_const = {
    // bg
    .bg_palette_count = bg_veronica_PALETTE_COUNT,
    .bg_palettes = bg_veronica_palettes,
    .bg_tile_count = bg_veronica_TILE_COUNT,
    .bg_tiles = bg_veronica_tiles,
    .bg_palette_map = bg_veronica_palette_map,
    // sp
    .left_eye = &veronica_left_eye,
    .right_eye = &veronica_right_eye,
    .mouth_talking = &veronica_mouth_talking,
    .mouth_passive = &veronica_mouth_passive,
};

CHARACTER_SIMPLE_TEMPLATE(veronica)
