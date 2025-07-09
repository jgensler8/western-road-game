#pragma bank 4
#include "character_cheri.h"
#include "gen/png2asset/bg_cheri.h"
#include "gen/png2asset/sp_cheri.h"
#include "gen/metasprite_fix/bg_cheri.h"
#include "gen/metasprite_fix/sp_cheri.h"

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

static uint8_t talking;
static uint8_t talking_changed;
#define BG_CHERI_METASPRITE ANIMATE_DEFAULT_METASPRITE(bg_cheri)
#define SP_CHERI_METASPRITE ANIMATE_DEFAULT_METASPRITE(sp_cheri)
static struct MemoryAllocation init(struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y)
{
    // palette
    uint8_t pal_start = palette_util_init_bkg(PALETTE_UTIL_BG(bg_cheri));
    // bg
    set_bkg_data(70, bg_cheri_TILE_COUNT, bg_cheri_tiles);
    struct PaletteArgs pargs = {
        .palette_map = bg_cheri_palette_map,
        .palette_start = pal_start,
    };
    set_bkg_offset(tile_x, tile_y, 8, 8, start.bg_start, &pargs);
    // sprite
    animation_init_sprite_sheet(&left_eye.con->sheet);
    animation_init_sprite_animation(&left_eye);
    animation_init_sprite_animation(&right_eye);
    animation_init_sprite_animation(&mouth_passive);
    animation_init_sprite_animation(&mouth_talking);
    talking = 0;
    talking_changed = 1;
    struct MemoryAllocation done = {
        .bg_start = start.bg_start,
        .bg_end = start.bg_start + 1,
    };
    return done;
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

static void render()
{
    maybe_animate(&left_eye);
    maybe_animate(&right_eye);
    if (talking)
    {
        maybe_animate(&mouth_talking);
        if (talking_changed)
        {
            animation_show(&mouth_talking);
            animation_hide(&mouth_passive);
        }
    }
    else
    {
        maybe_animate(&mouth_passive);
        if (talking_changed)
        {
            animation_show(&mouth_passive);
            animation_hide(&mouth_talking);
        }
    }
    talking_changed = 0;
}

BANKREF(character_cheri_ref)
struct Character character_cheri = {
    .init = init,
    .set_expression = set_expression,
    .start_talking = start_talking,
    .stop_talking = stop_talking,
    .render = render,
};