#include "types.h"
#include "input.h"
#include "text.h"
#include "sound.h"
#include "scene_start_menu.h"

struct Scene *current_scene = NULL;
struct Scene *next_scene = NULL;
void queue_scene(struct Scene *new_next_scene)
{
    next_scene = new_next_scene;
    menu_reset_state();
}

void main(void)
{
    text_init();    
    struct StatCalculation default_calculation = {
        .src = STAT_STEPS,
        .dst = STAT_DISTANCE,
        .change = STAT_CHANGE_INC,
    };
    default_state.calculations[0] = default_calculation;
    queue_scene(&scene_title);
    sound_init();

    uint8_t swapped = 0;
    while (1)
    {
        wait_vbl_done();
        input_scan();
        if (current_scene)
        {
            current_scene->process_input();
        }
        // maybe swap scene but do not immediately render it
        if (next_scene != NULL && next_scene != current_scene)
        {
            clear_bkg();
            current_scene = next_scene;
            next_scene = NULL;
            swapped = 1;
        }
        else
        {
            if (current_scene)
            {
                current_scene->render(swapped);
            }
            if (swapped)
            {
                swapped = 0;
            }
        }
    }
}
