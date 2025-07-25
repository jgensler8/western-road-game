#pragma bank 8
#include "character_bandit_a.h"
#include "gen/png2asset/bg_bandit_a.h"
#include "gen/png2asset/sp_bandit_a.h"
#include "gen/metasprite_fix/bg_bandit_a.h"
#include "gen/metasprite_fix/sp_bandit_a.h"
#include "character_simple.h"

#define SP_BANDIT_A_SHEET ANIMATE_SPRITE_SHEET_COMMON(sp_bandit_a)
#define BANDIT_A_FRAMES(tile_x, tile_y) ANI_FRAMES(0, (4 * 3), 4, tile_x, tile_y)
#define SP_BANDIT_A_X 8
#define SP_BANDIT_A_Y 8
static const struct SpriteAnimationConst animation_left_eye_const = {
    .sheet = SP_BANDIT_A_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 0,
    .tile_height = 0,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_BANDIT_A_X + 19,
    .screen_y = SP_BANDIT_A_Y + 22,
    .frame_tiles = BANDIT_A_FRAMES(0, 0),
};
static struct SpriteAnimation left_eye = {
    .con = &animation_left_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_right_eye_const = {
    .sheet = SP_BANDIT_A_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_BANDIT_A_X + 35,
    .screen_y = SP_BANDIT_A_Y + 17,
    .frame_tiles = BANDIT_A_FRAMES(0, 0),
};
static struct SpriteAnimation right_eye = {
    .con = &animation_right_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_passive_const = {
    .sheet = SP_BANDIT_A_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 2,
    .tile_width = 1,
    .tile_height = 1,
    .sp_index_start = 1,
    .style = ANIMATION_STYLE_NONE,
    .screen_x = SP_BANDIT_A_X + 26,
    .screen_y = SP_BANDIT_A_Y + 38,
    .frame_tiles = BANDIT_A_FRAMES(2, 2),
};
static struct SpriteAnimation mouth_passive = {
    .con = &animation_mouth_passive_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_talking_const = {
    .sheet = SP_BANDIT_A_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 2,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 9,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_TALK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_BANDIT_A_X + 26,
    .screen_y = SP_BANDIT_A_Y + 38,
    .frame_tiles = BANDIT_A_FRAMES(0, 2),
};
static struct SpriteAnimation mouth_talking = {
    .con = &animation_mouth_talking_const,
    .state.frame = 0,
};

static const struct CharacterSimpleConst character_bandit_a_simple_const = {
    // bg
    .bg_palette_count = bg_bandit_a_PALETTE_COUNT,
    .bg_palettes = bg_bandit_a_palettes,
    .bg_tile_count = bg_bandit_a_TILE_COUNT,
    .bg_tiles = bg_bandit_a_tiles,
    .bg_palette_map = bg_bandit_a_palette_map,
    // sp
    .left_eye = &left_eye,
    .right_eye = &right_eye,
    .mouth_passive = &mouth_passive,
    .mouth_talking = &mouth_talking,
};

CHARACTER_SIMPLE_TEMPLATE(bandit_a)