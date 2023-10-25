/*
    Ecrire un programme qui lit une sequence de nombres entiers.
    A la premiere valeur negative, la lecture des donnees s'arrete
        et les informations suivantes de la liste sont affichees a l'ecran :
            - le nombre d'entiers lus,
            - la valeur minimale,
            - la valeur maximale,
        (sans inclure la valeur negative).
    Si la liste est vide (donc, commence immediatement avec une valeur negative)
        le programme affiche 0, 0, 0.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>  // Optimisation pour le fun
#include <stdio.h>
#include <stdlib.h>

#define NB_ELEMENTS_MAX_TABLEAU 30

int main(void) {
    // Je m'amuse a faire le programme sans tableau car il n'est pas dit qu'il en faut un
    uint8_t compte = 0;
    int64_t valeur,
        minimum = 0,
        maximum = 0;

    // Lecture d'une sequence donnee par l'utilisateur
    printf("Entrez jusqu'a %d entiers:\n", NB_ELEMENTS_MAX_TABLEAU);

    while (compte < NB_ELEMENTS_MAX_TABLEAU) {
        scanf("%d", &valeur);
        if (valeur < 0) {
            printf(
                "%d entiers lus,\n"
                "%d est le minimum,\n"
                "%d est le maximum,\n",
                compte, minimum, maximum);
            break;
        } else if (valeur > maximum)
            maximum = valeur;
        else if (valeur < minimum)
            minimum = valeur;

        compte++;
    }

    system("pause");
    return EXIT_SUCCESS;
}
