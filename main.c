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

#include "bg_fade.h"
#include <gbdk/platform.h>
#define FADE_TILE_START 69
#define FADE_SWAP_STEPS 4
void load_swap_bkg(void)
{
    set_bkg_1bpp_data(FADE_TILE_START, FADE_SWAP_STEPS, bg_fade_tiles);
}

void main(void)
{
    text_init();
    load_swap_bkg();
    struct StatCalculation default_calculation = {
        .src = STAT_STEPS,
        .dst = STAT_DISTANCE,
        .change = STAT_CHANGE_INC,
    };
    default_state.calculations[0] = default_calculation;
    queue_scene(&scene_title);
    sound_init();
    clear_bkg();

    uint8_t swapped = 0;
    // 0 is empty 4 is completely black
    int8_t swap_progress = FADE_SWAP_STEPS - 1;
    while (1)
    {
        wait_vbl_done();
        if (swap_progress > 0)
        {
            delay(200);
        }
        input_scan();
        if (current_scene && swap_progress == 0)
        {
            current_scene->process_input();
        }
        // try swap in
        if (next_scene != NULL && next_scene != current_scene)
        {
            if (swap_progress < FADE_SWAP_STEPS)
            {
                // continue swap out swap out
                // in this case swap_progress==0 means the first tile
                fill_win_rect(0, 0, 20, 18, FADE_TILE_START + swap_progress);
                SHOW_WIN;
                swap_progress += 1;
            }
            else
            {
                // when the swap out progress is complete, then swap scenes
                current_scene = next_scene;
                next_scene = NULL;
            }
        }
        else
        {
            if (swap_progress > 0)
            {
                if (swap_progress > FADE_SWAP_STEPS)
                {
                    swap_progress == FADE_SWAP_STEPS;
                }
                // swap in
                // in this case, swap_progress==1 means the first tile
                fill_win_rect(0, 0, 20, 18, FADE_TILE_START + swap_progress - 1);
                swap_progress -= 1;
                if (swap_progress == 0)
                {
                    delay(400);
                    swapped = 1;
                    HIDE_WIN;
                }
            }

            // safety check
            // note: still rendered during the swap in
            if (current_scene)
            {
                current_scene->render(swapped);
                // unset swapped
                swapped = 0;
            }
        }
    }
}
