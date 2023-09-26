/*
    Maximum de deux valeurs
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max_des_deux(int entier1, int entier2);

int main(void) {
    int x, y, lemax;

    printf("Quelle est la premiere valeur?: ");
    scanf_s("%d", &x);

    printf("Quelle est la deuxieme valeur?: ");
    scanf_s("%d", &y);

    lemax = max_des_deux(x, y);

    printf("Le maximum entre %d et %d est: %d\n", x, y, lemax);

    return EXIT_SUCCESS;
}

/*
int max_des_deux(int entier1, int entier2) {
    if (entier1 > entier2) {
        return entier1;
    }
    
    return entier2;
}
*/

// (Pour flex:)
int max_des_deux(int entier1, int entier2) {
    return (entier1 > entier2) ? entier1 : entier2;
}
