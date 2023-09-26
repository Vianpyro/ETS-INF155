/*
	Verifier qu'un entier est compris entre deux bornes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int entier_valide(int min, int max);

int main(void) {
    int min, max;

    printf("Entrez les bornes minimum et maximum: ");
    scanf_s("%d%d", &min, &max);

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
    scanf_s("%d", &entier);

    while (entier < min || entier > max) {
        printf("Entrez une valeur comprise entre %d et %d: ", min, max);
        scanf_s("%d", &entier);
    }
    return entier;
}
