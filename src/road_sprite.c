#pragma bank 2
#include "road_sprite.h"

#define EXTERN_ROAD_SPRITE_FRAMES(sprite)                           \
    extern const struct SpriteAnimationConst rs_##sprite##_frame_0; \
    extern const struct SpriteAnimationConst rs_##sprite##_frame_1; \
    extern const struct SpriteAnimationConst rs_##sprite##_frame_2; \
    extern const struct SpriteAnimationConst rs_##sprite##_frame_3;

EXTERN_ROAD_SPRITE_FRAMES(cacti)
EXTERN_ROAD_SPRITE_FRAMES(inn)
EXTERN_ROAD_SPRITE_FRAMES(rock)
EXTERN_ROAD_SPRITE_FRAMES(shack)

const struct RoadSprite rs_events[ROAD_EVENT_COUNT] = {
    {
        .sp_start = 0,
    },
    // ROAD_EVENT_INN
    {
        .frames = {
            {.con = &rs_inn_frame_0},
            {.con = &rs_inn_frame_1},
            {.con = &rs_inn_frame_2},
            {.con = &rs_inn_frame_3},
        },
        .sp_start = ROAD_EVENT_SP_START,
    },
    // ROAD_EVENT_CHERI_QUEST_1
    {
        .frames = {
            {.con = &rs_shack_frame_0},
            {.con = &rs_shack_frame_1},
            {.con = &rs_shack_frame_2},
            {.con = &rs_shack_frame_3},
        },
        .sp_start = ROAD_EVENT_SP_START,
    },
    // ROAD_EVENT_BLUE_HOUSE
    {
        .frames = {
            {.con = &rs_shack_frame_0},
            {.con = &rs_shack_frame_1},
            {.con = &rs_shack_frame_2},
            {.con = &rs_shack_frame_3},
        },
        .sp_start = ROAD_EVENT_SP_START,
    },
    // ROAD_EVENT_TRADER
    {
        .frames = {
            {.con = &rs_shack_frame_0},
            {.con = &rs_shack_frame_1},
            {.con = &rs_shack_frame_2},
            {.con = &rs_shack_frame_3},
        },
        .sp_start = ROAD_EVENT_SP_START,
    },
};

void render_road_sprite(struct RoadSprite *rs)
{
    if (rs->last_render != rs->frame)
    {
        // given that i am overlapping road events with the sp_cacti, always clear 8 sprites even if we only use 4
        uint8_t max_frames = rs->frames[0].con->sp_index_start + 8;
        animation_hide_range(rs->frames[3].con->sp_index_start, max_frames);
        animation_init_sprite_animation(&rs->frames[rs->frame]);
        rs->last_render = rs->frame;
    }
}

void init_road_sprite(struct RoadSprite *rs)
{
    animation_init_sprite_sheet(&rs->frames[0].con->sheet);
    // force render by setting an impossible last_render
    rs->last_render = ROAD_SPRITE_MAX_FRAMES + 1;
    rs->frame = 0;
}