/*
    Imaginons d'abord que nous nous trouvons devant une grille a la position (0,0).
    Le but du programme est d'effectuer des deplacements aleatoires tant et
        aussi longtemps que le deplacement est situe a l'interieur d'un cercle
        de rayon R (qui sera fourni par l'utilisateur).
    A chaque coup, vous vous deplacez au hasard de la position (x, y) a une des
        quatre positions voisines (x+1, y), (x-1, y), (x, y+1), ou (x, y-1).
    Tant que x^2 + y^2 <= R^2, le programme continue les deplacements.
    A la fin, le programme affiche le nombre de deplacements effectues.
    AIDE : Generez un nombre aleatoire dans l'intervalle [0, 3] pour connaitre
        la direction a prendre.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define square(a) ((a) * (a))

// Cette fonction verifie une position dans un cercle de rayon r
int position_valide(int x, int y, int z);
int nombre_aleatoire(int min, int max);

int main(void) {
    // Initialisation des variables
    int rayon,
        pos_x = 0,
        pos_y = 0;
    long long nombre_deplacements = 0;

    // Initialisation de l'aleatoire
    srand(time(NULL));

    printf("Entrez le rayon du cercle: ");
    scanf("%d", &rayon);

    while (position_valide(pos_x, pos_y, rayon)) {
        int deplacement_x = nombre_aleatoire(-1, 1);
        int deplacement_y = nombre_aleatoire(-1, 1);

        pos_x += deplacement_x;
        pos_y += deplacement_y;

        // Verification que le deplacement est non-nul
        if (deplacement_x || deplacement_y) {
            nombre_deplacements++;
        }
    }

    printf("%d deplacements ont ete effectues avant de sortir du cercle de rayon %d.\n",
           nombre_deplacements, rayon);

    system("pause");
    return EXIT_SUCCESS;
}

int position_valide(int x, int y, int r) {
    return square(x) + square(y) <= square(r);
}

int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}
