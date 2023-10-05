/*
    Ecrire une fonction qui retourne le nombre d'elements positifs dans un tableau et afficher leur somme.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int posi(double tab[], int longueur, double *total);

int main(void) {
    double tablo[MAX] = {1.3, -1.5, 3.6, 8.0, -4.3};
    double somme_pos = 0;
    int nb_positifs;

    nb_positifs = posi(tablo, MAX, &somme_pos);

    printf("Il y'a %d valeur(s) positives pour un total de %.2lf\n", nb_positifs, somme_pos);

    system("pause");
    return EXIT_SUCCESS;
}

int posi(double tab[], int longueur, double *total) {
    int positifs = 0;

    for (int i = 0; i < longueur; i++)
        if (tab[i] > 0) {
            positifs += 1;
            *total += tab[i];
        }

    return positifs;
}
