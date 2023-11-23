/*
    Somme des chiffres d'un nombre
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, tot = 0;

    printf("Entrez une valeur: ");
    scanf("%d", &x);

    while (x) {
        tot += x % 10;
        x /= 10;
    }

    printf("La somme de ses chiffres est: %d\n", tot);

    system("pause");
    return EXIT_SUCCESS;
}
