#pragma once
#include "scene_common.h"

#define ROAD_SPRITE_MAX_FRAMES 4
static struct RoadSprite
{
    struct SpriteAnimation frames[ROAD_SPRITE_MAX_FRAMES];
    uint8_t sp_start;
    uint8_t frame;
    uint8_t last_render;
};

#define SHEET_SLOT(slot) (16 * slot)
#define ROAD_EVENT_LEFT_SP_START 0
#define ROAD_EVENT_RIGHT_SP_START 8

#define SP_EVENT_SHEET_TILES 16
#define SP_EVENT_SLOT SHEET_SLOT(2)
#define ROAD_EVENT_SP_START 16

#define RS_LEFT_X_0 40
#define RS_LEFT_Y_0 22
#define RS_LEFT_X_1 34
#define RS_LEFT_Y_1 38
#define RS_LEFT_X_2 26
#define RS_LEFT_Y_2 50
#define RS_LEFT_X_3 14
#define RS_LEFT_Y_3 60

void init_road_sprite(struct RoadSprite *rs);
void render_road_sprite(struct RoadSprite *rs);

// default road sprites
extern struct RoadSprite rs_cacti;
extern struct RoadSprite rs_rock;
// event road sprites
extern struct RoadSprite rs_events[ROAD_EVENT_COUNT];