#pragma once
#include <gb/metasprites.h>
#include <gbdk/platform.h>
#include <stdint.h>

// common bkg operations
#define ADJUST_X 8
#define ADJUST_Y 16
struct PaletteArgs
{
    const metasprite_t* metasprites;
    uint8_t palette_start;
};
void set_bkg_offset(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t tile_start, struct PaletteArgs* args);

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
    uint16_t stats[STAT_COUNT];
    struct StatCalculation calculations[MAX_STAT_CALCULATIONS];
    uint8_t next_event;
    uint8_t next_event_steps;
};
extern struct State default_state;
void on_step(void);
void maybe_handle_event(void);