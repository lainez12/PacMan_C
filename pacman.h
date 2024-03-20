// Fichier pacman.h

#ifndef PACMAN_H
#define PACMAN_H

#include "pacgomme.h"
#include "labyrinthe.h"

// Structure pour représenter le pacman
typedef struct {
    Position position;
    int vies;
    int pacgommes_mangees;
} Pacman;

// Fonction pour initialiser le pacman et le placer dans le labyrinthe
void initialiser_pacman(Pacman *pacman, Labyrinthe *labyrinthe);

// Fonction pour déplacer le pacman et gérer ses interactions avec les pac-gommes
void deplacer_pacman(Pacman *pacman, Labyrinthe *labyrinthe, Position pacgommes[], int *nombre_pacgommes);

#endif
