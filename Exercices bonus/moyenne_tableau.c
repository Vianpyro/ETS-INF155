/*
    Calcul de la moyenne d'une liste de nombres
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#define FFLUSH while(getchar() != '\n') {} // A inserer devant tous les scanf()!

#define LEN_TABLEAU 10

int main(void) {
    float tableau[LEN_TABLEAU]; // Declaration tableau de 10 nombres reels
    float somme = 0, moyenne;

    // Entree des nombres
    printf("Entrez %d valeurs: ", LEN_TABLEAU);
    for (int i = 0; i < LEN_TABLEAU; i++) {
        scanf("%f", &tableau[i]);
    }

    // Calcul de la somme totale et de la moyenne
    for (int i = 0; i < LEN_TABLEAU; i++) {
        somme += tableau[i];
    }

    moyenne = somme / LEN_TABLEAU;

    printf("La moyenne est: %.2f\n", moyenne);

    system("pause");
    return EXIT_SUCCESS;
}
