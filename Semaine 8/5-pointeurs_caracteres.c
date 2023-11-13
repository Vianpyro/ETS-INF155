/*
    But du programme: Exercice d'allocation dynamique de memoire
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Pour `strcpy`

#define LONGEUR_MAX 10
#define STRING_1 "abcdefghi"
#define STRING_2 "bcdefghij"

int main(void) {
    char *caractere_1,
        *caractere_2;

    // Allocation dynamique de la memoire
    caractere_1 = (char *)calloc(LONG_MAX, sizeof(char));
    caractere_2 = (char *)calloc(LONG_MAX, sizeof(char));

    // Copie des chaines de caracteres
    strcpy(caractere_1, STRING_1);
    strcpy(caractere_2, STRING_2);

    // Si les 2 chaînes sont différentes copier chaine 1 dans 2
    if (strcmp(caractere_1, caractere_2) != 0)
        strcpy(caractere_2, caractere_1);

    printf("%s\n", caractere_2);

    // Liberation de la memoire
    free(caractere_1);
    caractere_1 = NULL;

    free(caractere_2);
    caractere_2 = NULL;

    system("pause");
    return EXIT_SUCCESS;
}
