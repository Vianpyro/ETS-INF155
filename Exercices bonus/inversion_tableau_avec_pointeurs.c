/*
    Ecrire un programme qui inverse l'ordre des elements d'un tableau en utilisant des pointeurs

    Instructions :
        - Declarer et initialiser un tableau d'entiers de taille fixe (par exemple, 5 elements).
        - Ecrire une fonction qui prend en entree un tableau et sa taille, puis inverse l'ordre des elements du tableau en utilisant des pointeurs.
        - Afficher le tableau inverse pour verifier que le programme fonctionne correctement.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void inversion(int *debut, int *fin);

#include <stdio.h>

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int longueur = sizeof(tableau) / sizeof(tableau[0]); // Calcule la longueur du tableau
    int *debut = tableau;
    int *fin = tableau + longueur - 1; // Pointe vers le dernier element du tableau

    printf("Tableau original : ");
    for (int i = 0; i < longueur; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    inversion(debut, fin);

    printf("Tableau inverse : ");
    for (int i = 0; i < longueur; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}

// Fonction pour inverser un tableau avec des pointeurs
void inversion(int *debut, int *fin) {
    while (debut < fin) {
        // Echange les elements pointes par debut et fin
        int temp = *debut;
        *debut = *fin;
        *fin = temp;

        // Avance le pointeur de debut et recule le pointeur de fin
        debut++;
        fin--;
    }
}
