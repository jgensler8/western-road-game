#pragma once
#include <gbdk/platform.h>
#include <stdint.h>

struct Scene
{
    void (*process_input)(void);
    void (*render)(uint8_t swapped);
};
extern void queue_scene(struct Scene *new_next_scene);

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

#define MAX_STAT_CALCULATIONS 32
struct State
{
    struct StatCalculation calculations[MAX_STAT_CALCULATIONS];
};
extern struct State default_state;