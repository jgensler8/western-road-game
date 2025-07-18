#pragma bank 0
#include <rand.h>
#include "data.h"
#include "scene_common.h"
#include "gen/scene/gen_scene_inn.h"
#include "gen/scene/gen_scene_shack.h"
#include "gen/scene/gen_scene_blue_house.h"
#include "scene_road_fork.h"
#include "scene_trader.h"

// the global state struct
struct State default_state;

void state_generate_next_event(void)
{
    // pick random event
    uint8_t r = rand();
    if (r < 50)
    {
        default_state.next_event = ROAD_EVENT_TRADER;
    }
    else if (r < 100)
    {
        default_state.next_event = ROAD_EVENT_BLUE_HOUSE;
    }
    else if (r < 150)
    {
        default_state.next_event = ROAD_EVENT_FORK;
    }
    else
    {
        default_state.next_event = ROAD_EVENT_INN;
    }
    default_state.next_event_steps = 8;
}

void state_on_step(void)
{
    default_state.stats[STAT_STEPS] += 1;
    default_state.next_event_steps -= 1;
}

BANKREF_EXTERN(gen_scene_inn_ref)
BANKREF_EXTERN(gen_scene_shack_ref)
BANKREF_EXTERN(gen_scene_blue_house_ref)
BANKREF_EXTERN(scene_trader_ref)
BANKREF_EXTERN(scene_road_fork_ref)
const struct RoadEventScene road_events[ROAD_EVENT_COUNT] = {
    {0},
    {
        .scene = &gen_scene_inn,
        .bank = BANK(gen_scene_inn_ref),
    },
    {
        .scene = &gen_scene_shack,
        .bank = BANK(gen_scene_shack_ref),
    },
    {
        .scene = &gen_scene_blue_house,
        .bank = BANK(gen_scene_blue_house_ref),
    },
    {
        .scene = &scene_trader,
        .bank = BANK(scene_trader_ref),
    },
    // bandit a,b,c
    {0},
    {0},
    {0},
    {
        .scene = &scene_road_fork,
        .bank = BANK(scene_road_fork_ref),
    }
};

void state_maybe_handle_event(void)
{
    if (default_state.next_event != ROAD_EVENT_NONE && default_state.next_event_steps == 0)
    {
        enum RoadEvent event = default_state.next_event;
        // unset event
        default_state.next_event = ROAD_EVENT_NONE;
        queue_scene(road_events[event].scene, road_events[event].bank);
    }
}