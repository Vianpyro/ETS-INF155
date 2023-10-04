/*
    Modifier le programme de l'exercice 1 afin qu'il affiche le tableau en partant du dernier element.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NB_ELEMENTS 10

int main(void) {
    int tableau[NB_ELEMENTS];

    for (short i = 0; i < NB_ELEMENTS; i++)
        tableau[i] = 10 - i;

    for (short i = NB_ELEMENTS - 1; i >= 0; i--)
        printf("%d\n", tableau[i]);

    system("pause");
    return EXIT_SUCCESS;
}
