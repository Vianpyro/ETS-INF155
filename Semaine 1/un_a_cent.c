/*
    Nous d�sirons valider qu�un nombre entr� par un utilisateur est entre 1 et 100.
    Pour ce faire, d�finissez deux constantes avec les valeurs 1 et 100 et une variable de type entier.
    Dans une boucle, saisissez une valeur au clavier, v�rifiez qu�elle est entre 1 et 100 
        et si elle ne l�est pas, affichez un message d�erreur et redemandez � nouveau la valeur.
    La boucle se termine lorsque le nombre est valide.
    On affiche ensuite ce nombre.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entr�e/sortie
#include <stdlib.h> // Pour les fonctions d'entr�e/sortie et la fonction `system()`

int main(void) {
    int VALEUR_MIN = 1;
    int VALEUR_MAX = 100;

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
