/*
    Transformer un if-else en switch case
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void afficher_mois(int mois);

int main(void) {
    for (int i = 0; i <= 13; i++) {
        printf("%d: ", i);
        afficher_mois(i);
    }

    return EXIT_SUCCESS;
}

void afficher_mois(int mois) {
    // Ne pas oublier les "break" apres chaque affichage car pas de return donc fonction continue!
    switch (mois) {
        case 1: printf("jan"); break;
        case 2: printf("fev"); break;
        case 3: printf("mars"); break;
        case 4: printf("avr"); break;
        case 5: printf("mai"); break;
        case 6: printf("juin"); break;
        case 7: printf("juil"); break;
        case 8: printf("aout"); break;
        case 9: printf("sept"); break;
        case 10: printf("oct"); break;
        case 11: printf("nov"); break;
        case 12: printf("dec"); break;
        default: printf("n'est pas un mois valide!");
    }
    printf("\n");
}
