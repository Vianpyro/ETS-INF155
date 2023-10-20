/*
    Ecrire un programme qui declare un tableau d'entiers de 10 lignes et 10
        colonnes. Ensuite, il met des valeurs aleatoires comprises entre 1 et
        100 dans le tableau. Finalement, il affiche le plus petit et le plus
        grand element du tableau.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100
#define NB_LIGNES_MAX 10
#define NB_COLONNES_MAX 10

int minimum_liste2d(int tableau[][NB_COLONNES_MAX], int nb_lignes, int nb_colonnes);
int maximum_liste2d(int tableau[][NB_COLONNES_MAX], int nb_lignes, int nb_colonnes);
int nombre_aleatoire(int min, int max);
void affiche_min_max_liste2d(int tableau[NB_LIGNES_MAX][NB_COLONNES_MAX], int nb_lignes, int nb_colonnes);

int main(void) {
    int tableau[NB_LIGNES_MAX][NB_COLONNES_MAX];

    // Initialisation de l'aleatoire
    srand(time(NULL));

    // Remplissage et affichage du tableau
    for (int i = 0; i < NB_LIGNES_MAX; i++) {
        for (int j = 0; j < NB_COLONNES_MAX; j++) {
            tableau[i][j] = nombre_aleatoire(MIN, MAX);
            printf(" %3d,", tableau[i][j]);
        }
        printf("\n");
    }

    // Affichage
    affiche_min_max_liste2d(tableau, NB_LIGNES_MAX, NB_COLONNES_MAX);

    system("pause");
    return EXIT_SUCCESS;
}

int minimum_liste2d(int tableau[][NB_COLONNES_MAX], int nb_lignes, int nb_colonnes) {
    int minimum = tableau[0][0];

    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            if (tableau[i][j] < minimum)
                minimum = tableau[i][j];
        }
    }

    return minimum;
}

int maximum_liste2d(int tableau[][NB_COLONNES_MAX], int nb_lignes, int nb_colonnes) {
    int maximum = tableau[0][0];

    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            if (tableau[i][j] > maximum)
                maximum = tableau[i][j];
        }
    }

    return maximum;
}

int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

void affiche_min_max_liste2d(int tableau[][NB_COLONNES_MAX], int nb_lignes, int nb_colonnes) {
    int minimum, maximum;

    minimum = minimum_liste2d(tableau, nb_lignes, nb_colonnes);
    maximum = maximum_liste2d(tableau, nb_lignes, nb_colonnes);

    printf("Le minimum est: %d.\n", minimum);
    printf("Le maximum est: %d.\n", maximum);
}
