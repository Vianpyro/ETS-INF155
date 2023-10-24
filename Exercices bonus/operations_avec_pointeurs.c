/*
    Ecrire un programme qui effectue des operations de base sur des variables en utilisant des pointeurs.

    Instructions :
        - Declarer et initialiser deux variables entieres, par exemple int a et int b.
        - Declarer deux pointeurs vers des entiers, par exemple int *ptr_a et int *ptr_b, et les initialiser pour qu'ils pointent respectivement vers a et b.
        - Utiliser les pointeurs pour effectuer les operations suivantes et affichez les resultats a chaque etape :
            - Additionner a et b en utilisant les pointeurs, puis afficher le resultat.
            - Soustraire b de a en utilisant les pointeurs, puis afficher le resultat.
            - Multiplier a par 2 en utilisant le pointeur ptr_a, puis afficher le resultat.
            - Diviser b par 2 en utilisant le pointeur ptr_b, puis afficher le resultat.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#define FFLUSH while(getchar() != '\n') {} // A inserer devant tous les scanf("%c", ...)!

#define MAX 20

int main(void) {
    // Initialisation du generateur aleatoire
    srand(time(NULL));

    // Initialisation des variables
    int a = rand() % MAX + 1;
    int b = rand() % MAX + 1;
    int *ptr_a = &a;
    int *ptr_b = &b;

    // Situation initiale
    printf("Situation initiale: \n- a = %d\n- b = %d\n- ptr_a = %x\n- ptr_b = %x\n", a, b, &ptr_a, &ptr_b);

    // Addition
    int somme = *ptr_a + *ptr_b;
    printf("Somme: a + b = %d\n", somme);

    // Soustraction
    int difference = *ptr_a - *ptr_b;
    printf("Difference: a - b = %d\n", difference);

    // Multiplication
    *ptr_a *= 2;
    printf("Multiplication: a * 2 = %d\n", a);

    // Division
    *ptr_b /= 2;
    printf("Division: b / 2 = %d\n", b);

    system("pause");
    return EXIT_SUCCESS;
}
