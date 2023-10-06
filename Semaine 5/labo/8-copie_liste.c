/*
    Ecrire une fonction qui copie un tableau dans un autre.
    La fonction reçoit en parametres deux tableaux ainsi que le nombre d'elements a copier.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAX_ELEMENTS 10

void copier_tableau(int dest[], const int source[], int nb_elem);
int nombre_aleatoire(int min, int max);

int main(void) {
    int tableau_source[MAX_ELEMENTS],
        tableau_destination[MAX_ELEMENTS];

    // Definition des valeurs du premier tableau
    srand(time(NULL));
    for (short i = 0; i < MAX_ELEMENTS; i++)
        tableau_source[i] = nombre_aleatoire(0, MAX);

    // Copie du tableau de source dans le tableau de destination
    copier_tableau(tableau_destination, tableau_source, MAX_ELEMENTS);

    for (short i = 0; i < MAX_ELEMENTS; i++)
        printf("%d\n", tableau_destination[i]);

    system("pause");
    return EXIT_SUCCESS;
}

void copier_tableau(int dest[], const int source[], int nb_elem) {
    for (int i = 0; i < nb_elem; i++)
        dest[i] = source[i];
}

int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}
