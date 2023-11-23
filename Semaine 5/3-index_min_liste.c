/*
    Ecrire une fonction qui recoit en parametres un tableau d'entiers ainsi que le nombre d'elements du tableau.
    La fonction retourne l'indice du plus petit element.
*/
#include <stdio.h>
#include <stdlib.h>

#define NB_ELEMENTS 10

int indice_minimum(int tableau[], int longueur);

int main(void) {
    int tableau[NB_ELEMENTS] = {-1, 56, 47, -96, 24, 18, 12, 14, 0, -1};

    printf("Le plus petit element se trouve a l'indice %d.\n", indice_minimum(tableau, NB_ELEMENTS));

    system("pause");
    return EXIT_SUCCESS;
}

int indice_minimum(int tableau[], int longueur) {
    int index = 0;

    for (int i = 1; i < longueur; i++)
        if (tableau[i] < tableau[index])
            index = i;

    return index;
}
