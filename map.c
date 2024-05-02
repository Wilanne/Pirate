#include <stdio.h>
#include <stdint.h>

#include "map.h"
#include "player.h"
#include "pirate.h"
#include "treasure.h"
#include "trap.h"

Map *Map_new(Game *game) {
    // Memory Allocation
    Map *map = calloc(1, sizeof(Map));

    map->lines = LINES;
    map->columns = COLUMNS;

    // Memory Allocation for the map_grid
    map->map_grid = (char **)malloc(map->lines * sizeof(char *));
    for (int i = 0; i < map->lines; i++) {
        map->map_grid[i] = (char *)malloc(map->columns * sizeof(char));
    }

    // Array filling with empty spaces
    for(int i=0; i< map->lines; i++)
    {
        for(int j=0; j<map->columns; j++)
        {
            map->map_grid[i][j] = ' ';
        }
    }
    // Place a player on the map
    map->map_grid[game->player->position.x][game->player->position.y] = 'J';

    // Randomly place all the elements on the map
    Map_addCharacterOnMap(map, game);

    return map;
}

void Map_addCharacterOnMap(Map *map, Game *game) {

    for (int i = 0; i < TREASURE; i++) {
        coordinate treasure_pos;
        do {
            treasure_pos = (coordinate){rand() % LINES, rand() % COLUMNS};
        } while (Map_getCharacterOnMap(map, treasure_pos.x, treasure_pos.y) != ' ');
        Treasure_set_pos(game->treasures[i], treasure_pos);
        map->map_grid[treasure_pos.x][treasure_pos.y] = 'T';
    }

    for (int i = 0; i < TRAP; i++) {
        coordinate trap_pos;
        do {
            trap_pos = (coordinate){rand() % LINES, rand() % COLUMNS};
        } while (Map_getCharacterOnMap(map, trap_pos.x, trap_pos.y) != ' ');
        Trap_set_pos(game->traps[i], trap_pos);
        map->map_grid[trap_pos.x][trap_pos.y] = 'X';
    }

    for (int i = 0; i < PIRATE; i++) {
        coordinate pirate_pos;
        do {
            pirate_pos = (coordinate){rand() % LINES, rand() % COLUMNS};
        } while (Map_getCharacterOnMap(map, pirate_pos.x, pirate_pos.y) != ' ');
        Pirate_set_pos(game->pirates[i], pirate_pos);
        map->map_grid[pirate_pos.x][pirate_pos.y] = 'P';
    }
}

void Map_free(Map **map) {
    if (map == NULL || *map == NULL) {
        return; // Nothing to free
    }

    // Free the memory for map_grid
    if ((*map)->map_grid != NULL) {
        for (int i = 0; i < (*map)->lines; ++i) {
            free((*map)->map_grid[i]);
        }
        free((*map)->map_grid);
    }

    // Free the memory for the Map structure itself
    free(*map);
    *map = NULL;
}

void Map_drawMap(Map *map) {
    for(int j= 0; j<map->lines; j++)
    {
        // Delimitation line
        for(int i=0; i<map->columns; i++)
        {
            printf("+---");
        }
        printf("+\n");

        // Content
        for(int i=0; i<map->columns; i++)
        {
            printf("| ");
            printf("%c",map->map_grid[j][i]); // Character
            printf(" ");
        }
        printf("|\n");
    }
    // Delimitation line
    for(int i=0; i<map->columns; i++)
    {
        printf("+---");
    }
    printf("+\n");
}

char Map_getCharacterOnMap(Map *map, int x, int y) {
    return map->map_grid[x][y];
}

void Map_setCharacterOnMap(Map *map, int x, int y, char c) {
    map->map_grid[x][y] = c;
}

bool Map_checkIfInBound(int x, int y) {
    if (x < 0 || x >= LINES || y < 0 || y >= COLUMNS) {
        return false;
    }
    else {return true;}
}

bool Map_checkIfOnTreasure(Game *game) {
    int ret = 1;
    for (int i = 0; i < TREASURE; i++) {
        coordinate treasure_pos = Treasure_get_pos(game->treasures[i]);

        if (game->player->position.x == treasure_pos.x && game->player->position.y == treasure_pos.y) {
            game->player->score++;
        }
        if (game->player->score == TREASURE) {
            ret = 0;
        }
    }
    return ret;
}

bool Map_checkIfOnTrap(Game *game) {
    int ret = 1;
    for (int i = 0; i < TRAP; i++) {
        coordinate trap_pos = Trap_get_pos(game->traps[i]);

        if (game->player->position.x == trap_pos.x && game->player->position.y == trap_pos.y) {
            game->player->health -= game->traps[i]->damage;
        }
        if (game->player->health <= 0) {
            ret = 0;
        }
    }
    return ret;
}

void Map_handleMovement(Game *game, char direction) {

    int new_x = game->player->position.x;
    int new_y = game->player->position.y;

    switch(direction) {
        case 'w':
            new_x--;
            break;

        case 's':
            new_x++;
            break;

        case 'a':
            new_y--;
            break;

        case 'd':
            new_y++;
            break;
    }

    if (Map_checkIfInBound(new_x, new_y)) {
        Map_setCharacterOnMap(game->map, game->player->position.x, game->player->position.y, ' ');
        game->player->position.x = new_x;
        game->player->position.y = new_y;
        Map_setCharacterOnMap(game->map, game->player->position.x, game->player->position.y, 'J');
        game->status = CAN_MOVE;
    } else {game->status = CANNOT_MOVE;}

    if (Map_checkIfOnTreasure(game) == 0) {
        game->status = GAME_WIN;
    }

    if (Map_checkIfOnTrap(game) == 0) {
        game->status = GAME_LOOSE;
    }

    for (int i = 0; i < PIRATE; i++) {
        Map_setCharacterOnMap(game->map, game->pirates[i]->position.x, game->pirates[i]->position.y, ' ');
        if (Pirate_isInLineOfSight(game->pirates[i], game->player->position)) {
            Pirate_moveTowardPlayer(game->pirates[i], game->player->position);
        } else {
            Pirate_moveRandom(game->pirates[i]);
        }
        // Check if the new position of the pirate is already occupied by another character
        if (Map_getCharacterOnMap(game->map, game->pirates[i]->position.x+1, game->pirates[i]->position.y+1) == ' ') {
            Map_setCharacterOnMap(game->map, game->pirates[i]->position.x, game->pirates[i]->position.y, 'P');
        } else {
            // If the new position is occupied, find a new random position for the pirate
            coordinate new_pos;
            do {
                new_pos = (coordinate){rand() % LINES, rand() % COLUMNS};
            } while (Map_getCharacterOnMap(game->map, new_pos.x, new_pos.y) != ' ');
            Pirate_set_pos(game->pirates[i], new_pos);
            Map_setCharacterOnMap(game->map, new_pos.x, new_pos.y, 'P');
        }
    }

}