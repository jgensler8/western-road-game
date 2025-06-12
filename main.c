#include "types.h"
#include "input.h"
#include "text.h"
#include "sound.h"
#include "scene_start_menu.h"
#include "scene_road.h"
#include "scene_inn.h"
#include "gen_scene_inn.h"
#include <gb/hardware.h>

struct Scene *current_scene = NULL;
struct Scene *next_scene = NULL;
uint8_t next_bank_num = 1;
void queue_scene(struct Scene *new_next_scene, uint8_t new_bank_num)
{
    next_scene = new_next_scene;
    next_bank_num = new_bank_num;
    menu_reset_state();
}

#define FADE_SWAP_STEPS 4
#define FADE_MS 200
const palette_color_t pals[] = {
    RGB_WHITE,
    RGB_LIGHTGRAY,
    RGB_DARKGRAY,
    RGB_BLACK,
    // p2
    RGB_LIGHTGRAY,
    RGB_DARKGRAY,
    RGB_BLACK,
    RGB_BLACK,
    // p3
    RGB_DARKGRAY,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    // p4
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
};
palette_color_t *get_palette_for_fade(uint8_t fade)
{
    switch (fade)
    {
    case 0:
        return &pals[0];
    case 1:
        return &pals[4];
    case 2:
        return &pals[8];
    case 3:
        return &pals[12];
    default:
        return &pals[0];
    }
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
    // ~~~~ MAKE SURE SWITCH_ROM IS CORRECT ~~~~
    // queue_scene(&scene_title, 2);
    // SWITCH_ROM(2);
    // queue_scene(&scene_road);
    BANKREF_EXTERN(scene_inn_ref)
    queue_scene(&scene_inn, BANK(scene_inn_ref));
    SWITCH_ROM(BANK(scene_inn_ref));
    // BANKREF_EXTERN(gen_scene_inn_ref);
    // queue_scene(&gen_scene_inn, BANK(gen_scene_inn_ref));
    // ~~~ !!! ~~~
    sound_init();
    clear_bkg();

    uint8_t swapped = 0;
    // 0 is normal 3 is completely black
    uint8_t swap_progress = FADE_SWAP_STEPS - 1;
    while (1)
    {
        if (swap_progress > 0)
        {
            delay(FADE_MS);
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
                set_bkg_palette(BKGF_CGB_PAL0, 1, get_palette_for_fade(swap_progress));
                swap_progress += 1;
            }
            else
            {
                // when the swap out progress is complete, then swap scenes
                current_scene = next_scene;
                next_scene = NULL;
                SWITCH_ROM(next_bank_num);
            }
        }
        else
        {
            if (swap_progress > 0)
            {
                if (swap_progress >= FADE_SWAP_STEPS)
                {
                    swap_progress = FADE_SWAP_STEPS - 1;
                }
                // swap in
                set_bkg_palette(BKGF_CGB_PAL0, 1, get_palette_for_fade(swap_progress));
                swap_progress -= 1;
                if (swap_progress == 0)
                {
                    delay(FADE_MS);
                    set_bkg_palette(BKGF_CGB_PAL0, 1, get_palette_for_fade(0));
                    swapped = 1;
                }
            }

            // safety check
            // note: still rendered during the swap in
            if (current_scene)
            {
                wait_vbl_done();
                EMU_PROFILE_BEGIN("render_s:%TOTALCLKS%:")
                current_scene->render(swapped);
                EMU_PROFILE_END("render_e:%TOTALCLKS%:")
                // unset swapped
                swapped = 0;
            }
        }
    }
}
