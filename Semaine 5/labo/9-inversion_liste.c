/*
    Ecrire une fonction qui renverse un tableau.
    Le premier element devient le dernier, le dernier devient le premier, le second devient l'avant dernier, etc.
    La fonction reçoit en parametres le tableau a renverser ainsi que le nombre d'elements dans le tableau.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAX_ELEMENTS 10

void renverser_tableau(int tableau[], int nb_elem);
int nombre_aleatoire(int min, int max);

int main(void) {
    int tableau[MAX_ELEMENTS];

    // Definition des valeurs du tableau
    srand(time(NULL));
    for (short i = 0; i < MAX_ELEMENTS; i++)
        tableau[i] = nombre_aleatoire(0, MAX);

    // Affichage du tableau avant inversion
    for (short i = 0; i < MAX_ELEMENTS; i++)
        printf("%d ", tableau[i]);
    printf("\n");

    // Inversion du tableau
    renverser_tableau(tableau, MAX_ELEMENTS);

    for (short i = 0; i < MAX_ELEMENTS; i++)
        printf("%d ", tableau[i]);
    printf("\n");

    system("pause");
    return EXIT_SUCCESS;
}

// Fonction d'inversion d'un tableau
void renverser_tableau(int tableau[], int nb_elem) {
    int temp;

    for (int i = 0; i < nb_elem / 2; i++) {
        int temp = tableau[i];
        tableau[i] = tableau[nb_elem - 1 - i];
        tableau[nb_elem - 1 - i] = temp;
    }
}

int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}
