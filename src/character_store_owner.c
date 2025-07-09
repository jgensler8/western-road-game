#pragma bank 3
#include "character_store_owner.h"
#include "gen/png2asset/bg_store_owner.h"
#include "gen/png2asset/sp_store_owner.h"

static const uint8_t sp_store_owner_palette_map[sp_store_owner_TILE_COUNT] = {
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
    0,
    0,
    1,
    1,
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
};
#define SP_STORE_OWNER_SHEET {                    \
    .tiles = sp_store_owner_tiles,                \
    .tiles_len = 4 * 4 * 3,                       \
    .sheet_start = 0,                             \
    .sheet_frames = 3,                            \
    .sheet_frame_width_tiles = 4,                 \
    .sheet_width_tiles = 4 * 3,                   \
    .palette_start = OAMF_CGB_PAL0,               \
    .palettes = sp_store_owner_palettes,          \
    .palettes_len = sp_store_owner_PALETTE_COUNT, \
    .palette_map = sp_store_owner_palette_map,    \
}
#define STORE_OWNER_FRAMES(tile_x, tile_y) ANI_FRAMES(0, (4 * 3), 4, tile_x, tile_y)
#define SP_STORE_OWNER_X 8
#define SP_STORE_OWNER_Y 8
static const struct SpriteAnimationConst animation_left_eye_const = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_STORE_OWNER_X + 18,
    .screen_y = SP_STORE_OWNER_Y + 25,
    .frame_tiles = STORE_OWNER_FRAMES(0, 0),
};
static struct SpriteAnimation animation_left_eye = {
    .con = &animation_left_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_right_eye_const = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 2,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_STORE_OWNER_X + 40,
    .screen_y = SP_STORE_OWNER_Y + 25,
    .frame_tiles = STORE_OWNER_FRAMES(2, 0),
};
static struct SpriteAnimation animation_right_eye = {
    .con = &animation_right_eye_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_talking_const = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 4,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_TALK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .screen_x = SP_STORE_OWNER_X + 30,
    .screen_y = SP_STORE_OWNER_Y + 48,
    .frame_tiles = STORE_OWNER_FRAMES(0, 1),
};
static struct SpriteAnimation animation_mouth_talking = {
    .con = &animation_mouth_talking_const,
    .state.frame = 0,
};
static const struct SpriteAnimationConst animation_mouth_passive_const = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 6,
    .style = ANIMATION_STYLE_NONE,
    .screen_x = SP_STORE_OWNER_X + 30,
    .screen_y = SP_STORE_OWNER_Y + 48,
    .frame_tiles = STORE_OWNER_FRAMES(2, 1),
};
static struct SpriteAnimation animation_mouth_passive = {
    .con = &animation_mouth_passive_const,
    .state.frame = 0,
};

static uint8_t talking;
static uint8_t talking_changed;
static struct MemoryAllocation init(struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y)
{
    // palettes
    uint8_t pal_start = palette_util_init_bkg(PALETTE_UTIL_BG(bg_store_owner));
    // owner bg
    set_bkg_data(start.bg_start, bg_store_owner_TILE_COUNT, bg_store_owner_tiles);
    struct PaletteArgs pargs = {
        .metasprites = bg_store_owner_metasprites[0],
        .palette_start = pal_start,
    };
    set_bkg_offset(tile_x, tile_y, 8, 8, start.bg_start, &pargs);
    // owner sp
    animation_init_sprite_sheet(&animation_left_eye.con->sheet);
    animation_init_sprite_animation(&animation_left_eye);
    animation_init_sprite_animation(&animation_right_eye);
    animation_init_sprite_animation(&animation_mouth_passive);
    animation_init_sprite_animation(&animation_mouth_talking);
    talking = 0;
    // TODO: either build custom funcs or hardcode
    struct MemoryAllocation end = {
        .bg_end = start.bg_start + 6,
    };
    return end;
}
static void set_expression(enum CharacterExpression expression)
{
}
static void start_talking(void)
{
    talking = 1;
    talking_changed = 1;
}
static void stop_talking(void)
{
    talking = 0;
    talking_changed = 1;
}
static void render(void)
{
    maybe_animate(&animation_left_eye);
    maybe_animate(&animation_right_eye);
    if (talking)
    {
        maybe_animate(&animation_mouth_talking);
        if (talking_changed)
        {
            animation_show(&animation_mouth_talking);
            animation_hide(&animation_mouth_passive);
        }
    }
    else
    {
        maybe_animate(&animation_mouth_passive);
        if (talking_changed)
        {
            animation_show(&animation_mouth_passive);
            animation_hide(&animation_mouth_talking);
        }
    }
    talking_changed = 0;
}

BANKREF(character_store_owner_ref)
struct Character character_store_owner = {
    .init = init,
    .set_expression = set_expression,
    .start_talking = start_talking,
    .stop_talking = stop_talking,
    .render = render,
};