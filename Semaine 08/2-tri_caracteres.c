/*
    But du programme: Saisie d'une chaine de caracteres au clavier, affichage des chiffres seulement
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 80

int main(void) {
    int valeur,
        somme = 0,
        i = 0,
        c;
    char caracteres[MAX_CHAR];

    printf("Entrez la chaine de caracteres: ");
    scanf("%s", caracteres);

    while ((c = caracteres[i]) != '\0') {
        if ((c >= '0') && (c <= '9')) {
            somme += c - (int)'0';  // Ajout de la difference des codes ASCII
        }
        i++;
    }

    printf("La somme est: %d\n", somme);

    system("pause");
    return EXIT_SUCCESS;
}
