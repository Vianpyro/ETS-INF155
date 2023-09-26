/* 
    Fonction reçoit 2 entiers ("nombre" et "pos") et renvoie le chiffre à la position "pos" donnée du "nombre".
    Ex: appel avec nombre "15670" et la position "2", fonction retourne "7".
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int position(int valeur, int position);

int main(void) {
    assert(position(4321, 2) == 2);

    int valeur, pos;

    printf("Entrez un entier et la position du chiffre que vous cherchez (de droite a gauche): ");
    scanf("%d%d", &valeur, &pos);

    printf("La valeur en position %d de %d est: %d", pos, valeur, position(valeur, pos));

    return EXIT_SUCCESS;
}

int position(int valeur, int position) {
    // On enleve 1 a la position car la boucle commence a 0
    while (position - 1 > 0) {
        valeur /= 10;
        position--;
    }

    return valeur % 10;
}
