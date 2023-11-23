/*
    Ecrire un programme complet qui genere 20 entiers aleatoires entre 1 et 10 et les mets dans un tableau d'entiers.
    Ensuite, le programme affiche le plus petit element avec son indice et son nombre d'occurrences 
        ainsi que le plus grand element avec son indice et son nombre d'occurrences.
    Finalement, il fait une copie du tableau et il inverse la copie.
    Il affiche la copie inversee ainsi que le tableau original.
    UTILISER LES FONCTIONS DES 6 NUMEROS PRECEDENTS.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define MAX_ELEMENTS 20

int indice_minimum(int tableau[], int longueur);
int indice_maximum(int tableau[], int longueur);
int nombre_occurences(const int tableau[], int nb_elem, int element);
void copier_tableau(int dest[], const int source[], int nb_elem);
void renverser_tableau(int tableau[], int nb_elem);
int nombre_aleatoire(int min, int max);

int main(void) {
    int tableau_initial[MAX_ELEMENTS], tableau_final[MAX_ELEMENTS];
    int valeur_min, valeur_max;
    unsigned char indice_min, indice_max;

    // Definition des valeurs du tableau initial
    srand(time(NULL));
    for (short i = 0; i < MAX_ELEMENTS; i++)
        tableau_initial[i] = nombre_aleatoire(0, MAX);

    indice_min = indice_minimum(tableau_initial, MAX_ELEMENTS);
    indice_max = indice_maximum(tableau_initial, MAX_ELEMENTS);

    valeur_min = tableau_initial[indice_min];
    valeur_max = tableau_initial[indice_max];

    printf("Le plus petit element est %d, a l'indice %d.\n", valeur_min, indice_min);
    printf("Le plus grand element est %d, a l'indice %d.\n", valeur_max, indice_max);

    // Clonage et inversion du tableau
    copier_tableau(tableau_final, tableau_initial, MAX_ELEMENTS);
    renverser_tableau(tableau_final, MAX_ELEMENTS);

    // Affichage du tableau initial
    for (short i = 0; i < MAX_ELEMENTS; i++)
        printf("%d ", tableau_initial[i]);
    printf("\n");

    // Affichage du tableau final
    for (short i = 0; i < MAX_ELEMENTS; i++)
        printf("%d ", tableau_final[i]);
    printf("\n");

    system("pause");
    return EXIT_SUCCESS;
}

// Fonction retournant l'indice de la valeur maximum d'un tableau
int indice_maximum(int tableau[], int longueur) {
    int index = 0;

    for (int i = 1; i < longueur; i++)
        if (tableau[i] > tableau[index])
            index = i;

    return index;
}

// Fonction retournant l'indice de la valeur minimum d'un tableau
int indice_minimum(int tableau[], int longueur) {
    int index = 0;

    for (int i = 1; i < longueur; i++)
        if (tableau[i] < tableau[index])
            index = i;

    return index;
}

// Fonction de comptage d'occurence d'une valeur dans un tableau
int nombre_occurences(const int tableau[], int nb_elem, int element) {
    int occurence = 0;

    for (short i = 0; i < nb_elem; i++)
        if (tableau[i] == element)
            occurence++;

    return occurence;
}

// Fonction de copie d'un tableau
void copier_tableau(int dest[], const int source[], int nb_elem) {
    for (int i = 0; i < nb_elem; i++)
        dest[i] = source[i];
}

// Fonction d'inversion du tableau
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
