// Fichier labyrinthe.h

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#define TAILLE_LABYRINTHE 10 // Taille du labyrinthe (10x10 dans cet exemple)

// Structure pour représenter le labyrinthe
typedef struct {
    char cases[TAILLE_LABYRINTHE][TAILLE_LABYRINTHE]; // Matrice représentant les cases du labyrinthe
} Labyrinthe;

// Fonction pour initialiser le labyrinthe
void initialiser_labyrinthe(Labyrinthe *labyrinthe);

// Fonction pour placer aléatoirement quelques murs dans le labyrinthe
void placer_murs(Labyrinthe *labyrinthe);

// Fonction pour afficher le labyrinthe
void afficher_labyrinthe(Labyrinthe labyrinthe);

#endif