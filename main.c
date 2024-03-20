// Fichier main.c

#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "fantomes.h"
#include "labyrinthe.h"
#include "pacgomme.h"

#define NB_FANTOMES 4 // Nombre de fantômes dans le labyrinthe

int main() {
    // Création du labyrinthe
    Labyrinthe labyrinthe;
    initialiser_labyrinthe(&labyrinthe);
    placer_murs(&labyrinthe);

    // Création des pac-gommes
    Position pacgommes[TAILLE_LABYRINTHE * TAILLE_LABYRINTHE];
    int nombre_pacgommes = TAILLE_LABYRINTHE * TAILLE_LABYRINTHE;
    initialiser_pacgommes(&labyrinthe, pacgommes, nombre_pacgommes);
    // Création du pacman
    Pacman pacman;
    initialiser_pacman(&pacman, &labyrinthe);

    // Création des fantômes
    Fantome fantomes[NB_FANTOMES];
    initialiser_fantomes(fantomes, NB_FANTOMES, &labyrinthe);

    // Boucle de jeu
    int partie_terminee = 0;
    while (!partie_terminee) {
        system("clear"); // Efface l'écran (fonctionne sous Linux/Unix)

        // Affichage du labyrinthe
        afficher_labyrinthe(labyrinthe);

        // Déplacement du pacman
        deplacer_pacman(&pacman, &labyrinthe, pacgommes, &nombre_pacgommes);

        // Déplacement des fantômes
        deplacer_fantomes(fantomes, NB_FANTOMES, &labyrinthe);

        // TODO: Ajouter d'autres conditions de fin de partie (ex: nombre de vies épuisé)

        // Condition de fin de partie (exemple: plus de pac-gommes)
        if (nombre_pacgommes == 0) {
            partie_terminee = 1;
            printf("Félicitations ! Vous avez mangé toutes les pac-gommes. Vous avez gagné !\n");
        }

        // Pause pour ralentir l'affichage (peut être ajustée)
        system("sleep 1");
    }

    return 0;
}
