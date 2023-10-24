/*
    Fonction reçoit un entier positif et retourne nombre de chiffres presents dans le nombre (i.e. 123400 -> 6 chiffres).
    Dans « main », saisir un entier positif au clavier, appel a la fonction et affichage du resultat.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int comptage(int valeur);

int main(void) {
    assert(comptage(4553) == 4);
    assert(comptage(0) == 0);
    assert(comptage(19651651) == 8);

    int valeur;

    printf("Entrez un entier: ");
    scanf("%d", &valeur);

    printf("%d contient %d chiffres...", valeur, comptage(valeur));

    return EXIT_SUCCESS;
}

int comptage(int valeur) {
    int nombre_chiffres = 0;

    while (valeur != 0) {
        valeur /= 10;
        nombre_chiffres++;
    }

    return nombre_chiffres;
}