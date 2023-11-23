/*
    Ecrire une fonction "main" qui permet de calculer la somme de plusieurs entiers saisis au clavier et compris dans l'intervalle 1 a 10.
    Pour ce faire,  declarer deux variables `nombre` et `somme` de type entier long ainsi que trois constantes FIN, MIN et MAX ayant les valeurs 0, 1 et 10.
    Ensuite, tant que nombre n'est pas egal a FIN, saisir un nombre au clavier.
    Si le nombre est dans l'intervalle [MIN, MAX], ajouter ce nombre a la somme. Sinon, afficher un message d'erreur.
    Finalement, afficher la somme obtenue a l'ecran.
*/

#include <stdio.h> // #include <stdio.h> pour les fonctions d'entr�e/sortie
#include <stdlib.h> // Pour les fonctions d'entr�e/sortie et la fonction `system()`

#define FIN 0
#define MIN 1
#define MAX 10

int main() {
    long nombre, somme = 0;

    while (1) {
        printf("Entrez une valeur comprise entre %d et %d: ", MIN, MAX);
        scanf("%d", &nombre);

        if (nombre == FIN) {
            printf("La veleur finale est: %d\n", somme);
            break;
        } else if (nombre < MIN || nombre > MAX) {
            printf("Erreur, cette valeur n'est pas comprise entre %d et %d!\n", MIN, MAX);
        } else {
            somme += nombre;
        }
    }

    system("pause");
    return EXIT_SUCCESS;
}
