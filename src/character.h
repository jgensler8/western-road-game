#pragma once
#include "scene_common.h"

enum CharacterModel
{
    CHARACTER_MODEL_NONE,
    CHARACTER_MODEL_PLAYER,
    CHARACTER_MODEL_STORE_OWNER,
    CHARACTER_MODEL_CHERI,
    CHARACTER_MODEL_VERONICA,
    CHARACTER_MODEL_TRADER,
    CHARACTER_MODEL_BANDIT_A,
    CHARACTER_MODEL_COUNT,
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
    uint8_t bg_start;
    uint8_t bg_end;
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
void character_start_talking(enum CharacterModel model);
void character_stop_talking(enum CharacterModel model);
extern struct Character character_noop;