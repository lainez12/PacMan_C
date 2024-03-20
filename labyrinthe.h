#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#define TAILLE_LABYRINTHE 10 // ça jsp si il faut que soit dinamique

typedef struct {
    char cases[TAILLE_LABYRINTHE][TAILLE_LABYRINTHE];
} Labyrinthe;

void initialiser_labyrinthe(Labyrinthe *labyrinthe);

void placer_murs(Labyrinthe *labyrinthe);

void afficher_labyrinthe(Labyrinthe labyrinthe);

#endif