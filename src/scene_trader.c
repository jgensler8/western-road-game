#include "scene_trader.h"
#include "scene_road.h"
BANKREF_EXTERN(scene_road_ref)

uint8_t last_progress;
uint8_t progress;

enum ProgressType
{
    DIALOG,
    MENU,
};
enum ProgressType progress_types[13] = {
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
};

char *dialogs[13][2] = {
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
};

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
                    progress = 3;
                }
                else
                {
                    progress = 11;
                }
            }
            break;
        case 4:
            if (menu_process_input(&prompt_accept_trade))
            {
                if (prompt_accept_trade.selection == 0)
                {
                    progress = 5;
                }
                else
                {
                    progress = 8;
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
        }
    }
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        menu_reset_state();
        progress = 0;
        last_progress = 254;
    }
    if (progress != last_progress)
    {
        menu_reset_state();
    }
    if (progress_types[progress] == DIALOG)
    {
        if (progress != last_progress)
        {
            text_progress_init(dialogs[progress][0], dialogs[progress][1], &frame);
        }
        text_draw_frame_progress(&frame);
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