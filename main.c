/*
    fonts.c
    Simple example of how to use multiple fonts on the GB
    Michael Hope, 1999.
*/

#include <stdio.h>
#include <string.h>
#include <gbdk/platform.h>
// #include <gb/gb.h>

#include "lankygitmono.h"
#include "sframe7.h"

#define ALPHABET_TILE_START 0
void xy_printf(uint8_t screen_x, uint8_t screen_y, char *word)
{
    uint8_t len = strlen(word);
    for (uint8_t c = 0; c < len; c++)
    {
        set_bkg_tile_xy(screen_x + c, screen_y, ALPHABET_TILE_START + word[c] - ' ');
    }
}

void draw_frame(uint8_t screen_x, uint8_t screen_y, uint8_t width, uint8_t height)
{
    uint8_t frame_tile_start = 'Z' - ' ' + 1;
    // corners
    set_bkg_tile_xy(screen_x, screen_y, frame_tile_start + 0);
    set_bkg_tile_xy(screen_x + width - 1, screen_y, frame_tile_start + 2);
    set_bkg_tile_xy(screen_x, screen_y + height - 1, frame_tile_start + 6);
    set_bkg_tile_xy(screen_x + width - 1, screen_y + height - 1, frame_tile_start + 8);
    // row
    for (uint8_t c = 1; c < width - 1; c++)
    {
        // top
        set_bkg_tile_xy(screen_x + c, screen_y, frame_tile_start + 1);
        // bottom
        set_bkg_tile_xy(screen_x + c, screen_y + height - 1, frame_tile_start + 7);
    }
    // columns
    for (uint8_t c = 1; c < height - 1; c++)
    {
        // left
        set_bkg_tile_xy(screen_x, screen_y + c, frame_tile_start + 3);
        // right
        set_bkg_tile_xy(screen_x + width - 1, screen_y + c, frame_tile_start + 5);
    }
}

void clear_bkg()
{
    // this is the space tile
    uint8_t tile = 0;
    fill_bkg_rect(0,0, 31,31, tile);
}

void draw_frame_text(char* line_1, char* line_2)
{
    set_bkg_1bpp_data(0, 'Z' - ' ' + 1, lankygitmono_tiles);
    xy_printf(1, 15, line_1);
    xy_printf(1, 16, line_2);
    set_bkg_1bpp_data('Z' - ' ' + 1, 9, sframe7_tiles);
    draw_frame(0, 14, 20, 4);
    SHOW_BKG;
}

void main(void)
{
    clear_bkg();
    draw_frame_text("HELLO!", "THERE...");
}
