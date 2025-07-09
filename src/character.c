#pragma bank 0
#include "character.h"
#include "animate.h"
#include "character_store_owner.h"
#include "character_cheri.h"
#include "character_veronica.h"

void character_reset(void)
{
}
BANKREF_EXTERN(character_store_owner_ref)
BANKREF_EXTERN(character_cheri_ref)
BANKREF_EXTERN(character_veronica_ref)
struct BankedCharacter
{
    const struct Character *character;
    const uint32_t bank;
};
struct BankedCharacter bankedCharacters[CHARACTER_MODEL_COUNT] = {
    {.character = &character_noop, .bank = 1},
    {.character = &character_noop, .bank = 1},
    {.character = &character_veronica, .bank = BANK(character_veronica_ref)},
    {.character = &character_store_owner, .bank = BANK(character_store_owner_ref)},
    {.character = &character_cheri, .bank = BANK(character_cheri_ref)},
    {.character = &character_veronica, .bank = BANK(character_veronica_ref)},
};
void character_init(enum CharacterModel model, uint8_t tile_x, uint8_t tile_y)
{
    uint8_t previous_bank = CURRENT_BANK;
    struct MemoryAllocation allocation = {
        .bg_start = 70,
        .sp_start = 0,
    };
    SWITCH_ROM(bankedCharacters[model].bank);
    bankedCharacters[model].character->init(allocation, tile_x, tile_y);
    SWITCH_ROM(previous_bank);
}
void character_render(enum CharacterModel model, enum CharacterExpression expression)
{
    uint8_t previous_bank = CURRENT_BANK;
    SWITCH_ROM(bankedCharacters[model].bank);
    bankedCharacters[model].character->render();
    SWITCH_ROM(previous_bank);
}
void character_start_talking(enum CharacterModel model)
{
    uint8_t previous_bank = CURRENT_BANK;
    SWITCH_ROM(bankedCharacters[model].bank);
    bankedCharacters[model].character->start_talking();
    SWITCH_ROM(previous_bank);
}
void character_stop_talking(enum CharacterModel model)
{
    uint8_t previous_bank = CURRENT_BANK;
    SWITCH_ROM(bankedCharacters[model].bank);
    bankedCharacters[model].character->stop_talking();
    SWITCH_ROM(previous_bank);
}

static struct MemoryAllocation character_noop_init(struct MemoryAllocation start, uint8_t tile_x, uint8_t tile_y)
{
    return start;
}
static void character_noop_set_expression(enum CharacterExpression expression) {}
static void character_noop_start_talking(void) {}
static void character_noop_stop_talking(void) {}
static void character_noop_render(void) {}
struct Character character_noop = {
    .init = character_noop_init,
    .set_expression = character_noop_set_expression,
    .start_talking = character_noop_start_talking,
    .stop_talking = character_noop_stop_talking,
    .render = character_noop_render,
};