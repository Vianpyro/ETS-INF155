/*
    Fonction reçoit nombre entier en parametre et affiche tous les diviseurs de ce nombre.
    La fonction retourne le nombre de diviseurs affiches.
    Dans « main », saisir un entier au clavier, appel a fonction et affichage du resultat.
*/
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int diviseurs(int valeur);

int main(void) {
    assert(diviseurs(4) == 3);

    int valeur;

    printf("Entrez une valeur entiere dont vous souhaitez connaitre les diviseurs: ");
    scanf("%d", &valeur);

    printf("%d a %d diviseurs...", valeur, diviseurs(valeur));

    return EXIT_SUCCESS;
}

int diviseurs(int valeur) {
    int compteur = 0;
    for (int i = 1; i <= valeur; i++) {
        if (valeur % i == 0) {
            compteur++;
            printf("%d est un diviseur de %d.\n", i, valeur);
        }
    }
    return compteur;
}
