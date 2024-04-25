#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "player.h"

// General map functions
void Map_initaliazeMap(Player *player, uint8_t lines, uint8_t columns);
void Map_free();

// Draw the map
void Map_drawMap();

// Set and get character on map
char Map_getCharacterOnMap(int x, int y);
void Map_setCharacterOnMap(int x, int y, char c);

// Check if the position is out of bound
GAME_STATUS Map_CheckAllConditions(Player *player, char direction);
bool Map_checkIfInBound(int x, int y/*player ? */);
bool Map_checkIfOnTreasure(Player *player);
bool Map_checkIfOnTrap(Player *player);

void printdebug(Player *player);

#endif
