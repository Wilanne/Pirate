#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#include "utils.h"
#include "player.h"
#include "pirate.h"
#include "treasure.h"
#include "trap.h"
#include "map.h"

typedef struct Map Map;

typedef struct Game {
    GAME_STATUS status;
    Player *player;
    Pirate *pirates[PIRATE];
    Treasure *treasures[TREASURE];
    Trap *traps[TRAP];
    Map *map;
    bool isRunning;
} Game;

// Game new and free
Game *Game_new();
void Game_free(Game **game);

// Game functions
void Game_run(Game *game);
void Game_update(Game *game);
void Game_display(Game *game);

#endif