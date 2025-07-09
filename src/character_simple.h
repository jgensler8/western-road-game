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

#define CHARACTER_SIMPLE_TEMPLATE(name)                                                                \
    static struct CharacterSimple character_##name##_simple = {                                        \
        .con = &character_##name##_simple_const,                                                       \
        .state = {0},                                                                                  \
    };                                                                                                 \
    static struct MemoryAllocation init(struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y) \
    {                                                                                                  \
        struct MemoryAllocation ret = cs_init(&character_##name##_simple, start, tile_x, tile_y);      \
        return ret;                                                                                    \
    }                                                                                                  \
    static void set_expression(enum CharacterExpression expression)                                    \
    {                                                                                                  \
        cs_set_expression(&character_##name##_simple, expression);                                     \
    }                                                                                                  \
    static void start_talking(void)                                                                    \
    {                                                                                                  \
        cs_start_talking(&character_##name##_simple);                                                  \
    }                                                                                                  \
    static void stop_talking(void)                                                                     \
    {                                                                                                  \
        cs_stop_talking(&character_##name##_simple);                                                   \
    }                                                                                                  \
    static void render(void)                                                                           \
    {                                                                                                  \
        cs_render(&character_##name##_simple);                                                         \
    }                                                                                                  \
    BANKREF(character_##name##_ref)                                                                    \
    struct Character character_##name = {                                                              \
        .init = init,                                                                                  \
        .set_expression = set_expression,                                                              \
        .start_talking = start_talking,                                                                \
        .stop_talking = stop_talking,                                                                  \
        .render = render,                                                                              \
    };
