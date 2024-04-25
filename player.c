#include "player.h"
#include "map.h"

Player *Player_new() {
    //Player *player = malloc(sizeof(Player));
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

void Player_mouvement(Player *player, char direction, GAME_STATUS *status) {
    *status = Map_CheckAllConditions(player, direction);
    //if (player->health <= 0) {*status = GAME_LOOSE;}
}

coordinate Player_get_pos(Player *player) {
    return player->position;
}

int Player_get_health(Player *player) {
    return player->health;
}

void Player_set_health(Player *player, int health) {
    player->health = health;
}