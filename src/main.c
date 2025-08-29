#include "data.h"
#include "input.h"
#include "text.h"
#include "sound.h"
#include "scene_title.h"
#include "scene_shop.h"
#include "scene_trader.h"
#include "scene_road.h"
#include "scene_road_fork.h"
#include "gen/scene/gen_scene_intro.h"
#include "gen/scene/gen_scene_inn.h"
#include "gen/scene/gen_scene_shack.h"
#include "gen/scene/gen_scene_blue_house.h"
#include "gen/scene/gen_scene_bandit.h"
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
// #define FADE_MS 1

void main(void)
{
    SPRITES_8x8;
    text_init();
    struct StatCalculation default_calculation = {
        .src = STAT_STEPS,
        .dst = STAT_DISTANCE,
        .change = STAT_CHANGE_INC,
    };
    default_state.calculations[0] = default_calculation;
    default_state.stats[STAT_GOLD] = 5;
    default_state.stats[STAT_INN_VISITS] = 0;
    default_state.next_event = ROAD_EVENT_NONE;
    default_state.next_event_steps = 0;
    // objective init
    default_state.goal = GOAL_NONE;
    default_state.quest = QUEST_NONE;
    SCENE_OPTIONS_INIT
    BANKREF_EXTERN(scene_title_ref)
    queue_scene(&scene_title, BANK(scene_title_ref));
    // BANKREF_EXTERN(gen_scene_blue_house_ref);
    // queue_scene(&gen_scene_blue_house, BANK(gen_scene_blue_house_ref));
    // BANKREF_EXTERN(gen_scene_inn_ref);
    // queue_scene(&gen_scene_inn, BANK(gen_scene_inn_ref));
    // BANKREF_EXTERN(gen_scene_shack_ref);
    // queue_scene(&gen_scene_shack, BANK(gen_scene_shack_ref));
    // BANKREF_EXTERN(scene_shop_ref);
    // queue_scene(&scene_shop, BANK(scene_shop_ref));
    // default_state.items[ITEM_OVERALLS] = 1;
    // for (uint8_t i = ITEM_NONE + 1; i < ITEM_COUNT; i++)
    // {
    //     default_state.items[i] = 1;
    // }
    // BANKREF_EXTERN(scene_trader_ref);
    // queue_scene(&scene_trader, BANK(scene_trader_ref));
    // BANKREF_EXTERN(scene_road_ref);
    // queue_scene(&scene_road, BANK(scene_road_ref));
    // BANKREF_EXTERN(scene_road_fork_ref);
    // queue_scene(&scene_road_fork, BANK(scene_road_fork_ref));
    // default_state.stats[STAT_VERONICA_VISITS] = 0;
    // BANKREF_EXTERN(gen_scene_blue_house_ref);
    // queue_scene(&gen_scene_blue_house, BANK(gen_scene_blue_house_ref));
    // BANKREF_EXTERN(scene_bandit_ref);
    // queue_scene(&scene_bandit, BANK(scene_bandit_ref));
    // BANKREF_EXTERN(gen_scene_bandit_ref);
    // queue_scene(&gen_scene_bandit, BANK(gen_scene_bandit_ref));
    sound_init();
    clear_bkg();
    SHOW_BKG;
    SHOW_SPRITES;

    struct SceneRenderOptions options = {
        .swapped = 0,
        .fade = FADE_SWAP_STEPS - 1,
    };
    // 0 is normal 3 is completely black
    while (1)
    {
        if (options.fade > 0)
        {
            delay(FADE_MS);
        }
        input_scan();
        if (current_scene && options.fade == 0)
        {
            current_scene->process_input();
        }
        // make swap progress
        if (next_scene != NULL && next_scene != current_scene)
        {
            // swap out
            if (options.fade < FADE_SWAP_STEPS - 1)
            {
                // continue swap out swap out
                // fade_all_bg_palettes(options.fade);
                options.fade += 1;
            }
            else
            {
                // when the swap out progress is complete, then swap scenes
                current_scene = next_scene;
                next_scene = NULL;
                SWITCH_ROM(next_bank_num);
                options.swapped = 1;
                palette_util_reset();
                clear_bkg();
                animation_hide_all();
            }
        }
        else
        {
            // swap in
            if (options.fade > 0)
            {
                options.fade -= 1;
            }
        }
        // safety check
        // note: still rendered during the swap in
        if (current_scene)
        {
            wait_vbl_done();
            // EMU_PROFILE_BEGIN("render_s:%TOTALCLKS%:")
            current_scene->render(&options);
            palette_util_maybe_fade(&options);
            // EMU_PROFILE_END("render_e:%TOTALCLKS%:")
            // unset swapped
            options.swapped = 0;
        }
    }
}