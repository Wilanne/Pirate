#include <stdio.h>
#include <stdint.h>

#include "map.h"
#include "player.h"
#include "treasure.h"
#include "trap.h"

static uint8_t nb_ligne;
static uint8_t nb_colonne;

char **map_grid;

static Treasure *treasures[TREASURE];
static Trap *traps[TRAP];

void Map_initaliazeMap(Player *player, uint8_t lines, uint8_t columns) {

    // Set the size of the map
    nb_ligne = lines;
    nb_colonne = columns;

    // Memory Allocation
    map_grid = (char **)malloc(lines * sizeof(char *));
    for (int i = 0; i < lines; i++) {
        map_grid[i] = (char *)malloc(columns * sizeof(char));
    }

    // Array filling with empty spaces
    for(int i=0; i< lines; i++)
    {
        for(int j=0; j<columns; j++)
        {
            map_grid[i][j] = ' ';
        }
    }
    map_grid[player->position.x][player->position.y] = 'J';

    // Add a treasure
    for (int i = 0; i < TREASURE; i++) {
        treasures[i] = Treasure_new(lines,columns);
        //printf("%p\n", treasure);
        map_grid[treasures[i]->position.x][treasures[i]->position.y] = 'T';
    }
    
    // Add a trap
    for (int i = 0; i < TRAP; i++) {
        traps[i] = Trap_new(lines,columns);
        //printf("%p\n", treasure);
        map_grid[traps[i]->position.x][traps[i]->position.y] = ' ';
    }
}

void Map_free() {
    for (int i = 0; i < nb_ligne; i++) {
        free(map_grid[i]);
    }
    free(map_grid);

    for (int i = 0; i < TREASURE; i++) {
        Treasure_free(&treasures[i]);
        treasures[i] = NULL;
    }

    for (int i = 0; i < TRAP; i++) {
        Trap_free(&traps[i]);
        traps[i] = NULL;
    }
}

void Map_drawMap()
{
    for(int j= 0; j<nb_ligne; j++)
    {
        //ligne de delimitation
        for(int i=0; i<nb_colonne; i++)
        {
            printf("+---");
        }
        printf("+\n");
        //ligne de contenu
        for(int i=0; i<nb_colonne; i++)
        {
            printf("| ");
            printf("%c",map_grid[j][i]); //contenu
            printf(" ");
        }
        printf("|\n");
    }
    //ligne de delimitation
    for(int i=0; i<nb_colonne; i++)
    {
        printf("+---");
    }
    printf("+\n");
}

char Map_getCharacterOnMap(int x, int y) {
    return map_grid[x][y];
}
void Map_setCharacterOnMap(int x, int y, char c) {
    map_grid[x][y] = c;
}

GAME_STATUS Map_CheckAllConditions(Player *player, char direction) {
    GAME_STATUS status;

    //coordinate player_pos = Player_get_pos(player);

    int new_x = player->position.x;
    int new_y = player->position.y;

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
        Map_setCharacterOnMap(player->position.x, player->position.y, ' ');
        player->position.x = new_x;
        player->position.y = new_y;
        Map_setCharacterOnMap(player->position.x, player->position.y, 'J');
        status = CAN_MOVE;
    } else {status = CANNOT_MOVE;}

    if (Map_checkIfOnTreasure(player) == 0) {
        status = GAME_WIN;
    }

    if (Map_checkIfOnTrap(player) == 0) {
        status = GAME_LOOSE;
    }
    
    return status;
}

bool Map_checkIfInBound(int x, int y) {
    if (x < 0 || x >= nb_ligne || y < 0 || y >= nb_colonne) {
        return false;
    }
    else {return true;}
}

bool Map_checkIfOnTreasure(Player *player) {
    int ret = 1;
    for (int i = 0; i < TREASURE; i++) {
        coordinate treasure_pos = Treasure_get_pos(treasures[i]);

        if (player->position.x == treasure_pos.x && player->position.y == treasure_pos.y) {
            player->score++;
        }
        if (player->score == TREASURE) {
            ret = 0;
        }
    }
    return ret;
}

bool Map_checkIfOnTrap(Player *player) {
    int ret = 1;
    for (int i = 0; i < TRAP; i++) {
        coordinate trap_pos = Trap_get_pos(traps[i]);

        if (player->position.x == trap_pos.x && player->position.y == trap_pos.y) {
            player->health -= traps[i]->damage;
        }
        if (player->health <= 0) {
            ret = 0;
        }
    }
    return ret;
}

void printdebug(Player *player) {
    printf("Player position: %d, %d\n", player->position.x, player->position.y);
    printf("Player health: %d\n", player->health);
    printf("Player score: %d\n", player->score);
    
    for (int i = 0; i < TREASURE; i++) {
        printf("Treasure position: %d, %d\n", treasures[i]->position.x, treasures[i]->position.y);
    }

    for (int i = 0; i < TRAP; i++) {
        printf("Trap position: %d, %d\n", traps[i]->position.x, traps[i]->position.y);
    }

    // for (int i = 0; i < TRAP; i++) {
    //     printf("Trap damages: %d\n", traps[i]->damage);
    // }
}