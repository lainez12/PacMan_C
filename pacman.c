// Fichier pacman.c

#include <stdio.h>
#include "pacman.h"
#include "pacgomme.h"

// Fonction pour initialiser le pacman et le placer dans le labyrinthe
void initialiser_pacman(Pacman *pacman, Labyrinthe *labyrinthe) {
    // Placer le pacman au centre du labyrinthe
    pacman->position.x = TAILLE_LABYRINTHE / 2;
    pacman->position.y = TAILLE_LABYRINTHE / 2;

    // Initialiser le nombre de vies du pacman
    pacman->vies = 3;

    // Initialiser le compteur de pac-gommes mangées
    pacman->pacgommes_mangees = 0;

    // Placer le pacman dans le labyrinthe
    labyrinthe->cases[pacman->position.x][pacman->position.y] = 'P';
}

// Fonction pour déplacer le pacman et gérer ses interactions avec les pac-gommes
void deplacer_pacman(Pacman *pacman, Labyrinthe *labyrinthe, Position pacgommes[], int *nombre_pacgommes) {
    // Obtenir la saisie de l'utilisateur pour le déplacement
    char direction;
    printf("Choisissez une direction (z: haut, q: gauche, s: bas, d: droite) : ");
    scanf(" %c", &direction); // Utilisation de l'espace avant %c pour ignorer les caractères blancs (espaces, retours à la ligne, etc.)

    // Déplacer le pacman selon la direction choisie, s'il n'y a pas de mur
    switch (direction) {
        case 'z':
             printf("Déplacement vers le haut.\n");
            if (pacman->position.x > 0 && labyrinthe->cases[pacman->position.x - 1][pacman->position.y] != '#') {
                printf("Pas de mur, déplacement autorisé.\n");
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' '; // Effacer la position actuelle du pacman
                pacman->position.x--; // Déplacer le pacman vers le haut
            } else {
                printf("Il y a un mur.\n");
            }
            break;
        case 'q':
            if (pacman->position.y > 0 && labyrinthe->cases[pacman->position.x][pacman->position.y - 1] != '#') {
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' '; // Effacer la position actuelle du pacman
                pacman->position.y--; // Déplacer le pacman vers la gauche
            }
            break;
        case 's':
            if (pacman->position.x < TAILLE_LABYRINTHE - 1 && labyrinthe->cases[pacman->position.x + 1][pacman->position.y] != '#') {
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' '; // Effacer la position actuelle du pacman
                pacman->position.x++; // Déplacer le pacman vers le bas
            }
            break;
        case 'd':
            if (pacman->position.y < TAILLE_LABYRINTHE - 1 && labyrinthe->cases[pacman->position.x][pacman->position.y + 1] != '#') {
                labyrinthe->cases[pacman->position.x][pacman->position.y] = ' '; // Effacer la position actuelle du pacman
                pacman->position.y++; // Déplacer le pacman vers la droite
            }
            break;
    }
    printf("\nvoila %d\n",pacman->position.x);
    // Vérifier s'il y a une pac-gomme à la nouvelle position du pacman
    if (position_a_pacgomme(pacgommes, *nombre_pacgommes, pacman->position)) {
        supprimer_pacgomme(pacgommes, *nombre_pacgommes, pacman->position); // Supprimer la pac-gomme mangée
        (*nombre_pacgommes)--; // Réduire le nombre total de pac-gommes
        pacman->pacgommes_mangees++; // Incrémenter le compteur de pac-gommes mangées
    }

    // Placer le pacman à sa nouvelle position dans le labyrinthe
    labyrinthe->cases[pacman->position.x][pacman->position.y] = 'P';
}