#ifndef Trap_H
#define Trap_H

#include <stdbool.h>
#include "player.h"
#include "utils.h"

typedef struct Trap
{
    coordinate position;
    int damage;
} Trap;

// Trap new and free
Trap *Trap_new();
void Trap_free(Trap **Trap);

coordinate Trap_get_pos(Trap *Trap);


#endif
