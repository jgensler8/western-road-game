#include "scene_inn.h"
#include "bg_store_owner.h"
#include "sp_store_owner.h"

static void process_input(void)
{
}
#define FRAME_TILE(x, y, frame, sheet) ((((y) * sheet.sheet_width_tiles) + (x)) + frame * sheet.sheet_frame_width_tiles)
struct SpriteSheet
{
    const uint8_t *tiles;
    uint8_t tiles_len;
    // sprite_data tile start
    uint8_t sheet_start;
    // how many frames of animation
    uint8_t sheet_frames;
    // for an individual frames, how many tiles wide is it
    uint8_t sheet_frame_width_tiles;
    // how wide is the entire sheet (cached calculation of sheet_frames*sheet_frame_tile_width)
    uint8_t sheet_width_tiles;
    uint8_t palette_start;
    uint8_t *palettes;
    uint8_t palettes_len;
};
enum AnimationStyle
{
    ANIMATION_STYLE_NONE,
    ANIMATION_STYLE_ONCE,
    ANIMATION_STYLE_LOOP,
    ANIMATION_STYLE_PING_PONG,
};
enum AnimationDirection
{
    ANIMATION_DIRECTION_FORWARD,
    ANIMATION_DIRECTION_BACKWARD,
};
struct SpriteAnimationState
{
    uint8_t frame;
    uint8_t frame_wait;
    enum AnimationDirection direction;
};
struct SpriteAnimation
{
    struct SpriteSheet sheet;
    // these are tile units
    uint8_t sheet_tile_x;
    uint8_t sheet_tile_y;
    uint8_t tile_width;
    uint8_t tile_height;
    uint8_t sp_index_start;
    uint8_t screen_x;
    uint8_t screen_y;
    uint8_t timings_len;
    uint8_t timings[8];
    enum AnimationStyle style;
    struct SpriteAnimationState state;
};
#define SP_STORE_OWNER_SHEET {           \
    .tiles = sp_store_owner_tiles,       \
    .tiles_len = 4 * 4 * 3,              \
    .sheet_start = 0,                    \
    .sheet_frames = 3,                   \
    .sheet_frame_width_tiles = 4,        \
    .sheet_width_tiles = 4 * 3,          \
    .palette_start = OAMF_CGB_PAL0,      \
    .palettes = sp_store_owner_palettes, \
    .palettes_len = 2,                   \
}
#define SP_STORE_OWNER_TILE_X 1
#define SP_STORE_OWNER_TILE_Y 1
#define SP_STORE_OWNER_SCREEN_X (SP_STORE_OWNER_TILE_X * 8)
#define SP_STORE_OWNER_SCREEN_Y (SP_STORE_OWNER_TILE_Y * 8)
#define SP_STORE_OWNER_FRAME_TIMINGS {128, 4, 4}
struct SpriteAnimation animation_left_eye = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 0,
    .screen_x = SP_STORE_OWNER_SCREEN_X + 18,
    .screen_y = SP_STORE_OWNER_SCREEN_Y + 25,
    .timings_len = 3,
    .timings = SP_STORE_OWNER_FRAME_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .state.frame = 0,
};
struct SpriteAnimation animation_right_eye = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 2,
    .sheet_tile_y = 0,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 2,
    .screen_x = SP_STORE_OWNER_SCREEN_X + 40,
    .screen_y = SP_STORE_OWNER_SCREEN_Y + 25,
    .timings_len = 3,
    .timings = SP_STORE_OWNER_FRAME_TIMINGS,
    .style = ANIMATION_STYLE_PING_PONG,
    .state.frame = 0,
};
struct SpriteAnimation animation_mouth = {
    .sheet = SP_STORE_OWNER_SHEET,
    .sheet_tile_x = 0,
    .sheet_tile_y = 1,
    .tile_width = 2,
    .tile_height = 1,
    .sp_index_start = 4,
    .screen_x = SP_STORE_OWNER_SCREEN_X + 30,
    .screen_y = SP_STORE_OWNER_SCREEN_Y + 48,
    .style = ANIMATION_STYLE_NONE,
    .state.frame = 0,
};
static void animation_init_sprite_sheet(struct SpriteSheet *sheet)
{
    set_sprite_data(sheet->sheet_start, sheet->tiles_len, sheet->tiles);
    set_sprite_palette(sheet->palette_start, sheet->palettes_len, sheet->palettes);
}
static void animation_init_sprite_animation(struct SpriteAnimation *ani)
{
    for (uint8_t tile_y = 0; tile_y < ani->tile_height; tile_y++)
    {
        for (uint8_t tile_x = 0; tile_x < ani->tile_width; tile_x++)
        {
            uint8_t sp_i = ani->sp_index_start + tile_y * ani->tile_width + tile_x;
            set_sprite_tile(sp_i, FRAME_TILE(ani->sheet_tile_x + tile_x, ani->sheet_tile_y + tile_y, ani->state.frame, ani->sheet));
            move_sprite(sp_i, ani->screen_x + 8 * tile_x + ADJUST_X, ani->screen_y + 8 * tile_y + ADJUST_Y);
        }
    }
}
static void animation_update(struct SpriteAnimation *ani)
{
    for (uint8_t tile_y = 0; tile_y < ani->tile_height; tile_y++)
    {
        for (uint8_t tile_x = 0; tile_x < ani->tile_width; tile_x++)
        {
            uint8_t sp_i = ani->sp_index_start + tile_y * ani->tile_width + tile_x;
            set_sprite_tile(sp_i, FRAME_TILE(ani->sheet_tile_x + tile_x, ani->sheet_tile_y + tile_y, ani->state.frame, ani->sheet));
        }
    }
    ani->state.frame_wait = ani->timings[ani->state.frame];
}
static inline void animate(struct SpriteAnimation *ani)
{
    switch (ani->style)
    {
    case ANIMATION_STYLE_NONE:
        // alread rendered in init
        return;
    case ANIMATION_STYLE_ONCE:
        if (ani->state.frame == ani->sheet.sheet_frames)
        {
            return;
        }
        ani->state.frame++;
        animation_update(ani);
        return;
    case ANIMATION_STYLE_LOOP:
        if (ani->state.frame == ani->sheet.sheet_frames)
        {
            ani->state.frame = 0;
        }
        else
        {
            ani->state.frame++;
        }
        animation_update(ani);
        return;
    case ANIMATION_STYLE_PING_PONG:
        // update state
        if (ani->state.frame == 0)
        {
            ani->state.direction = ANIMATION_DIRECTION_FORWARD;
        }
        else if (ani->state.frame == ani->sheet.sheet_frames)
        {
            ani->state.direction = ANIMATION_DIRECTION_BACKWARD;
        }
        // move frame
        if (ani->state.direction == ANIMATION_DIRECTION_FORWARD)
        {
            ani->state.frame++;
        }
        else if (ani->state.direction == ANIMATION_DIRECTION_BACKWARD)
        {
            ani->state.frame--;
        }
        // then render
        animation_update(ani);
        return;
    }
}
static inline void maybe_animate(struct SpriteAnimation *ani)
{
    if (ani->state.frame_wait > 0)
    {
        ani->state.frame_wait--;
    }
    else
    {
        animate(ani);
    }
}
static void render(uint8_t swapped)
{
    if (swapped)
    {
        // owner bg
        uint8_t owner_xt = SP_STORE_OWNER_TILE_X, owner_yt = SP_STORE_OWNER_TILE_Y;
        set_bkg_data(SCENE_BG_TILE_DATA_START, 64, bg_store_owner_tiles);
        set_bkg_palette(BKGF_CGB_PAL1, 7, bg_store_owner_palettes);
        struct PaletteArgs pargs = {
            .metasprites = bg_store_owner_metasprites[0],
            .palette_start = BKGF_CGB_PAL1,
        };
        set_bkg_offset(owner_xt, owner_yt, 8, 8, SCENE_BG_TILE_DATA_START, &pargs);
        // owner sp
        animation_init_sprite_sheet(&animation_left_eye.sheet);
        animation_init_sprite_animation(&animation_left_eye);
        animation_init_sprite_animation(&animation_right_eye);
        animation_init_sprite_animation(&animation_mouth);
        SHOW_SPRITES;
        // frame
        draw_frame(0, 0, 10, 10);
        text_draw_frame("HELLO THERE", EMPTY);
    }
    else
    {
        maybe_animate(&animation_left_eye);
        maybe_animate(&animation_right_eye);
        maybe_animate(&animation_mouth);
    }
}
struct Scene scene_inn = {
    .process_input = process_input,
    .render = render,
};