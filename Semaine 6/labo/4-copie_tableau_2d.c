/*
    Ecrire une fonction qui copie un tableau dans un autre.
    La fonction reçoit en parametres les deux tableaux ainsi que le nombre
    de lignes a copier.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100
#define NB_COLONNES_MAX 20

int nombre_aleatoire(int min, int max);
void copier_tableau_2D(int destination[][NB_COLONNES_MAX],
                       int source[][NB_COLONNES_MAX], int nb_lignes);
void affichage_tableau_2d(int tableau[][NB_COLONNES_MAX], int nb_lignes);

int main(void) {
    const int nb_lignes = 10;
    int source[nb_lignes][NB_COLONNES_MAX],
        destination[nb_lignes][NB_COLONNES_MAX];

    // Initialisation de l'aleatoire
    srand(time(NULL));

    // Remplissage et affichage du tableau
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < NB_COLONNES_MAX; j++) {
            source[i][j] = nombre_aleatoire(MIN, MAX);
        }
    }

    // Copie
    copier_tableau_2D(destination, source, nb_lignes);

    // Affichage (pour verifier)
    printf("Tableau source:\n");
    affichage_tableau_2d(source, nb_lignes);
    printf("Tableau destination:\n");
    affichage_tableau_2d(destination, nb_lignes);

    system("pause");
    return EXIT_SUCCESS;
}

int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

void copier_tableau_2D(int destination[][NB_COLONNES_MAX],
                       int source[][NB_COLONNES_MAX], int nb_lignes) {
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < NB_COLONNES_MAX; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

void affichage_tableau_2d(int tableau[][NB_COLONNES_MAX], int nb_lignes) {
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < NB_COLONNES_MAX; j++) {
            printf(" %3d,", tableau[i][j]);
        }
        printf("\n");
    }
}
