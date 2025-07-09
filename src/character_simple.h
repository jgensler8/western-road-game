#include "character.h"

struct CharacterSimpleConst
{
    // bg
    uint8_t bg_palette_count;
    const palette_color_t *bg_palettes;
    uint8_t bg_tile_count;
    uint8_t *bg_tiles;
    uint8_t *bg_palette_map;

    // sp
    struct SpriteAnimation *left_eye;
    struct SpriteAnimation *right_eye;
    struct SpriteAnimation *mouth_passive;
    struct SpriteAnimation *mouth_talking;
};
struct CharacterSimpleState
{
    uint8_t talking;
    uint8_t talking_changed;
};
struct CharacterSimple
{
    const struct CharacterSimpleConst *con;
    struct CharacterSimpleState state;
};

struct MemoryAllocation cs_init(struct CharacterSimple *self, struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y);
void cs_set_expression(struct CharacterSimple *self, enum CharacterExpression expression);
void cs_start_talking(struct CharacterSimple *self);
void cs_stop_talking(struct CharacterSimple *self);
void cs_render(struct CharacterSimple *self);