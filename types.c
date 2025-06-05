#pragma bank 0
#include "types.h"
#include "rand.h"
#include "scene_common.h"
struct State default_state;

void set_bkg_offset(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t tile_start, struct PaletteArgs *args)
{
    for (uint8_t y_s = 0; y_s < height; y_s++)
    {
        for (uint8_t x_s = 0; x_s < width; x_s++)
        {
            uint8_t tile_offset = y_s * width + x_s;
            set_bkg_tile_xy(x + x_s, y + y_s, tile_start + tile_offset);
            if (args != NULL)
            {
                uint8_t metasprite_props = args->metasprites[tile_offset].props;
                set_bkg_attribute_xy(x + x_s, y + y_s, args->palette_start + metasprite_props);
            }
        }
    }
}

void on_step(void)
{
    if (default_state.next_event == 0)
    {
        if (rand() < 100)
        {
            default_state.next_event = 1;
            default_state.next_event_steps = 5 + rand() / 16;
        }
    }
    if (default_state.next_event_steps > 0)
    {
        default_state.next_event_steps -= 1;
    }
    default_state.stats[STAT_STEPS] += 1;
}

void maybe_handle_event(void)
{
    if (default_state.next_event != 0 && default_state.next_event_steps == 0)
    {
        text_draw_frame("IS THIS AN INN?", EMPTY);
        delay(500);
        // unset event
        default_state.next_event = 0;
    }
}