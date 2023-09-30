/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int saisir_nombre_positif(void);
int lire_obtenir_max(int n);

int main(void) {
    unsigned int n; // Doit etre positif
    float max;

    n = saisir_nombre_positif();
    max = lire_obtenir_max(n);

    printf("\nLa plus grande valeur est : %.2f\n", max);

    return EXIT_SUCCESS;
}

int saisir_nombre_positif(void) {
    int valeur;

    do {
        printf("Entrez le nombre (entier positif) de valeurs a rentrer: ");
        scanf("%d", &valeur);
    } while (valeur <= 0);

    return valeur;
}

int lire_obtenir_max(int n) {
    int cnt;
    float temp, max;

    printf("Entrez %d nombres: ", n);
    scanf("%f", &temp);

    max = temp;

    /* boucle pour lire et comparer les (n-1) autres valeurs */
    while (++cnt < n) {
        scanf("%f", &temp);
        if (max < temp)
            max = temp;
    }

    return max;
}
