/*
    Ecrire une fonction qui recoit en parametres un tableau d'entiers ainsi que
        le nombre de lignes et le nombre de colonnes du tableau. La fonction
        retourne le plus petit element du tableau.
*/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COLONNES_MAX 10

int minimum_liste2d(int tableau[][NB_COLONNES_MAX], int nb_lignes, int nb_colonnes);

int main(void) {
    int tableau[][NB_COLONNES_MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int nb_lignes = 3,
        nb_colonnes = 3,
        minimum;

    minimum = minimum_liste2d(tableau, nb_lignes, nb_colonnes);
    printf("Le minimum est: %d\n", minimum);

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
