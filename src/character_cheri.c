#pragma bank 4
#include "character_cheri.h"
#include "gen/png2asset/bg_cheri.h"
#include "gen/png2asset/sp_cheri.h"
#include "gen/metasprite_fix/bg_cheri.h"
#include "gen/metasprite_fix/sp_cheri.h"
#include "character_simple.h"

#define SP_CHERI_SHEET ANIMATE_SPRITE_SHEET_COMMON(sp_cheri)
#define CHERI_FRAMES(tile_x, tile_y) ANI_FRAMES(0, (4 * 3), 4, tile_x, tile_y)
#define SP_CHERI_X 8
#define SP_CHERI_Y 8
static const struct SpriteAnimationConst animation_left_eye_const = {
    .sheet = SP_CHERI_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_CHERI_X + 19,
    .screen_y = SP_CHERI_Y + 22,
    .frame_tiles = CHERI_FRAMES(0, 0),
};
static struct SpriteAnimation left_eye = {
    .con = &animation_left_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_right_eye_const = {
    .sheet = SP_CHERI_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 2,
    .sp_index_start = 4,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_CHERI_X + 40,
    .screen_y = SP_CHERI_Y + 22,
    .frame_tiles = CHERI_FRAMES(0, 0),
};
static struct SpriteAnimation right_eye = {
    .con = &animation_right_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_passive_const = {
    .sheet = SP_CHERI_SHEET,
    .sheet_tile_x = 1,
    .sheet_tile_y = 2,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 8,
    .style = ANIMATION_STYLE_NONE,
    .screen_x = SP_CHERI_X + 33,
    .screen_y = SP_CHERI_Y + 45,
    .frame_tiles = CHERI_FRAMES(1, 2),
};
static struct SpriteAnimation mouth_passive = {
    .con = &animation_mouth_passive_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_talking_const = {
    .sheet = SP_CHERI_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 2,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 9,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_TALK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_CHERI_X + 33,
    .screen_y = SP_CHERI_Y + 45,
    .frame_tiles = CHERI_FRAMES(0, 2),
};
static struct SpriteAnimation mouth_talking = {
    .con = &animation_mouth_talking_const,
    .state.frame = 0,
};

static const struct CharacterSimpleConst character_cheri_simple_const = {
    // bg
    .bg_palette_count = bg_cheri_PALETTE_COUNT,
    .bg_palettes = bg_cheri_palettes,
    .bg_tile_count = bg_cheri_TILE_COUNT,
    .bg_tiles = bg_cheri_tiles,
    .bg_palette_map = bg_cheri_palette_map,
    // sp
    .left_eye = &left_eye,
    .right_eye = &right_eye,
    .mouth_passive = &mouth_passive,
    .mouth_talking = &mouth_talking,
};

CHARACTER_SIMPLE_TEMPLATE(cheri)
