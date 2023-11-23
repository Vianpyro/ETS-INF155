/*
	Verifier qu'un entier est compris entre deux bornes
*/
#include <stdio.h>
#include <stdlib.h>

int entier_valide(int min, int max);

int main(void) {
    int min, max;

    printf("Entrez les bornes minimum et maximum: ");
    scanf("%d%d", &min, &max);

    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }

    printf("%d est un entier valide compris entre %d et %d!", entier_valide(min, max), min, max);

    return EXIT_SUCCESS;
}

int entier_valide(int min, int max) {
    int entier = 0;

    printf("Entrez la valeur a valider: ");
    scanf("%d", &entier);

    while (entier < min || entier > max) {
        printf("Entrez une valeur comprise entre %d et %d: ", min, max);
        scanf("%d", &entier);
    }
    return entier;
}
