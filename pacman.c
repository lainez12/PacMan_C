#include <stdio.h>
#include "pacman.h"
#include "pacgomme.h"

//Mettre a pacman dans le labyrinthe
void initialiser_pacman(Pacman *pacman, Labyrinthe *labyrinthe) {
    pacman->position.x = TAILLE_LABYRINTHE / 2;
    pacman->position.y = TAILLE_LABYRINTHE / 2;
    //mais il meur pas encore, jsp pk
    pacman->vies = 3;

    //jsp sil faut les comptabiliser
    pacman->pacgommes_mangees = 0;

    // P de pacman
    labyrinthe->cases[pacman->position.x][pacman->position.y] = 'P';
}

// deplacer le pacman et manger ses pac-gommes
void deplacer_pacman(Pacman *pacman, Labyrinthe *labyrinthe, Position pacgommes[], int *nombre_pacgommes) {
    char direction;
    printf("Choisissez une direction (z: haut, q: gauche, s: bas, d: droite) : ");
    scanf(" %c", &direction);

    //cela il faut l'amelieure
    switch (direction) {
        case 'z':
             printf("Déplacement vers le haut.\n");
            if (pacman->position.x > 0 && labyrinthe->cases[pacman->position.x - 1][pacman->position.y] != '#') {
                printf("Pas de mur, déplacement autorisé.\n");
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' '; // Effacer la position 
                pacman->position.x--; // Déplacer le pacman vers le haut marche pas
            } else {
                printf("Il y a un mur.\n");
            }
            break;
        case 'q':
            if (pacman->position.y > 0 && labyrinthe->cases[pacman->position.x][pacman->position.y - 1] != '#') {
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' ';
                pacman->position.y--;
            }
            break;
        case 's':
            if (pacman->position.x < TAILLE_LABYRINTHE - 1 && labyrinthe->cases[pacman->position.x + 1][pacman->position.y] != '#') {
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' ';
                pacman->position.x++;
            }
            break;
        case 'd':
            if (pacman->position.y < TAILLE_LABYRINTHE - 1 && labyrinthe->cases[pacman->position.x][pacman->position.y + 1] != '#') {
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' '; 
                pacman->position.y++;
            }
            break;
    }
    //faire disparraitre le pacgommes
    if (position_a_pacgomme(pacgommes, *nombre_pacgommes, pacman->position)) {
        supprimer_pacgomme(pacgommes, *nombre_pacgommes, pacman->position);
        (*nombre_pacgommes)--;
        pacman->pacgommes_mangees++;
    }

    // nouvelle position?
    labyrinthe->cases[pacman->position.x][pacman->position.y] = 'P';
}