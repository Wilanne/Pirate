#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "utils.h"

// Maybee to be put in the function contructor ??
#define POS_X 0
#define POS_Y 0
#define HEALTH 3

// typedef enum PLAYER_STATUS{
//     ALIVE,
//     DEAD, 
//     ON_TREASURE,
//     ON_TRAP
// } PLAYER_STATUS;

typedef struct Player
{
    coordinate position;
    int health;
    int score;
} Player;

// Player new and free
Player *Player_new();
void Player_free(Player **player);

// Player mouvement
void Player_mouvement(Player *player, char direction, GAME_STATUS *status);
coordinate Player_get_pos(Player *player);

// Player health
int Player_get_health(Player *player);
void Player_set_health(Player *player, int health);

#endif