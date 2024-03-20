#include <stdio.h>
#include "pacgomme.h"
#include "labyrinthe.h"

void initialiser_pacgommes(Labyrinthe *labyrinthe, Position pacgommes[], int nombre_pacgommes) {

    for (int i = 0; i < nombre_pacgommes; i++) {
        pacgommes[i].x = i + 1;
        pacgommes[i].y = i + 1;

        // Placer la pac-gomme, mais pas aleatoirement et pas dans tout le Labyrinthe
        labyrinthe->cases[pacgommes[i].x][pacgommes[i].y] = '.';
    }
}

// Fonction pour supprimer une pac-gomme
void supprimer_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position) {
    for (int i = 0; i < nombre_pacgommes; i++) {
        if (pacgommes[i].x == position.x && pacgommes[i].y == position.y) {
            pacgommes[i] = pacgommes[nombre_pacgommes - 1];
            nombre_pacgommes--;
            break;
        }
    }
}

int position_a_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position) {
    printf("\nIci peut être\n");
    for (int i = 0; i < nombre_pacgommes; i++) {
        if (pacgommes[i].x == position.x && pacgommes[i].y == position.y) {
            return 1; // La position contient une pac-gomme
        }
    }
    return 0; // pas de pac-gomme
}
