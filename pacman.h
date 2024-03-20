#ifndef PACMAN_H
#define PACMAN_H

#include "pacgomme.h"
#include "labyrinthe.h"

typedef struct {
    Position position;
    int vies;
    int pacgommes_mangees;
} Pacman;

void initialiser_pacman(Pacman *pacman, Labyrinthe *labyrinthe);

void deplacer_pacman(Pacman *pacman, Labyrinthe *labyrinthe, Position pacgommes[], int *nombre_pacgommes);

#endif
