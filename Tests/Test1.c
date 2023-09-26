/*
    Fichier de remise de Vianney Veremme pour le Test #1 d'INF155 - Groupe 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

// Definition des valeurs minimum et maximum (selon l'enoncee)
#define MIN 100
#define MAX 200

// Declarations prototypes des fonctions definies apres la fonction principale (main)
int saisir_entier(int min, int max);
int produit_chiffres(int valeur);

int main(void) {
    // Verifications de la fonction produit_chiffres
    assert(produit_chiffres(124) == 8);
    assert(produit_chiffres(101) == 0);

    // Declaration variable(s)
    int nb_fin;

    // Demande d'entree a l'utilisateur
    nb_fin = saisir_entier(MIN, MAX);

    // Affichage des valeurs comprises entre MIN et MAX dont au moins un chiffre est "0"
    for (int i = MIN; i <= nb_fin; i++) {
        if (produit_chiffres(i) == 0) {
            printf("%d, ", i);
        }
    }

    return EXIT_SUCCESS;
}

// Declaration d'une fonction retourne un entier saisi et verifie qu'il est bien compris dans un interval defini
int saisir_entier(int min, int max) {
    int valeur;

    do {
        printf("Entrez un entier compris entre %d et %d: ", min, max);
        scanf("%d", &valeur);
    } while (valeur < min || valeur > max);

    return valeur;
}

// Declaration d'une fonction retourne le produit des chiffres d'un nombre recu
int produit_chiffres(int valeur) {
    int produit = 1;

    while (valeur != 0) {
        produit *= valeur % 10;
        valeur /= 10;
    }

    return produit;
}
