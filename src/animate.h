#pragma once

// common bkg operations
#define ADJUST_X 8
#define ADJUST_Y 16
struct PaletteArgs
{
    const uint8_t *palette_map;
    uint8_t palette_start;
};
void set_bkg_offset(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t tile_start, struct PaletteArgs *args);

struct SpriteSheet
{
    const uint8_t *tiles;
    uint8_t tiles_len;
    // set_sprite_data tile start
    uint8_t sheet_start;
    // how many frames of animation
    uint8_t sheet_frames;
    // for an individual frames, how many tiles wide is it
    uint8_t sheet_frame_width_tiles;
    // how wide is the entire sheet (cached calculation of sheet_frames*sheet_frame_tile_width)
    uint8_t sheet_width_tiles;
    // sprite palette start (0-7), overwritten on sprite_sheet_init due to auto
    uint8_t palette_start;
    uint8_t *palettes;
    uint8_t palettes_len;
    uint8_t *palette_map;
};
#define ANIMATE_SPRITE_SHEET_COMMON(SPRITE) { \
    .tiles = SPRITE##_tiles,                  \
    .tiles_len = SPRITE##_TILE_COUNT,         \
    .sheet_start = 0,                         \
    .sheet_frames = 3,                        \
    .sheet_frame_width_tiles = 4,             \
    .sheet_width_tiles = 4 * 3,               \
    .palettes = SPRITE##_palettes,            \
    .palettes_len = SPRITE##_PALETTE_COUNT,   \
    .palette_map = SPRITE##_palette_map,      \
}

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
#define ANIMATION_MAX_FRAMES 8
#define ANIMATION_MAX_HEIGHT 4
#define ANIMATION_MAX_WIDTH 4
// #define ANIMATION_MAX_HEIGHT 2
// #define ANIMATION_MAX_WIDTH 2
struct SpriteAnimationConst
{
    const struct SpriteSheet sheet;
    // these are tile units
    uint8_t sheet_tile_x;
    uint8_t sheet_tile_y;
    uint8_t tile_width;
    uint8_t tile_height;
    uint8_t sp_index_start;
    uint8_t screen_x;
    uint8_t screen_y;
    uint8_t timings_len;
    uint8_t timings[ANIMATION_MAX_FRAMES];
    enum AnimationStyle style;
    // absolute sp tile_data to use (macro generations include tile_start)
    uint8_t frame_tiles[ANIMATION_MAX_FRAMES][ANIMATION_MAX_HEIGHT][ANIMATION_MAX_WIDTH];
};
#define ANI_FRAME_TILE(tile_start, sheet_width_tiles, sheet_frame_width_tiles, x, y, frame) ((((y) * sheet_width_tiles) + (x)) + (frame * sheet_frame_width_tiles) + tile_start)
#define ANI_FRAME(ts, swt, sfwt, tile_x, tile_y, frame) {             \
    {                                                                 \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 0, tile_y + 0, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 1, tile_y + 0, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 2, tile_y + 0, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 3, tile_y + 0, frame), \
    },                                                                \
    {                                                                 \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 0, tile_y + 1, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 1, tile_y + 1, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 2, tile_y + 1, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 3, tile_y + 1, frame), \
    },                                                                \
    {                                                                 \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 0, tile_y + 2, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 1, tile_y + 2, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 2, tile_y + 2, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 3, tile_y + 2, frame), \
    },                                                                \
    {                                                                 \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 0, tile_y + 3, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 1, tile_y + 3, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 2, tile_y + 3, frame), \
        ANI_FRAME_TILE(ts, swt, sfwt, tile_x + 3, tile_y + 3, frame), \
    },                                                                \
}
#define ANI_FRAMES(tile_start, sheet_width_tiles, sheet_frame_width_tiles, tile_x, tile_y) { \
    ANI_FRAME(tile_start, sheet_width_tiles, sheet_frame_width_tiles, tile_x, tile_y, 0),    \
    ANI_FRAME(tile_start, sheet_width_tiles, sheet_frame_width_tiles, tile_x, tile_y, 1),    \
    ANI_FRAME(tile_start, sheet_width_tiles, sheet_frame_width_tiles, tile_x, tile_y, 2),    \
    ANI_FRAME(tile_start, sheet_width_tiles, sheet_frame_width_tiles, tile_x, tile_y, 3),    \
}
struct SpriteAnimation
{
    const struct SpriteAnimationConst *con;
    struct SpriteAnimationState state;
};

#define ANIMATE_DEFAULT_METASPRITE(SPRITE) SPRITE##_metasprites[0]
#define ANIMATE_TILE_OFFSET(animation, offset_x, offset_y) \
    animation.screen_x = tile_x * 8 + offset_x;            \
    animation.screen_y = tile_y * 8 + offset_y;
#define ANIMATE_DEFAULT_BLINK_TIMINGS {128, 4, 4}
#define ANIMATE_DEFAULT_TALK_TIMINGS {10, 1, 2}
void animation_init_sprite_sheet(const struct SpriteSheet *sheet);
void animation_move_sprite(struct SpriteAnimation *ani);
void animation_init_sprite_animation(struct SpriteAnimation *ani);
void maybe_animate(struct SpriteAnimation *ani);
void animation_show(struct SpriteAnimation *ani);
void animation_hide(struct SpriteAnimation *ani);
void animation_hide_range(uint8_t start, uint8_t end);
void animation_hide_all(void);

#define PALETTE_UTIL_BG(SPRITE) SPRITE##_PALETTE_COUNT, SPRITE##_palettes
#define PALETTE_UTIL_SP(SPRITE) SPRITE##_PALETTE_COUNT, SPRITE##_palettes
void palette_util_reset(void);
// returns the starting palette used
uint8_t palette_util_init_bkg(uint8_t palette_count, const palette_color_t *palettes);
void palette_util_init_sp(const uint8_t palette_start, const uint8_t palette_count, const palette_color_t *palettes);
void palette_util_maybe_fade(struct SceneRenderOptions *options);