/*
    Ecrire un programme qui declare un tableau de 10 entiers.
    Ensuite, mettre les valeurs 10 a 1 dans le tableau (element 1 = 10, element 2 = 9, ...).
    Finalement, afficher le tableau.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NB_ELEMENTS 10

int main(void) {
    int tableau[NB_ELEMENTS];

    for (short i = 0; i < NB_ELEMENTS; i++) {
        tableau[i] = 10 - i;
    }

    for (short i = 0; i < NB_ELEMENTS; i++) {
        printf("%d\n", tableau[i]);
    }

    system("pause");
    return EXIT_SUCCESS;
}
