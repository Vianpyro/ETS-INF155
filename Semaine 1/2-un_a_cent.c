/*
    Valider qu'un nombre est compris entre 1 et 100.
    Pour ce faire, definire deux constantes avec les valeurs 1 et 100 et une variable de type entier.
    Dans une boucle, saisir une valeur au clavier, verifier qu'elle est entre 1 et 100,
        si elle ne l'est pas, afficher un message d'erreur et redemander a nouveau la valeur.
    La boucle se termine lorsque le nombre est valide.
    On affiche ensuite ce nombre.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entree/sortie
#include <stdlib.h> // Pour les fonctions d'entree/sortie et la fonction `system()`

#define VALEUR_MIN 1
#define VALEUR_MAX 100

int main(void) {
    int valeur;

    while (1) {
        printf("Entrez une valeur comprise entre %d et %d (inclus) : ", VALEUR_MIN, VALEUR_MAX);
        scanf("%d", &valeur);

        if (valeur >= VALEUR_MIN && valeur <= VALEUR_MAX) 
            break;
        
        printf("Erreur, cette valeur (%d) n'est pas comprise entre %d et %d!\n", valeur, VALEUR_MIN, VALEUR_MAX);
    }

    printf("%d\n", valeur);

    system("pause");
}
