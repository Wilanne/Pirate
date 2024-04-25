#ifndef UTILS_H
#define UTILS_H

#define COLONNE 6
#define LIGNE 6
#define TREASURE 2
#define TRAP 3

typedef enum GAME_STATUS{
    INITIALISED,
    CAN_MOVE,
    CANNOT_MOVE,
    GAME_WIN,
    GAME_LOOSE,
    GAME_QUIT
} GAME_STATUS;

typedef struct coordinate {
    int x;
    int y;
} coordinate;

#endif