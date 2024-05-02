#include <stdlib.h>
#include "utils.h"
#include "trap.h"

Trap *Trap_new() {
    Trap *Trap = calloc(1, sizeof(*Trap));
 
    Trap->damage = 1;

    return Trap;
}

void Trap_free(Trap **Trap) {
    free(*Trap);
}

coordinate Trap_get_pos(Trap *Trap) {
    return Trap->position;
}

void Trap_set_pos(Trap *Trap, coordinate pos) {
    Trap->position = pos;
}