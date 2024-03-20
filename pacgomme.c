// Fichier pacgomme.c
#include <stdio.h>
#include "pacgomme.h"
#include "labyrinthe.h"

// Fonction pour initialiser les pac-gommes
void initialiser_pacgommes(Labyrinthe *labyrinthe, Position pacgommes[], int nombre_pacgommes) {
    // Simulation de la génération aléatoire des pac-gommes
    // Ici, nous plaçons simplement les pac-gommes aux positions (1,1), (2,2), (3,3), ...
    for (int i = 0; i < nombre_pacgommes; i++) {
        pacgommes[i].x = i + 1;
        pacgommes[i].y = i + 1;

        // Placer la pac-gomme dans le labyrinthe
        labyrinthe->cases[pacgommes[i].x][pacgommes[i].y] = '.'; // Utilisez un caractère représentant les pac-gommes
    }
}

// Fonction pour supprimer une pac-gomme à une position donnée
void supprimer_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position) {
    // Parcourir les pac-gommes et supprimer celle qui correspond à la position donnée
    for (int i = 0; i < nombre_pacgommes; i++) {
        if (pacgommes[i].x == position.x && pacgommes[i].y == position.y) {
            // Déplacer la dernière pac-gomme à la place de celle que nous voulons supprimer
            pacgommes[i] = pacgommes[nombre_pacgommes - 1];
            // Réduire le nombre total de pac-gommes
            nombre_pacgommes--;
            break;
        }
    }
}

// Fonction pour vérifier si une position contient une pac-gomme
int position_a_pacgomme(Position pacgommes[], int nombre_pacgommes, Position position) {
    printf("\nIci peut être\n");
    // Parcourir les pac-gommes et vérifier si l'une d'entre elles est à la position donnée
    for (int i = 0; i < nombre_pacgommes; i++) {
        if (pacgommes[i].x == position.x && pacgommes[i].y == position.y) {
            return 1; // La position contient une pac-gomme
        }
    }
    return 0; // La position ne contient pas de pac-gomme
}
