#pragma bank 0
#include "items.h"
#include "text.h"

uint8_t item_price(enum Item item)
{
    switch (item)
    {
    case ITEM_OVERALLS:
        return 1;
    case ITEM_BAG:
        return 2;
    case ITEM_CRYSTAL:
        return 3;
    default:
        return 0;
    }
}

char* item_name(enum Item item)
{
    switch (item)
    {
    case ITEM_OVERALLS:
        return "OVERALLS";
    case ITEM_BAG:
        return "BAG";
    case ITEM_CRYSTAL:
        return "CRYSTAL";
    case ITEM_BLUE_PACKAGE:
        return "BLUE PACKAGE";
    default:
        return "NONE";
    }
}

const char *item_details[ITEM_COUNT][2] = {
    {EMPTY, EMPTY},
    {"CLASSIC LOOK", EMPTY},
    {"A SIMPLE BAG", EMPTY},
    {"+1 KNOWLEDGE", "PER STEP"},
    {"DELIVERY ITEM", "FROM VERONICA"},
};