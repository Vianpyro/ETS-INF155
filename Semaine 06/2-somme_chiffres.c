/*
    But du programme: de saisir une chaine de caracteres et afficher la somme.
*/
#include <stdio.h>   // Pour la fonction printf et scanf
#include <stdlib.h>  // Pour la macro EXIT_SUCCESS et la fonction system

#define MAX_CHAR 30

int main(void) {
    char chaine[MAX_CHAR],
        somme = 0;

    printf("Entrez la chaine de valeurs a additionner: ");
    scanf("%s", &chaine);

    for (int i = 0; chaine[i] != '\0'; i++) {
        char c = chaine[i];
        if (c >= '0' && c <= '9')
            somme += (c - '0');
    }

    printf("La somme est: %d\n", somme);

    system("pause");
    return EXIT_SUCCESS;
}
