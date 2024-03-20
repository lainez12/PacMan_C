#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinthe.h"

void initialiser_labyrinthe(Labyrinthe *labyrinthe) {
    for (int i = 0; i < TAILLE_LABYRINTHE; i++) {
        for (int j = 0; j < TAILLE_LABYRINTHE; j++) {
            if (i == 0 || i == TAILLE_LABYRINTHE - 1 || j == 0 || j == TAILLE_LABYRINTHE - 1)
                labyrinthe->cases[i][j] = '#';
            else
                labyrinthe->cases[i][j] = ' '; // Case vide
        }
    }
}

//ça il faut le changer
void placer_murs(Labyrinthe *labyrinthe) {
    labyrinthe->cases[3][5] = '#';
    labyrinthe->cases[4][5] = '#';

    labyrinthe->cases[7][2] = '#';
    labyrinthe->cases[7][3] = '#';
}

void afficher_labyrinthe(Labyrinthe labyrinthe) {
    for (int i = 0; i < TAILLE_LABYRINTHE; i++) {
        for (int j = 0; j < TAILLE_LABYRINTHE; j++) {
            printf("%c ", labyrinthe.cases[i][j]);
        }
        printf("\n");
    }
}
