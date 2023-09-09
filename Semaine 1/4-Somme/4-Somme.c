/*
    Écrivez une fonction "main" qui permet de calculer la somme de plusieurs entiers saisis au clavier et compris dans l'intervalle 1 à 10.
    Pour ce faire,  déclarez deux variables `nombre` et `somme` de type entier long ainsi que trois constantes FIN, MIN et MAX ayant les valeurs 0, 1 et 10.
    Ensuite, tant que nombre n'est pas égal à FIN, saisissez un nombre au clavier (une valeur entière que vous mettez dans nombre).
    Si le nombre est dans l'intervalle MIN à MAX, ajoutez ce nombre a la somme. Sinon, si le nombre n'est pas égal à FIN, affichez un message d'erreur. 
    Finalement, affichez la somme obtenue à l'écran.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entrée/sortie
#include <stdlib.h> // Pour les fonctions d'entrée/sortie et la fonction `system()`

int main() {
    int FIN = 0, MIN = 1, MAX = 10;
    
    long nombre, somme = 0;

    while (1) {
        printf("Entrez une valeur comprise entre %d et %d: ", MIN, MAX);
        scanf_s("%d", &nombre);

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
}
