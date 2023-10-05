/*
    Ecrire une fonction qui retourne le nombre d'occurrences d'un element dans un tableau.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define MAX_ELEMENTS 100

int nombre_aleatoire(int min, int max);
int nombre_occurences(const int tableau[], int nb_elem, int element);

int main(void) {
    int tablo[MAX_ELEMENTS];
    int element;
    int occurences;

    // Definition des valeurs du tableau
    srand(time(NULL));
    for (short i = 0; i < MAX_ELEMENTS; i++)
        tablo[i] = nombre_aleatoire(0, MAX);

    element = tablo[nombre_aleatoire(0, MAX)];

    // Affichage du tableau et de l'element choisi
    for (short i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", tablo[i]);
    }
    printf("\n%d\n", element);

    // Affichage du nombre d'occurence
    occurences = nombre_occurences(tablo, MAX_ELEMENTS, element);
    printf("Il y'a %d fois %d dans la liste.\n", occurences, element);

    system("pause");
    return EXIT_SUCCESS;
}

int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

int nombre_occurences(const int tableau[], int nb_elem, int element) {
    int occurence = 0;

    for (short i = 0; i < nb_elem; i++)
        if (tableau[i] == element)
            occurence++;

    return occurence;
}
