/*
    Calcul d'un factoriel
*/
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int factoriel(int valeur);

int main(void) {
    assert(factoriel(0) == 1);
    assert(factoriel(1) == 1);
    assert(factoriel(3) == 6);
    assert(factoriel(5) == 120);

    int valeur;

    printf("Entrez un nombre: ");
    scanf("%d", &valeur);

    printf("%d! vaut %d.", valeur, factoriel(valeur));

    return EXIT_SUCCESS;
}

int factoriel(int valeur) {
    int result = 1;

    for (int i = 2; i <= valeur; i++) {
        result *= i;
    }

    return result;
}
