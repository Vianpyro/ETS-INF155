/*
    Programme calcule somme des chiffres nombre entier.
    Doit faire appel aux fonctions des numeros 8 et 9 pour faire cette somme
        (i.e. selon le nombre de chiffres du nombre, on fait la somme de chaque chiffre recupere avec la fonction du #9)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int somme_chiffres(int valeur);

int main(void) {
    assert(somme_chiffres(123) == 6);
    
    int valeur;

    printf("Entrez une valeur: ");
    scanf("%d", &valeur);

    printf("La somme des chiffres de %d est: %d", valeur, somme_chiffres(valeur));

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

int position(int valeur, int position) {
    // On enleve 1 a la position car la boucle commence a 0
    while (position - 1 > 0) {
        valeur /= 10;
        position--;
    }

    return valeur % 10;
}

int somme_chiffres(int valeur) {
    int longueur = comptage(valeur);
    int somme = 0;

    for (int i = 1; i <= longueur; i++) {
        somme += position(valeur, i);
    }

    return somme;
}
