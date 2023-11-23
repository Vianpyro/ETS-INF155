/*
    Definir la fonction "nb_termes()" dont le prototype est : int nb_termes(int max);
    Cette fonction doit calculer et retourner le nombre de termes necessaires
        pour que la serie (1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...etc)
        depasse la valeur "max" recue en parametre.
    La serie est definie comme la somme des valeurs de 1 a n.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int nb_termes(int max);

int main(void) {
    int max, termes;

    printf("Entrez la valeur 'max': ");
    scanf("%d", &max);

    termes = nb_termes(max);

    printf("Il faud %d termes pour depasser %d.\n", termes, max);

    system("pause");
    return EXIT_SUCCESS;
}

int nb_termes(int max) {
    int somme = 0, i = 1;

    while ((somme += i++) < max)
        ;

    return i;
}
