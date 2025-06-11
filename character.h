#pragma once
#include "scene_common.h"

enum CharacterModel
{
    CHARACTER_MODEL_PLAYER,
    CHARACTER_MODEL_STORE_OWNER,
    CHARACTER_MODEL_CHERI,
};

enum CharacterExpression
{
    CHARACTER_EXPRESSION_DEFAULT,
    CHARACTER_EXPRESSION_MAD,
    CHARACTER_EXPRESSION_QUESTION,
    CHARACTER_EXPRESSION_LAUGH,
};

struct MemoryAllocation
{
    uint8_t sp_start;
    uint8_t sp_end;
    uint8_t sp_pal_start;
    uint8_t sp_pal_end;
    uint8_t bg_start;
    uint8_t bg_end;
    uint8_t bg_pal_start;
    uint8_t bg_pal_end;
};

struct Character
{
    struct MemoryAllocation (*init)(struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y);
    void (*set_expression)(enum CharacterExpression expression);
    void (*start_talking)(void);
    void (*stop_talking)(void);
    void (*render)(void);
};

void character_reset(void);
void character_init(enum CharacterModel model, uint8_t tile_x, uint8_t tile_y);
void character_render(enum CharacterModel model, enum CharacterExpression expression);