#include <stdlib.h>
#include "utils.h"
#include "player.h"

Player *Player_new() {
    Player *player = calloc(1, sizeof(*player));

    player->position.x = POS_X;
    player->position.y = POS_Y;
    player->health = HEALTH;

    return player;
}

void Player_free(Player **player) {
    free(*player);
    player = NULL;
}

coordinate Player_get_pos(Player *player) {
    return player->position;
}

void Player_set_pos(Player *player, coordinate pos) {
    player->position = pos;
}

int Player_get_health(Player *player) {
    return player->health;
}

void Player_set_health(Player *player, int health) {
    player->health = health;
}