#ifndef PACGOMME_H
#define PACGOMME_H

#include "labyrinthe.h"

typedef struct {
    int x;
    int y;
} Position;

void initialiser_pacgommes(Labyrinthe *labyrinthe, Position pacgommes[], int nombre_pacgommes);

void supprimer_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position);

int position_a_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position);

#endif
