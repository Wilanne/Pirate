#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "getch.h"
#include "game.h"

char characterFromGetch;

Game *Game_new() {
    // The srand function is used to initialize the random number generator.
    srand(time(NULL));

    // Memory allocation
    Game *game = calloc(1, sizeof(Game));
    if (game == NULL) {
        perror("Game allocation failed\n");
        exit(EXIT_FAILURE);
    }


    game->player = Player_new();
    
    for (int i = 0; i < TREASURE; i++) {
        game->treasures[i] = Treasure_new();
    }
    
    for (int i = 0; i < TRAP; i++) {
        game->traps[i] = Trap_new();
    }

    for (int i = 0; i < PIRATE; i++) {
        game->pirates[i] = Pirate_new();
    }
    
    game->map = Map_new(game);
    
    game->isRunning = true;
    game->status = INITIALISED;

    return game;
}

void Game_free(Game **game) {
    for (int i = 0; i < PIRATE; i++) {
        Pirate_free(&(*game)->pirates[i]);
    }
    
    for (int i = 0; i < TREASURE; i++) {
        Treasure_free(&(*game)->treasures[i]);
    }

    for (int i = 0; i < TRAP; i++) {
        Trap_free(&(*game)->traps[i]);
    }

    Map_free(&(*game)->map);
    Player_free(&(*game)->player);

    free(*game);
    *game = NULL;
}

void Game_run(Game *game) {
    Game_display(game);
    while (game->isRunning) {
        Game_update(game);
        Game_display(game);
    }
}

void Game_update(Game *game) {
    characterFromGetch = getch();

    if (characterFromGetch == 'q') {
        game->isRunning = false;
    }

    Map_handleMovement(game, characterFromGetch);

    switch (game->status)
    {
    default:
        printf("Error in the game loop\n");
            break;

    case GAME_WIN:
        game->isRunning = false;
        break;
    
    case GAME_LOOSE:
        game->isRunning = false;
        break;
    }
}

void Game_display(Game *game) {
    system("clear");
    Map_drawMap(game->map);
    printf("Player health: %d\n", Player_get_health(game->player));

    if (game->status == GAME_WIN) {
        printf("You win !\n");
        printf("Your score was: %d\n", game->player->score);
    }

    if (game->status == GAME_LOOSE) {
        printf("You Loose All Your HP :( !\n");
        printf("Your score was: %d\n", game->player->score);
    } 
    
}