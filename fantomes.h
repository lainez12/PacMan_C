// Fichier fantomes.h

#ifndef FANTOMES_H
#define FANTOMES_H

#include "labyrinthe.h"
#include "pacgomme.h"

// Structure pour représenter un fantôme
typedef struct {
    Position position;
} Fantome;

// Fonction pour initialiser les fantômes et les placer dans le labyrinthe
void initialiser_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe);

// Fonction pour déplacer les fantômes aléatoirement dans le labyrinthe
void deplacer_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe);

#endif
