#ifndef TREASURE_H
#define TREASURE_H

typedef struct Treasure
{
    coordinate position;
    //bool is_taken;
    //int value;
} Treasure;

// Player new and free
Treasure *Treasure_new();
void Treasure_free(Treasure **Treasure);

coordinate Treasure_get_pos(Treasure *Treasure);
void Treasure_set_pos(Treasure *Treasure, coordinate pos);

#endif
