#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include "utils.h"
#include "game.h"

typedef struct Game Game;

typedef struct Map {
    char **map_grid;
    int lines;
    int columns;
} Map;

// General map functions
Map *Map_new(Game *game);
void Map_free(Map **map);

// Draw the map
void Map_drawMap(Map *map);

// Set and get character on map
void Map_addCharacterOnMap(Map *map, Game *game);
char Map_getCharacterOnMap(Map *map, int x, int y);
void Map_setCharacterOnMap(Map *map, int x, int y, char c);

// Check if the position is out of bound
void Map_handleMovement(Game *game, char direction);
bool Map_checkIfInBound(int x, int y);
bool Map_checkIfOnTreasure(Game *game);
bool Map_checkIfOnTrap(Game *game);

#endif
