// Fichier pacgomme.h

#ifndef PACGOMME_H
#define PACGOMME_H

#include "labyrinthe.h" // Inclure la déclaration du type Labyrinthe

// Structure pour stocker une position
typedef struct {
    int x;
    int y;
} Position;

// Fonction pour initialiser les pac-gommes
void initialiser_pacgommes(Labyrinthe *labyrinthe, Position pacgommes[], int nombre_pacgommes);

// Fonction pour supprimer une pac-gomme à une position donnée
void supprimer_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position);

// Fonction pour vérifier si une position contient une pac-gomme
int position_a_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position);

#endif
