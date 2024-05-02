// Last update: 20/03/2024 
#include <stdlib.h>
#include <stdio.h>

// User includes
#include "game.h"

int main()
{
    Game *game = Game_new();

    // Game loop 
    while (game->isRunning) {
        Game_run(game);
    }
    
    Game_free(&game);
}
   