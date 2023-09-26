/*
    Maximum de trois valeurs
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max_des_trois(int entier1, int entier2, int entier3);

int main(void) {
    int x, y, z, lemax;

    printf("Quelle est la premiere valeur?: ");
    scanf_s("%d", &x);

    printf("Quelle est la deuxieme valeur?: ");
    scanf_s("%d", &y);

    printf("Quelle est la troisiemevaleur?: ");
    scanf_s("%d", &z);

    lemax = max_des_trois(x, y, z);

    printf("Le maximum entre %d, %d et %d est: %d\n", x, y, z, lemax);

    return EXIT_SUCCESS;
}

int max_des_deux(int entier1, int entier2) {
    return (entier1 > entier2) ? entier1 : entier2;
}

int max_des_trois(int entier1, int entier2, int entier3) {
    if (max_des_deux(entier1, entier2) == entier1) {
        return max_des_deux(entier1, entier3);
    }

    return max_des_deux(entier2, entier3);
}
