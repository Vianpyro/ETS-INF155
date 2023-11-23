/*
    Corriger toutes les erreurs dans ce bloc et expliquer :

    #define MAX 10

    void main( ) {
        int a;
        scanf("%d", a);
        MAX = 2*a;
        printf("resultat = %d", MAX);
    }
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(void) {  // La fonction main ne retourne rien "void"
    int a;

    scanf("%d", &a);  // On donne l'adresse (pointeur) pour stocker une valeur
    // MAX = 2 * a;   // On ne peut tout simplement pas changer la valeur une macro

    printf("resultat = %d\n", a);  // On veut afficher la variable a, pas la macro MAX

    return EXIT_SUCCESS;  // On retourne 0 (pas de probleme)
}
