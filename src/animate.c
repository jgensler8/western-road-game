#pragma bank 0
#include "data.h"
#include <gbdk/platform.h>
#include "animate.h"
#include <gbdk/emu_debug.h>

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
                uint8_t metasprite_palette = args->palette_map[tile_offset];
                set_bkg_attribute_xy(x + x_s, y + y_s, args->palette_start + metasprite_palette);
            }
        }
    }
}

void animation_init_sprite_sheet(const struct SpriteSheet *sheet)
{
    set_sprite_data(sheet->sheet_start, sheet->tiles_len, sheet->tiles);
    palette_util_init_sp(sheet->palette_start, sheet->palettes_len, sheet->palettes);
}
void animation_update(struct SpriteAnimation *ani)
{
    uint8_t sp_i = ani->con->sp_index_start;
    for (uint8_t tile_y = 0; tile_y < ani->con->tile_height; tile_y++)
    {
        for (uint8_t tile_x = 0; tile_x < ani->con->tile_width; tile_x++)
        {
            set_sprite_tile(sp_i, ani->con->frame_tiles[ani->state.frame][tile_y][tile_x]);
            sp_i++;
        }
    }
    ani->state.frame_wait = ani->con->timings[ani->state.frame];
}
#define FRAME_TILE(x, y, frame, sheet) ((((y) * sheet.sheet_width_tiles) + (x)) + frame * sheet.sheet_frame_width_tiles)
void animation_move_sprite(struct SpriteAnimation *ani)
{
    uint8_t sp_i = ani->con->sp_index_start;
    for (uint8_t tile_y = 0; tile_y < ani->con->tile_height; tile_y++)
    {
        for (uint8_t tile_x = 0; tile_x < ani->con->tile_width; tile_x++)
        {
            move_sprite(sp_i, ani->con->screen_x + 8 * tile_x + ADJUST_X, ani->con->screen_y + 8 * tile_y + ADJUST_Y);
            sp_i++;
        }
    }
}
void animation_set_palette(struct SpriteAnimation *ani)
{
    uint8_t sp_i = ani->con->sp_index_start;
    for (uint8_t tile_y = 0; tile_y < ani->con->tile_height; tile_y++)
    {
        for (uint8_t tile_x = 0; tile_x < ani->con->tile_width; tile_x++)
        {
            // TODO: supporting changing palettes during the animation
            uint8_t source_frame = 0;
            uint8_t metasprite_tile = ani->con->frame_tiles[source_frame][tile_y][tile_x] - ani->con->sheet.sheet_start;
            // TODO: fix whatever alignment or pointer math wrong with default metasprites
            // uint8_t metasprite_palette = ani->con->sheet.metasprite[metasprite_tile].props & 0x07;
            uint8_t metasprite_palette = ani->con->sheet.palette_map[metasprite_tile];
            set_sprite_prop(sp_i, ani->con->sheet.palette_start + metasprite_palette);
            sp_i++;
        }
    }
}
void animation_init_sprite_animation(struct SpriteAnimation *ani)
{
    // move current sp
    animation_move_sprite(ani);
    animation_set_palette(ani);
    // animate current frame
    animation_update(ani);
}
static inline void animate(struct SpriteAnimation *ani)
{
    switch (ani->con->style)
    {
    case ANIMATION_STYLE_NONE:
        // already rendered in init
        return;
    case ANIMATION_STYLE_ONCE:
        if (ani->state.frame == ani->con->sheet.sheet_frames)
        {
            return;
        }
        ani->state.frame++;
        animation_update(ani);
        return;
    case ANIMATION_STYLE_LOOP:
        if (ani->state.frame == ani->con->sheet.sheet_frames)
        {
            ani->state.frame = 0;
        }
        else
        {
            ani->state.frame++;
        }
        animation_update(ani);
        return;
    case ANIMATION_STYLE_PING_PONG:
        // update state
        if (ani->state.frame == 0)
        {
            ani->state.direction = ANIMATION_DIRECTION_FORWARD;
        }
        else if (ani->state.frame == ani->con->sheet.sheet_frames - 1)
        {
            ani->state.direction = ANIMATION_DIRECTION_BACKWARD;
        }
        // move frame
        if (ani->state.direction == ANIMATION_DIRECTION_FORWARD)
        {
            ani->state.frame++;
        }
        else if (ani->state.direction == ANIMATION_DIRECTION_BACKWARD)
        {
            ani->state.frame--;
        }
        // then render
        animation_update(ani);
        return;
    }
}
void maybe_animate(struct SpriteAnimation *ani)
{
    if (ani->state.frame_wait > 0)
    {
        ani->state.frame_wait--;
    }
    else
    {
        // EMU_PROFILE_BEGIN("ani_s:%TOTALCLKS%:")
        animate(ani);
        // EMU_PROFILE_END("ani_e:%TOTALCLKS%:")
    }
}
void animation_show(struct SpriteAnimation *ani)
{
    animation_move_sprite(ani);
}
void animation_hide(struct SpriteAnimation *ani)
{
    uint8_t num_sprites = ani->con->tile_width * ani->con->tile_height;
    for (uint8_t sp_i = ani->con->sp_index_start; sp_i < ani->con->sp_index_start + num_sprites; sp_i++)
    {
        hide_sprite(sp_i);
    }
}
void animation_hide_range(uint8_t start, uint8_t end)
{
    for (uint8_t sp_i = start; sp_i < end; sp_i++)
    {
        hide_sprite(sp_i);
    }
}
void animation_hide_all(void)
{
    animation_hide_range(0, 32);
}

// Helper macro to extract R, G, B components (5 bits each)
#define GET_R(color) ((color) & 0x1F)
#define GET_G(color) (((color) >> 5) & 0x1F)
#define GET_B(color) (((color) >> 10) & 0x1F)

// Helper macro to combine R, G, B components into a 15-bit color
#define MAKE_COLOR(r, g, b) (((b) << 10) | ((g) << 5) | (r))

// Number of fade steps (0 to 3 for a total of 4 steps)
#define FADE_SWAP_STEPS 4

// The core fade function
// 'step' goes from 0 (normal) to FADE_SWAP_STEPS - 1 (all black)
static palette_color_t fade_color_to_black(palette_color_t original_color, uint8_t step)
{
    if (step >= FADE_SWAP_STEPS - 1)
    {             // Last step is always black
        return 0; // Black
    }
    if (step == 0)
    { // First step is original color
        return original_color;
    }

    uint8_t r = GET_R(original_color);
    uint8_t g = GET_G(original_color);
    uint8_t b = GET_B(original_color);

    // Calculate fade factor.
    // For 4 steps (0, 1, 2, 3), total "active" fade steps are 3 (from 0 to 2)
    // Step 0: no change
    // Step 1: (FADE_SWAP_STEPS - 1 - 1) / (FADE_SWAP_STEPS - 1) = 2/3 brightness
    // Step 2: (FADE_SWAP_STEPS - 1 - 2) / (FADE_SWAP_STEPS - 1) = 1/3 brightness
    // Step 3: 0 brightness (handled by if statement above)

    // Using integer division, this can be tricky.
    // A more robust way is to use a lookup table for multipliers or careful integer math.
    // Example: (original_component * (FADE_SWAP_STEPS - 1 - step)) / (FADE_SWAP_STEPS - 1)
    // Let's call FADE_MAX_VAL = FADE_SWAP_STEPS - 1 (which is 3 for 4 steps)
    // new_comp = (original_comp * (FADE_MAX_VAL - step)) / FADE_MAX_VAL;

    uint8_t new_r, new_g, new_b;
    uint8_t fade_scale = FADE_SWAP_STEPS - 1 - step; // 3, 2, 1 for steps 0, 1, 2 respectively

    // Perform multiplication first to retain precision before division
    new_r = (r * fade_scale) / (FADE_SWAP_STEPS - 1);
    new_g = (g * fade_scale) / (FADE_SWAP_STEPS - 1);
    new_b = (b * fade_scale) / (FADE_SWAP_STEPS - 1);

    return MAKE_COLOR(new_r, new_g, new_b);
}

static uint16_t palette_last_fade = 254;
static uint16_t bg_pal_offset = 0;
static uint16_t sp_pal_offset = 0;
#define PALETTE_DEFAULT_PAL { \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
    RGB8(0, 0, 0),            \
}
static palette_color_t bkg_pal_cache[4 * 8] = PALETTE_DEFAULT_PAL;
static palette_color_t sp_pal_cache[4 * 8] = PALETTE_DEFAULT_PAL;
static palette_color_t bkg_pal_cache_f1[4 * 8] = PALETTE_DEFAULT_PAL;
static palette_color_t sp_pal_cache_f1[4 * 8] = PALETTE_DEFAULT_PAL;
static palette_color_t bkg_pal_cache_f2[4 * 8] = PALETTE_DEFAULT_PAL;
static palette_color_t sp_pal_cache_f2[4 * 8] = PALETTE_DEFAULT_PAL;
static palette_color_t bkg_pal_cache_f3[4 * 8] = PALETTE_DEFAULT_PAL;
static palette_color_t sp_pal_cache_f3[4 * 8] = PALETTE_DEFAULT_PAL;
void palette_util_reset_bkg_palettes(void)
{
    for (uint8_t y = 0; y < 18; y++)
    {
        for (uint8_t x = 0; x < 20; x++)
        {
            set_bkg_attribute_xy(x, y, BKGF_CGB_PAL0);
        }
    }
}
void palette_util_reset(void)
{
    bg_pal_offset = 0;
    sp_pal_offset = 0;
    const palette_color_t default_palettes[4] = {
        RGB8(255, 255, 255), RGB8(0, 0, 0), RGB8(0, 0, 0), RGB8(0, 0, 0)};
    palette_util_init_bkg(1, default_palettes);
    palette_util_reset_bkg_palettes();
}
static void palette_copy(palette_color_t *dest, const palette_color_t *src, uint8_t palette_count, uint8_t step)
{
    for (uint8_t i = 0; i < palette_count * 4; i++)
    {
        dest[i] = fade_color_to_black(src[i], step);
    }
}
uint8_t palette_util_init_bkg(uint8_t palette_count, const palette_color_t *palettes)
{
    uint8_t start = bg_pal_offset;
    palette_copy(&bkg_pal_cache[bg_pal_offset * 4], palettes, palette_count, 0);
    palette_copy(&bkg_pal_cache_f1[bg_pal_offset * 4], palettes, palette_count, 1);
    palette_copy(&bkg_pal_cache_f2[bg_pal_offset * 4], palettes, palette_count, 2);
    bg_pal_offset += palette_count;
    return start;
}
void palette_util_init_sp(const uint8_t palette_start, const uint8_t palette_count, const palette_color_t *palettes)
{
    palette_copy(&sp_pal_cache[palette_start * 4], palettes, palette_count, 0);
    palette_copy(&sp_pal_cache_f1[palette_start * 4], palettes, palette_count, 1);
    palette_copy(&sp_pal_cache_f2[palette_start * 4], palettes, palette_count, 2);
}
static inline void pallete_util_fade(struct SceneRenderOptions *options)
{
    switch (options->fade)
    {
    default:
    case 0:
        set_bkg_palette(BKGF_CGB_PAL0, 8, bkg_pal_cache);
        set_sprite_palette(OAMF_CGB_PAL0, 8, sp_pal_cache);
        break;
    case 1:
        set_bkg_palette(BKGF_CGB_PAL0, 8, bkg_pal_cache_f1);
        set_sprite_palette(OAMF_CGB_PAL0, 8, sp_pal_cache_f1);
        break;
    case 2:
        set_bkg_palette(BKGF_CGB_PAL0, 8, bkg_pal_cache_f2);
        set_sprite_palette(OAMF_CGB_PAL0, 8, sp_pal_cache_f2);
        break;
    case 3:
        set_bkg_palette(BKGF_CGB_PAL0, 8, bkg_pal_cache_f3);
        set_sprite_palette(OAMF_CGB_PAL0, 8, sp_pal_cache_f3);
        break;
    }
}
void palette_util_maybe_fade(struct SceneRenderOptions *options)
{
    if (palette_last_fade != options->fade)
    {
        pallete_util_fade(options);
    }
    palette_last_fade = options->fade;
}