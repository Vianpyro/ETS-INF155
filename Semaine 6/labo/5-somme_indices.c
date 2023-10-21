/*
    Ecrire un programme qui declare un tableau d'entiers de 10 lignes et 20 colonnes.
    Le programme met la somme des indices dans chaque case du tableau (l'element
        a la ligne 3 colonne 4 prend la valeur 7, l'element a la ligne 5 colonne
        10 prend la valeur 15, etc...).
    Finalement, le programme fait une copie du tableau et affiche la copie sur
        10 lignes et 20 colonnes.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>  // Pour le uint8_t, allant de 0 a 255: optimisation pour le fun
#include <stdio.h>
#include <stdlib.h>

#define NB_LIGNES 10
#define NB_COLONNES 20

void copier_tableau_2D(int destination[NB_LIGNES][NB_COLONNES],
                       int source[NB_LIGNES][NB_COLONNES]);
void affichage_tableau_2d(int tableau[NB_LIGNES][NB_COLONNES]);

int main(void) {
    int tableau[NB_LIGNES][NB_COLONNES],
        copie[NB_LIGNES][NB_COLONNES];

    // Remplissage
    for (uint8_t i = 0; i < NB_LIGNES; i++) {
        for (uint8_t j = 0; j < NB_COLONNES; j++) {
            tableau[i][j] = i + j;
        }
    }

    // Copie et affichage de la copie
    copier_tableau_2D(copie, tableau);
    affichage_tableau_2d(copie);

    system("pause");
    return EXIT_SUCCESS;
}

void copier_tableau_2D(int destination[NB_LIGNES][NB_COLONNES],
                       int source[NB_LIGNES][NB_COLONNES]) {
    for (uint8_t i = 0; i < NB_LIGNES; i++) {
        for (uint8_t j = 0; j < NB_COLONNES; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

void affichage_tableau_2d(int tableau[NB_LIGNES][NB_COLONNES]) {
    for (uint8_t i = 0; i < NB_LIGNES; i++) {
        for (uint8_t j = 0; j < NB_COLONNES; j++) {
            printf(" %3d,", tableau[i][j]);
        }
        printf("\n");
    }
}
