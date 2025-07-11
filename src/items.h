#pragma once
#include "data.h"

uint8_t item_price(enum Item item);
char *item_name(enum Item item);
extern const char *item_details[ITEM_COUNT][2];