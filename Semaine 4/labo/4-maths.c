/*
    Programmation de diverses fonction mathematiques
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#define MAX_PRIME 10000

int comptage(int valeur);
int diviseurs(int valeur);
int pgcd(int a, int b);
int position(int valeur, int position);
int ppcm(int a, int b);
int prime(int valeur);
int prime_suivant(int valeur);

int main(void) {
    assert(comptage(123) == 3);
    assert(comptage(-4269) == 4);

    assert(diviseurs(1) == 1);
    assert(diviseurs(12) == 6);

    assert(pgcd(42, 69) == 3);
    assert(pgcd(12345678, 90) == 18);

    assert(position(123, 2) == 1);
    assert(position(4269, 0) == 9);

    assert(ppcm(42, 69) == 966);
    assert(ppcm(2, 16) == 16);

    assert(prime(13) == 1);
    assert(prime(4) == 0);

    assert(prime_suivant(13) == 17);
    assert(prime_suivant(1) == 2);

    for (int i = 1; i < 1000; i = prime_suivant(i)) {
        printf("%d ", i);
    }

    return EXIT_SUCCESS;
}

int diviseurs(int valeur) {
    int compteur = 0;
    
    for (int i = 1; i <= valeur; i++) {
        if (valeur % i == 0) {
            compteur++;
        }
    }

    return compteur;
}

int prime(int valeur) {
    return (diviseurs(valeur) > 2) ? 0 : 1;
}

int prime_suivant(int valeur) {
    while (++valeur < MAX_PRIME && !prime(valeur));
    return valeur;
}

int comptage(int valeur) {
    int nombre_chiffres = 0;

    for (; valeur != 0; valeur /= 10) {
        nombre_chiffres++;
    }

    return nombre_chiffres;
}

int position(int valeur, int position) {
    for (; position > 0; position--) {
        valeur /= 10;
    }

    return valeur % 10;
}

int pgcd(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) a = a - b;
        else b = b - a;
    }

    return (a == 0) ? b : a;
}

int ppcm(int a, int b) {
    return a / pgcd(a, b) * b;
}
