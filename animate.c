#pragma bank 0
#include "types.h"
#include <gbdk/platform.h>
#include "animate.h"

void animation_init_sprite_sheet(struct SpriteSheet *sheet)
{
    set_sprite_data(sheet->sheet_start, sheet->tiles_len, sheet->tiles);
    set_sprite_palette(sheet->palette_start, sheet->palettes_len, sheet->palettes);
}
void animation_update(struct SpriteAnimation *ani)
{
    uint8_t sp_i = ani->sp_index_start;
    for (uint8_t tile_y = 0; tile_y < ani->tile_height; tile_y++)
    {
        for (uint8_t tile_x = 0; tile_x < ani->tile_width; tile_x++)
        {
            set_sprite_tile(sp_i, ani->frame_tiles[ani->state.frame][tile_y][tile_x]);
            sp_i++;
        }
    }
    ani->state.frame_wait = ani->timings[ani->state.frame];
}
#define FRAME_TILE(x, y, frame, sheet) ((((y) * sheet.sheet_width_tiles) + (x)) + frame * sheet.sheet_frame_width_tiles)
void animation_init_sprite_animation(struct SpriteAnimation *ani)
{
    // init frame data
    for (uint8_t frame = 0; frame < ANIMATION_MAX_FRAMES; frame++)
    {
        for (uint8_t tile_y = 0; tile_y < ani->tile_height; tile_y++)
        {
            for (uint8_t tile_x = 0; tile_x < ani->tile_width; tile_x++)
            {
                ani->frame_tiles[frame][tile_y][tile_x] = FRAME_TILE(ani->sheet_tile_x + tile_x, ani->sheet_tile_y + tile_y, frame, ani->sheet);
            }
        }
    }
    // move current sp
    uint8_t sp_i = ani->sp_index_start;
    for (uint8_t tile_y = 0; tile_y < ani->tile_height; tile_y++)
    {
        for (uint8_t tile_x = 0; tile_x < ani->tile_width; tile_x++)
        {
            move_sprite(sp_i, ani->screen_x + 8 * tile_x + ADJUST_X, ani->screen_y + 8 * tile_y + ADJUST_Y);
            sp_i++;
        }
    }
    // animate current frame
    animation_update(ani);
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
void maybe_animate(struct SpriteAnimation *ani)
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