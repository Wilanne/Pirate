#ifndef UTILS_H
#define UTILS_H

// Map size
#define LINES 10
#define COLUMNS 10

// Number of elements
#define PLAYER 1
#define TREASURE 2
#define TRAP 5
#define PIRATE 2

// Player settings
#define POS_X 0
#define POS_Y 0
#define HEALTH 3 

typedef enum GAME_STATUS{
    INITIALISED,
    RUNNING,
    CAN_MOVE,
    CANNOT_MOVE,
    GAME_WIN,
    GAME_LOOSE,
} GAME_STATUS;

typedef struct coordinate {
    int x;
    int y;
} coordinate;

#endif