#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "fantomes.h"
#include "labyrinthe.h"
#include "pacgomme.h"

#define NB_FANTOMES 4 // Nombre de fantômes

int main() {
    // Creation du labyrinthe
    Labyrinthe labyrinthe;
    initialiser_labyrinthe(&labyrinthe);
    placer_murs(&labyrinthe);

    // Creation des pacgommes
    Position pacgommes[TAILLE_LABYRINTHE * TAILLE_LABYRINTHE];
    int nombre_pacgommes = TAILLE_LABYRINTHE * TAILLE_LABYRINTHE;
    initialiser_pacgommes(&labyrinthe, pacgommes, nombre_pacgommes);
    // Creation du pacman
    Pacman pacman;
    initialiser_pacman(&pacman, &labyrinthe);

    // Creation des fantomes
    Fantome fantomes[NB_FANTOMES];
    initialiser_fantomes(fantomes, NB_FANTOMES, &labyrinthe);

    // Jeu
    int partie_terminee = 0;
    while (!partie_terminee) {
        system("clear");

        afficher_labyrinthe(labyrinthe);

        deplacer_pacman(&pacman, &labyrinthe, pacgommes, &nombre_pacgommes);

        deplacer_fantomes(fantomes, NB_FANTOMES, &labyrinthe);

        // Il faut gere le vie encore

        if (nombre_pacgommes == 0) {
            partie_terminee = 1;
            printf("Félicitations ! Vous avez fini de mangé toutes les pac-gommes.!\n");
        }

        system("sleep 1");
    }

    return 0;
}
