#pragma bank 0
#include <rand.h>
#include "data.h"
#include "scene_common.h"
#include "gen/scene/gen_scene_inn.h"
struct State default_state;

void state_generate_next_event(void)
{
    // // pick random event
    // if (rand() < 100)
    // {
    //     default_state.next_event = ROAD_EVENT_INN;
    // }
    default_state.next_event = ROAD_EVENT_INN;
    default_state.next_event_steps = 8;
}

void state_on_step(void)
{
    default_state.stats[STAT_STEPS] += 1;
    default_state.next_event_steps -= 1;
}

BANKREF_EXTERN(gen_scene_inn_ref)
const struct RoadEventScene road_events[ROAD_EVENT_COUNT] = {
    {},
    {
        .scene = &gen_scene_inn,
        .bank = BANK(gen_scene_inn_ref),
    },
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