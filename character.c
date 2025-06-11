#pragma bank 0
#include "character.h"
#include "animate.h"
#include "character_store_owner.h"
#include "character_cheri.h"

void character_reset(void)
{
}
BANKREF_EXTERN(character_store_owner_ref)
BANKREF_EXTERN(character_cheri_ref)
void character_init(enum CharacterModel model, uint8_t tile_x, uint8_t tile_y)
{
    uint8_t previous_bank = CURRENT_BANK;
    struct MemoryAllocation allocation = {
        .bg_start = 70,
        .bg_pal_start = BKGF_CGB_PAL1,
        .sp_start = 0,
        .sp_pal_start = OAMF_CGB_PAL0,
    };
    switch (model)
    {
    case CHARACTER_MODEL_PLAYER:
        break;
    case CHARACTER_MODEL_STORE_OWNER:
        SWITCH_ROM(BANK(character_store_owner_ref));
        character_store_owner.init(allocation, tile_x, tile_y);
        break;
    case CHARACTER_MODEL_CHERI:
        SWITCH_ROM(BANK(character_cheri_ref));
        character_cheri.init(allocation, tile_x, tile_y);
        break;
    }
    SHOW_SPRITES;
    SWITCH_ROM(previous_bank);
}
void character_render(enum CharacterModel model, enum CharacterExpression expression)
{
    uint8_t previous_bank = CURRENT_BANK;
    switch (model)
    {
    case CHARACTER_MODEL_PLAYER:
        break;
    case CHARACTER_MODEL_STORE_OWNER:
        SWITCH_ROM(BANK(character_store_owner_ref));
        character_store_owner.render();
        break;
    case CHARACTER_MODEL_CHERI:
        SWITCH_ROM(BANK(character_cheri_ref));
        character_cheri.render();
        break;
    }
    SWITCH_ROM(previous_bank);
}