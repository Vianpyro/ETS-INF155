/*
    But du programme: Analyser une chaine de characteres et categoriser le type de chaque charactere
*/
#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>   // Pour les fonctions isalpha, isdigit, isspace, ispunct
#include <stdio.h>   // Pour la fonction printf
#include <stdlib.h>  // Pour la macro EXIT_SUCCESS et la fonction system
#include <string.h>  // Pour la fonction strlen

#define TAILLE_MAX 30

int main(void) {
    char chaine[TAILLE_MAX];
    int espace = 0,
        ponctuation = 0,
        alphabetique = 0,
        numerique = 0;
    int longueur;

    printf("Entrez la chaine a analyser: ");
    gets_s(chaine, TAILLE_MAX);  // Utilisation de gets_s car scanf s'arrete au premier espace

    longueur = strlen(chaine);

    for (int i = 0; i < longueur; i++) {
        char c = chaine[i];
        if (isspace(c))
            espace++;
        else if (ispunct(c))
            ponctuation++;
        else if (isalpha(c))
            alphabetique++;
        else if (isdigit(c))
            numerique++;
    }

    printf("\n%d espaces, %d ponctuations, %d alphabetiques, %d numeriques\n",
           espace, ponctuation, alphabetique, numerique);

    system("pause");
    return EXIT_SUCCESS;
}
