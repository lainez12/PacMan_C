#include <stdlib.h>
#include <time.h>
#include "fantomes.h"

void initialiser_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe) {
    //nombre aleatoir j'essaie
    srand(time(NULL));

    for (int i = 0; i < nombre_fantomes; i++) {
        int x = rand() % TAILLE_LABYRINTHE;
        int y = rand() % TAILLE_LABYRINTHE;

        if (labyrinthe->cases[x][y] == ' ') {
            fantomes[i].position.x = x;
            fantomes[i].position.y = y;
            labyrinthe->cases[x][y] = 'F';
        }
    }
}

void deplacer_fantomes(Fantome fantomes[], int nombre_fantomes, Labyrinthe *labyrinthe) {
    for (int i = 0; i < nombre_fantomes; i++) {
        int direction = rand() % 4;

        int next_x = fantomes[i].position.x;
        int next_y = fantomes[i].position.y;

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

        labyrinthe->cases[fantomes[i].position.x][fantomes[i].position.y] = ' ';
        labyrinthe->cases[next_x][next_y] = 'F';
        fantomes[i].position.x = next_x;
        fantomes[i].position.y = next_y;
    }
}
