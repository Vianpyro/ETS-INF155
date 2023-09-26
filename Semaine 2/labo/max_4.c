/*
    Maximum de quatre valeurs
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max_des_quatre(int entier1, int entier2, int entier3, int entier4);

int main(void) {
    int a, b, c, d, lemax;

    printf("Entrez quatres valeurs: ");
    scanf_s("%d%d%d%d", &a, &b, &c, &d);

    lemax = max_des_quatre(a, b, c, d);

    printf("Le maximum entre %d, %d, %d et %d est: %d\n", a, b, c, d, lemax);

    return EXIT_SUCCESS;
}

int max_des_deux(int entier1, int entier2) {
    return (entier1 > entier2) ? entier1 : entier2;
}

int max_des_trois(int entier1, int entier2, int entier3) {
    int max_local = max_des_deux(entier1, entier2);
    return (entier3 > max_local) ? entier3 : max_local;
}

int max_des_quatre(int entier1, int entier2, int entier3, int entier4) {
    int max_local = max_des_trois(entier1, entier2, entier3);
    return (entier4 > max_local) ? entier4 : max_local;
}
