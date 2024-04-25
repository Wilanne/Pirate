#include <stdlib.h>
#include <time.h>

#include "treasure.h"

Treasure *Treasure_new(int lines, int columns) {
    Treasure *treasure = calloc(1, sizeof(*treasure));
    
    //srand(time(NULL));
    treasure->position.x = (rand() % (lines - 1)) + 1;
    treasure->position.y = (rand() % (columns - 1)) + 1;

    return treasure;
}

void Treasure_free(Treasure **treasure) {
    free(*treasure);
}

coordinate Treasure_get_pos(Treasure *treasure) {
    return treasure->position;
}