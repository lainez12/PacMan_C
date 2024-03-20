#ifndef FANTOMES_H
#define FANTOMES_H

#include "labyrinthe.h"
#include "pacgomme.h"

typedef struct {
    Position position;
} Fantome;

void initialiser_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe);

void deplacer_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe);

#endif
