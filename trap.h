#ifndef TRAP_H
#define TRAP_H

typedef struct Trap
{
    coordinate position;
    int damage;
} Trap;

// Trap new and free
Trap *Trap_new();
void Trap_free(Trap **Trap);

coordinate Trap_get_pos(Trap *Trap);
void Trap_set_pos(Trap *Trap, coordinate pos);


#endif
