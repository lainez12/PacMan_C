// Fichier labyrinthe.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinthe.h"

// Fonction pour initialiser le labyrinthe
void initialiser_labyrinthe(Labyrinthe *labyrinthe) {
    // Remplir toutes les cases du labyrinthe avec des espaces (représentant des cases vides)
    for (int i = 0; i < TAILLE_LABYRINTHE; i++) {
        for (int j = 0; j < TAILLE_LABYRINTHE; j++) {
            if (i == 0 || i == TAILLE_LABYRINTHE - 1 || j == 0 || j == TAILLE_LABYRINTHE - 1)
                labyrinthe->cases[i][j] = '#';
            else
                labyrinthe->cases[i][j] = ' '; // Case vide
        }
    }
}

// Fonction pour placer deux murs simples dans des positions spécifiques du labyrinthe
void placer_murs(Labyrinthe *labyrinthe) {
    // Placer le premier mur simple
    labyrinthe->cases[3][5] = '#'; // Mur vertical à la position (3, 5)
    labyrinthe->cases[4][5] = '#'; // Mur vertical à la position (4, 5)

    // Placer le deuxième mur simple
    labyrinthe->cases[7][2] = '#'; // Mur horizontal à la position (7, 2)
    labyrinthe->cases[7][3] = '#'; // Mur horizontal à la position (7, 3)
}

// Fonction pour afficher le labyrinthe
void afficher_labyrinthe(Labyrinthe labyrinthe) {
    for (int i = 0; i < TAILLE_LABYRINTHE; i++) {
        for (int j = 0; j < TAILLE_LABYRINTHE; j++) {
            printf("%c ", labyrinthe.cases[i][j]);
        }
        printf("\n");
    }
}
