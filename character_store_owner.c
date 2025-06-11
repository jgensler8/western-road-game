#pragma bank 3
#include "character_store_owner.h"
#include "bg_store_owner.h"
#include "sp_store_owner.h"

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
}

static struct SpriteAnimation animation_left_eye = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 0,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .state.frame = 0,
};
static struct SpriteAnimation animation_right_eye = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 2,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_BLINK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .state.frame = 0,
};
static struct SpriteAnimation animation_mouth_talking = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 4,
    .timings_len = 3,
    .timings = ANIMATE_DEFAULT_TALK_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .state.frame = 0,
};
static struct SpriteAnimation animation_mouth_passive = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 6,
    .style = ANIMATION_STYLE_NONE,
    .state.frame = 0,
};

static uint8_t talking;
static uint8_t talking_changed;
static struct MemoryAllocation init(struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y)
{
    // owner bg
    set_bkg_data(start.bg_start, 64, bg_store_owner_tiles);
    set_bkg_palette(start.bg_pal_start, 7, bg_store_owner_palettes);
    struct PaletteArgs pargs = {
        .metasprites = bg_store_owner_metasprites[0],
        .palette_start = start.bg_pal_start,
    };
    set_bkg_offset(tile_x, tile_y, 8, 8, start.bg_start, &pargs);
    // owner sp
    animation_init_sprite_sheet(&animation_left_eye.sheet);
    animation_init_sprite_animation(&animation_left_eye, sp_store_owner_metasprites[0]);
    ANIMATE_TILE_OFFSET(animation_left_eye, 18, 25);
    animation_init_sprite_animation(&animation_right_eye, sp_store_owner_metasprites[0]);
    ANIMATE_TILE_OFFSET(animation_right_eye, 40, 25);
    animation_init_sprite_animation(&animation_mouth_passive, sp_store_owner_metasprites[0]);
    ANIMATE_TILE_OFFSET(animation_mouth_passive, 30, 48);
    animation_init_sprite_animation(&animation_mouth_talking, sp_store_owner_metasprites[0]);
    ANIMATE_TILE_OFFSET(animation_mouth_talking, 30, 48);
    talking = 0;
}
static void set_expression(enum CharacterExpression expression)
{
}
static void start_talking(void)
{
    talking = 0;
    talking_changed = 1;
}
static void stop_talking(void)
{
    talking = 1;
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