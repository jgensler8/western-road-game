#pragma bank 5
#include "scene_trader.h"
#include "scene_road.h"
#include <rand.h>
BANKREF_EXTERN(scene_road_ref)

uint8_t last_progress;
uint8_t progress;
uint8_t gold_receive;
enum Item item_give;
enum Item item_receive;
uint8_t offer_rendered;

inline void create_trade_offer()
{
    int possible_trades[8];
    uint8_t possible_trades_count = 0;
    for (uint8_t i = 1; i < ITEM_COUNT; i++)
    {
        if (default_state.items[i] > 0)
        {
            possible_trades[possible_trades_count] = i;
            possible_trades_count++;
        }
    }
    int possible_receives[8];
    uint8_t possible_receives_count = 0;
    for (uint8_t i = 1; i < ITEM_COUNT; i++)
    {
        if (default_state.items[i] == 0)
        {
            possible_receives[possible_receives_count] = i;
            possible_receives_count++;
        }
    }
    item_receive = possible_receives[rand() % possible_receives_count];
    if (possible_trades_count == 0)
    {
        item_give = ITEM_NONE;
    }
    else
    {
        item_give = possible_trades[rand() % possible_trades_count];
    }
}

enum ProgressType
{
    DIALOG,
    MENU,
};
const enum ProgressType progress_types[18] = {
    DIALOG,
    DIALOG,
    MENU,

    DIALOG,
    MENU,
    DIALOG,
    DIALOG,
    MENU,

    DIALOG,
    DIALOG,
    MENU,

    DIALOG,
    MENU,

    DIALOG,
    DIALOG,
    DIALOG,
    MENU,
};

const char *dialogs[18][2] = {
    {"HELLO THERE", "TRAVELER"},
    {"MIGHT I INTEREST", "YOU IN A TRADE?"},
    {0},

    // accept,
    {"WONDERFUL. HERE IS", "WHAT I PROPOSE"},
    {0},
    {"PLEASURE DOING", "BUSINESS"},
    {"SAFE TRAVELS", EMPTY},
    {0},

    // follow up offer
    {"WAIT WAIT!", EMPTY},
    {"LET ME SWEETEN", "THE DEAL"},
    {0},

    // skip the follow up
    {"IF YOU INSIST...", EMPTY},
    {0},

    // no items to trade
    {"OH....", EMPTY},
    {"YOU DON'T HAVE", "ANYTHING TO TRADE"},
    {"HERE, TAKE THIS", EMPTY},
    {0}};

static struct Menu prompt_offer = {
    .options = {
        "I'LL CONSIDER IT",
        "NO, THANK YOU",
    },
    .max_option = 1,
};

static struct Menu prompt_accept_trade = {
    .options = {
        "ACCEPT TRADE",
        "DECLINE TRADE",
    },
    .max_option = 1,
};

struct ProgressableFrame frame;

static void process_input(void)
{
    SCENE_OPTIONS_PROCESS_INPUT_TAKEOVER
    if (progress_types[progress] == DIALOG)
    {
        if (joypad_a_pressed)
        {
            if (text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            }
            else
            {
                progress++;
            }
        }
    }
    else if (progress_types[progress] == MENU)
    {
        switch (progress)
        {
        case 2:
            if (menu_process_input(&prompt_offer))
            {
                if (prompt_offer.selection == 0)
                {
                    // interested in trade
                    if (item_give == ITEM_NONE)
                    {
                        // no item to give
                        progress = 13;
                    }
                    else
                    {
                        // trade screen
                        progress = 3;
                    }
                }
                else
                {
                    // not interested
                    progress = 11;
                }
            }
            break;
        case 4:
            if (menu_process_input(&prompt_accept_trade))
            {
                if (prompt_accept_trade.selection == 0)
                {
                    // accept the offer
                    default_state.items[item_give] = 0;
                    default_state.items[item_receive] = 1;
                    default_state.stats[STAT_GOLD] += gold_receive;
                    progress = 5;
                }
                else
                {
                    // decline the offer
                    progress = 8;
                    gold_receive = rand();        
                    offer_rendered = 0;
                    // maybe not get a follow up offer
                    // progress = 10;
                }
            }
            break;
        case 7:
            progress = 12;
            break;
        case 10:
            // incrase offer
            progress = 4;
            break;
        case 12:
            queue_scene(&scene_road, BANK(scene_road_ref));
            break;
        case 16:
            progress = 12;
            break;
        }
    }
}

static inline void render_offer_screen()
{
    if (offer_rendered == 0)
    {
        draw_frame(9, 0, 11, 10);
        xy_printf(10, 1, "GIVE:");
        xy_printf(10, 2, item_name(item_give));
        xy_printf(10, 4, "RECEIVE:");
        xy_printf(10, 5, item_name(item_receive));
        if (gold_receive > 0)
        {
            xy_printf(10, 6, fixed_itoa(gold_receive));
            xy_printf(15, 6, "GOLD");
        }
        // description
        draw_frame(0, 10, 20, 4);
        xy_printf(1, 11, item_details[item_receive][0]);
        xy_printf(1, 12, item_details[item_receive][1]);
    }
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        menu_reset_state();
        character_init(CHARACTER_MODEL_TRADER, 1, 1);
        progress = 0;
        offer_rendered = 0;
        gold_receive = 0;
        last_progress = 254;
        create_trade_offer();
    }
    SCENE_OPTIONS_RENDER_TAKEOVER
    if (progress != last_progress)
    {
        menu_reset_state();
    }
    character_render(CHARACTER_MODEL_TRADER, CHARACTER_EXPRESSION_DEFAULT);
    if (progress_types[progress] == DIALOG)
    {
        if (progress != last_progress)
        {
            text_progress_init(dialogs[progress][0], dialogs[progress][1], &frame);
            character_start_talking(CHARACTER_MODEL_TRADER);
        }
        if (!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_TRADER);
        };
    }
    else if (progress_types[progress] == MENU)
    {
        switch (progress)
        {
        case 2:
            menu_render(&prompt_offer);
            break;
        case 4:
            // render offer screen
            render_offer_screen();
            menu_render(&prompt_accept_trade);
            break;
        }
    }
    last_progress = progress;
}

BANKREF(scene_trader_ref)
struct Scene scene_trader = {
    .process_input = process_input,
    .render = render,
};