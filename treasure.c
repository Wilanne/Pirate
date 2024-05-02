#include <stdlib.h>
#include "utils.h"
#include "treasure.h"

Treasure *Treasure_new(int lines, int columns) {
    Treasure *treasure = calloc(1, sizeof(*treasure));

    return treasure;
}

void Treasure_free(Treasure **treasure) {
    free(*treasure);
}

coordinate Treasure_get_pos(Treasure *treasure) {
    return treasure->position;
}

void Treasure_set_pos(Treasure *treasure, coordinate pos) {
    treasure->position = pos;
}