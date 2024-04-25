// Last update: 20/03/2024 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Given includes
#include "getch.h"

// User includes
#include "utils.h"
#include "map.h"
#include "player.h"

int main()
{
    srand(time(NULL));

    char characterFromGetch;
    int isFinished = 0;

    GAME_STATUS status;

    Player *player = Player_new();
    
    Map_initaliazeMap(player, LIGNE, COLONNE);
    Map_drawMap();
    
    // Game loop    
    do {
        characterFromGetch = getch();

        if (characterFromGetch == 'q') {
            isFinished = GAME_QUIT;
        }
        
        Player_mouvement(player, characterFromGetch, &status);
        switch (status) {
            case CANNOT_MOVE:
                break;

            case CAN_MOVE:
                system("clear");
                printdebug(player);
                Map_drawMap();
                break;

            case GAME_WIN:                
                system("clear");
                printf("You win !\n");
                printf("Your score was: %d\n", player->score);
                isFinished = GAME_WIN;
                break;

            case GAME_LOOSE:                
                system("clear");
                printf("You Loose All Your HP :( !\n");
                printf("Your score was: %d\n", player->score);
                isFinished = GAME_QUIT;
                break;

            default:
                printf("Error in the game loop\n");
                break;
        }
    } while (isFinished != GAME_WIN && isFinished != GAME_QUIT);

    // Memory free
    Player_free(&player);
    Map_free();
}
