#pragma once

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
#define ANIMATION_MAX_FRAMES 8
#define ANIMATION_MAX_HEIGHT 2
#define ANIMATION_MAX_WIDTH 2
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
    uint8_t timings[ANIMATION_MAX_FRAMES];
    uint8_t frame_tiles[ANIMATION_MAX_FRAMES][ANIMATION_MAX_HEIGHT][ANIMATION_MAX_WIDTH];
    enum AnimationStyle style;
    struct SpriteAnimationState state;
};


void animation_init_sprite_sheet(struct SpriteSheet *sheet);
void animation_init_sprite_animation(struct SpriteAnimation *ani);
void maybe_animate(struct SpriteAnimation *ani);