// Fichier fantomes.c

#include <stdlib.h>
#include <time.h>
#include "fantomes.h"

// Fonction pour initialiser les fantômes et les placer dans le labyrinthe
void initialiser_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe) {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Placer les fantômes de manière aléatoire dans le labyrinthe
    for (int i = 0; i < nombre_fantomes; i++) {
        // Générer des coordonnées aléatoires pour placer le fantôme
        int x = rand() % TAILLE_LABYRINTHE;
        int y = rand() % TAILLE_LABYRINTHE;

        // Vérifier si la position est vide avant de placer le fantôme
        if (labyrinthe->cases[x][y] == ' ') {
            fantomes[i].position.x = x;
            fantomes[i].position.y = y;
            labyrinthe->cases[x][y] = 'F'; // Marquer la position du fantôme dans le labyrinthe
        }
    }
}

// Fonction pour déplacer les fantômes aléatoirement dans le labyrinthe
void deplacer_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe) {
    // Déplacer chaque fantôme dans une direction aléatoire
    for (int i = 0; i < nombre_fantomes; i++) {
        // Générer un déplacement aléatoire pour le fantôme
        int direction = rand() % 4; // 0: haut, 1: gauche, 2: bas, 3: droite

        // Coordonnées du prochain déplacement
        int next_x = fantomes[i].position.x;
        int next_y = fantomes[i].position.y;

        // Déplacer le fantôme dans la direction choisie, s'il n'y a pas de mur
        switch (direction) {
            case 0:
                if (next_x > 0 && labyrinthe->cases[next_x - 1][next_y] != '#') {
                    next_x--;
                }
                break;
            case 1:
                if (next_y > 0 && labyrinthe->cases[next_x][next_y - 1] != '#') {
                    next_y--;
                }
                break;
            case 2:
                if (next_x < TAILLE_LABYRINTHE - 1 && labyrinthe->cases[next_x + 1][next_y] != '#') {
                    next_x++;
                }
                break;
            case 3:
                if (next_y < TAILLE_LABYRINTHE - 1 && labyrinthe->cases[next_x][next_y + 1] != '#') {
                    next_y++;
                }
                break;
        }

        // Mettre à jour la position du fantôme dans le labyrinthe
        labyrinthe->cases[fantomes[i].position.x][fantomes[i].position.y] = ' '; // Effacer la position actuelle du fantôme
        labyrinthe->cases[next_x][next_y] = 'F'; // Déplacer le fantôme à la nouvelle position
        fantomes[i].position.x = next_x;
        fantomes[i].position.y = next_y;
    }
}
