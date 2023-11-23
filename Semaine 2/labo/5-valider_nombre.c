/*
    Valider un nombre entre 1 et 10 puis calculer au factoriel
*/
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#define MIN 1
#define MAX 10

int entier_valide(int min, int max);
int factoriel(int valeur);

int main(void) {
    assert(factoriel(0) == 1);
    assert(factoriel(1) == 1);
    assert(factoriel(3) == 6);
    assert(factoriel(5) == 120);

    int valeur_a_factoriser = entier_valide(MIN, MAX);

    printf("%d! vaut %d.", valeur_a_factoriser, factoriel(valeur_a_factoriser));

    return EXIT_SUCCESS;
}

int entier_valide(int min, int max) {
    int entier = 0;

    printf("Entrez la valeur a calculer: ");
    scanf("%d", &entier);

    while (entier < min || entier > max) {
        printf("Entrez une valeur comprise entre %d et %d: ", min, max);
        scanf("%d", &entier);
    }
    return entier;
}

int factoriel(int valeur) {
    int result = 1;

    for (int i = 2; i <= valeur; i++) result *= i;

    return result;
}
