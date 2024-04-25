#include <stdlib.h>

#include "trap.h"

Trap *Trap_new(int lines, int columns) {
    Trap *Trap = calloc(1, sizeof(*Trap));
    
    //srand(time(NULL));
    Trap->position.x = (rand() % (lines - 1)) + 1;
    Trap->position.y = (rand() % (columns - 1)) + 1;

    //Trap->damage = (rand() % 3) + 1;
    Trap->damage = 1;

    return Trap;
}

void Trap_free(Trap **Trap) {
    free(*Trap);
}

coordinate Trap_get_pos(Trap *Trap) {
    return Trap->position;
}