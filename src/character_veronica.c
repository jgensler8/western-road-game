#pragma bank 4
#include "character_veronica.h"
#include "character_simple.h"
#include "gen/png2asset/bg_veronica.h"
#include "gen/png2asset/sp_veronica.h"

static const uint8_t sp_veronica_palette_map[sp_veronica_TILE_COUNT] = {0};
#define SP_VERONICA_SHEET {                    \
    .tiles = sp_veronica_tiles,                \
    .tiles_len = 4 * 4 * 3,                    \
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
static const struct SpriteAnimationConst animation_left_eye_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_VERONICA_X + 18,
    .screen_y = SP_VERONICA_Y + 25,
    .frame_tiles = VERONICA_FRAMES(0, 0),
};
static struct SpriteAnimation animation_left_eye = {
    .con = &animation_left_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_right_eye_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 2,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_VERONICA_X + 40,
    .screen_y = SP_VERONICA_Y + 25,
    .frame_tiles = VERONICA_FRAMES(2, 0),
};
static struct SpriteAnimation animation_right_eye = {
    .con = &animation_right_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_talking_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 4,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_TALK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_VERONICA_X + 30,
    .screen_y = SP_VERONICA_Y + 48,
    .frame_tiles = VERONICA_FRAMES(0, 1),
};
static struct SpriteAnimation animation_mouth_talking = {
    .con = &animation_mouth_talking_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_passive_const = {
    .sheet = SP_VERONICA_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 6,
    .style = ANIMATION_STYLE_NONE,
    .screen_x = SP_VERONICA_X + 30,
    .screen_y = SP_VERONICA_Y + 48,
    .frame_tiles = VERONICA_FRAMES(2, 1),
};
static struct SpriteAnimation animation_mouth_passive = {
    .con = &animation_mouth_passive_const,
    .state.frame = 0,
};

static const uint8_t bg_veronica_palette_map[bg_veronica_TILE_COUNT] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
};
static const struct CharacterSimpleConst character_veronica_simple_const = {
    // bg
    .bg_palette_count = bg_veronica_PALETTE_COUNT,
    .bg_palettes = bg_veronica_palettes,
    .bg_tile_count = bg_veronica_TILE_COUNT,
    .bg_tiles = bg_veronica_tiles,
    .bg_palette_map = bg_veronica_palette_map,
    // sp
    .left_eye = &animation_left_eye,
    .right_eye = &animation_right_eye,
    .mouth_talking = &animation_mouth_talking,
    .mouth_passive = &animation_mouth_passive,
};
static struct CharacterSimple character_veronica_simple = {
    .con = &character_veronica_simple_const,
    .state = {0},
};
static struct MemoryAllocation init(struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y)
{
    // return start;
    struct MemoryAllocation ret = cs_init(&character_veronica_simple, start, tile_x, tile_y);
    return ret;
}
static void set_expression(enum CharacterExpression expression)
{
    cs_set_expression(&character_veronica_simple, expression);
}
static void start_talking(void)
{
    cs_start_talking(&character_veronica_simple);
}
static void stop_talking(void)
{
    cs_stop_talking(&character_veronica_simple);
}
static void render(void)
{
    cs_render(&character_veronica_simple);
}
BANKREF(character_veronica_ref)
struct Character character_veronica = {
    .init = init,
    .set_expression = set_expression,
    .start_talking = start_talking,
    .stop_talking = stop_talking,
    .render = render,
};