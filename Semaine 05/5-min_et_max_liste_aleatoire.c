/*
    Ecrire un programme qui declare un tableau de 10 entiers.
    Ensuite, il met des valeurs aleatoires comprises entre 1 et 100 dans le tableau.
    Finalement, il affiche le plus petit et le plus grand element du tableau.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_ELEMENTS 10
#define MIN 1
#define MAX 100

int nombre_aleatoire(int min, int max);
int indice_maximum(int tableau[], int longueur);
int indice_minimum(int tableau[], int longueur);

int main(void) {
    int tableau[NB_ELEMENTS];
    int index_min, index_max;

    // Definition des valeurs du tableau
    srand(time(NULL));
    for (int i = 0; i < NB_ELEMENTS; i++)
        tableau[i] = nombre_aleatoire(MIN, MAX);

    // Affichage du tableau
    for (int i = 0; i < NB_ELEMENTS; i++)
        printf("%d ", tableau[i]);

    printf("\n");

    // Affichage des valeurs min et max
    index_min = indice_minimum(tableau, NB_ELEMENTS);
    index_max = indice_maximum(tableau, NB_ELEMENTS);

    printf("Le minimum est: %d, a la position %d\n", tableau[index_min], index_min);
    printf("Le maximum est: %d, a la position %d\n", tableau[index_max], index_max);

    system("pause");
    return EXIT_SUCCESS;
}

int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

int indice_minimum(int tableau[], int longueur) {
    int index = 0;

    for (int i = 1; i < longueur; i++)
        if (tableau[i] < tableau[index])
            index = i;

    return index;
}

int indice_maximum(int tableau[], int longueur) {
    int index = 0;

    for (int i = 1; i < longueur; i++)
        if (tableau[i] > tableau[index])
            index = i;

    return index;
}
