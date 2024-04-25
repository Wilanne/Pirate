#ifndef TREASURE_H
#define TREASURE_H

#include <stdbool.h>
#include "player.h"
#include "utils.h"

typedef struct Treasure
{
    coordinate position;
    //bool is_taken;
    //int value;
} Treasure;

// Player new and free
Treasure *Treasure_new();
void Treasure_free(Treasure **Treasure);

coordinate Treasure_get_pos(Treasure *Treasure);

#endif
