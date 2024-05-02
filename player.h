#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"

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
coordinate Player_get_pos(Player *player);
void Player_set_pos(Player *player, coordinate pos);

// Player health
int Player_get_health(Player *player);
void Player_set_health(Player *player, int health);

#endif