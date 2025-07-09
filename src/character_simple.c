#pragma bank 0
#include "character_simple.h"

struct MemoryAllocation cs_init(struct CharacterSimple *cs, struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y)
{
    // bg
    uint8_t pal_start = palette_util_init_bkg(cs->con->bg_palette_count, cs->con->bg_palettes);
    set_bkg_data(start.bg_start, cs->con->bg_tile_count, cs->con->bg_tiles);
    struct PaletteArgs pargs = {
        .palette_map = cs->con->bg_palette_map,
        .palette_start = pal_start,
    };
    set_bkg_offset(tile_x, tile_y, 8, 8, start.bg_start, &pargs);
    // sp
    animation_init_sprite_sheet(&cs->con->left_eye->con->sheet);
    animation_init_sprite_animation(&cs->con->left_eye);
    animation_init_sprite_animation(&cs->con->right_eye);
    animation_init_sprite_animation(&cs->con->mouth_passive);
    animation_init_sprite_animation(&cs->con->mouth_talking);
    cs->state.talking = 0;
    // TODO: either build custom funcs or hardcode
    struct MemoryAllocation end = {
        .bg_end = start.bg_start + 6,
    };
    return end;
}
void cs_set_expression(struct CharacterSimple *cs, enum CharacterExpression expression)
{
}
void cs_start_talking(struct CharacterSimple *cs)
{
    cs->state.talking = 1;
    cs->state.talking_changed = 1;
}
void cs_stop_talking(struct CharacterSimple *cs)
{
    cs->state.talking = 0;
    cs->state.talking_changed = 1;
}
void cs_render(struct CharacterSimple *cs)
{
    maybe_animate(cs->con->left_eye);
    maybe_animate(cs->con->right_eye);
    if (cs->state.talking)
    {
        maybe_animate(cs->con->mouth_talking);
        if (cs->state.talking_changed)
        {
            animation_show(cs->con->mouth_talking);
            animation_hide(cs->con->mouth_passive);
        }
    }
    else
    {
        maybe_animate(cs->con->mouth_passive);
        if (cs->state.talking_changed)
        {
            animation_show(cs->con->mouth_passive);
            animation_hide(cs->con->mouth_talking);
        }
    }
    cs->state.talking_changed = 0;
}
