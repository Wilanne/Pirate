#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "pirate.h"

Pirate *Pirate_new() {
    Pirate *pirate = calloc(1, sizeof(*pirate));
    pirate->position.x = (rand() % (LINES - 1)) + 1;
    pirate->position.y = (rand() % (COLUMNS - 1)) + 1;

    return pirate;
}

void Pirate_free(Pirate **Pirate) {
    free(*Pirate);
    Pirate = NULL;
}

bool Pirate_isInLineOfSight(Pirate *pirate, coordinate player_pos) {
    if (pirate->position.x == player_pos.x || pirate->position.y == player_pos.y) {
        return true;
    }
    return false;
}

void Pirate_moveTowardPlayer(Pirate *pirate, coordinate player_pos) {
    if (pirate->position.x < player_pos.x) {
        pirate->position.x++;
    } else if (pirate->position.x > player_pos.x) {
        pirate->position.x--;
    }

    if (pirate->position.y < player_pos.y) {
        pirate->position.y++;
    } else if (pirate->position.y > player_pos.y) {
        pirate->position.y--;
    }
}

void Pirate_moveRandom(Pirate *pirate) {
    int direction = rand() % 4;    

    switch (direction) {
        case 0:
            if (pirate->position.x > 0) {
                pirate->position.x--;
            }
            break;
        case 1:
            if (pirate->position.x < LINES - 1) {
                pirate->position.x++;
            }
            break;
        case 2:
            if (pirate->position.y > 0) {
                pirate->position.y--;
            }
            break;
        case 3:
            if (pirate->position.y < COLUMNS - 1) {
                pirate->position.y++;
            }
            break;
    }

    // What is pirate teleport to an alredy placed character ? 
}


coordinate Pirate_get_pos(Pirate *Pirate) {
    return Pirate->position;
}

void Pirate_set_pos(Pirate *Pirate, coordinate pos) {
    Pirate->position = pos;
}

