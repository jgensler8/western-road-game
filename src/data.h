#pragma once
#include <gb/metasprites.h>
#include <gbdk/platform.h>
#include <stdint.h>

struct SceneRenderOptions
{
    uint8_t swapped;
    uint8_t fade;
};

struct Scene
{
    void (*process_input)(void);
    void (*render)(const struct SceneRenderOptions *options);
};
extern void queue_scene(struct Scene *new_next_scene, uint8_t new_bank_num);

enum Stat
{
    STAT_NONE,
    STAT_STEPS,
    STAT_DISTANCE,
    STAT_GOLD,
    STAT_COUNT,
};

enum StatChange
{
    STAT_CHANGE_INC,
    STAT_CHANGE_DEC,
    STAT_CHANGE_MUL,
};

struct StatCalculation
{
    enum Stat src;
    enum Stat dst;
    enum StatChange change;
};

enum RoadEvent
{
    ROAD_EVENT_NONE,
    ROAD_EVENT_INN,
    ROAD_EVENT_CHERI_QUEST_1,
    ROAD_EVENT_COUNT,
};

struct RoadEventScene
{
    struct Scene *scene;
    uint8_t bank;
};

#define MAX_STAT_CALCULATIONS 32
struct State
{
    uint16_t stats[STAT_COUNT];
    struct StatCalculation calculations[MAX_STAT_CALCULATIONS];
    enum RoadEvent next_event;
    uint16_t next_event_steps;
    uint16_t inn_visits;
};
extern struct State default_state;
void state_generate_next_event(void);
void state_on_step(void);
void state_maybe_handle_event(void);