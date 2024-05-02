#ifndef PIRATE_H
#define PIRATE_H

#include <stdbool.h>

typedef struct Pirate {
    coordinate position;
    int damage;
} Pirate;

// Pirate new and free
Pirate *Pirate_new();
void Pirate_free(Pirate **Pirate); 

// Pirate mouvement & getter and setter
bool Pirate_isInLineOfSight(Pirate *pirate, coordinate player_pos);
void Pirate_moveTowardPlayer(Pirate *pirate, coordinate player_pos);
void Pirate_moveRandom(Pirate *pirate);

coordinate Pirate_get_pos(Pirate *Pirate);
void Pirate_set_pos(Pirate *Pirate, coordinate pos);

#endif