

// Permet de désactiver certains warnings du compilateur
#define _CRT_SECURE_NO_WARNINGS

// Librairies usuelles à inclure
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*=========================================================*/
/*                  LES CONSTANTES                         */
/*=========================================================*/
#define NB_VAL_MIN 10  // nombre minimal de valeurs aléatoires
#define ALEA_MIN -100  // borne inférieure des valeurs aléatoires
#define ALEA_MAX 100   // borne supérieure des valeurs aléatoires

/*=========================================================*/
/*                  LES FONCTIONS                          */
/*=========================================================*/
// Fonction qui retourne un nombre aléatoire entre [min, max]
int nombre_aleatoire(int min, int max);
int transferer(int *a, int *b, int *c);
int valeurs_alea(int nb_valeurs, int min, int max, int *nb_pos, int *nb_neg);

/*===========================================================================*/
/*===========================================================================*/
// Programme principal:
int main(void) {  // les variables pour le test de la fonction "transferer()"
    int x1 = 12, x2 = -5, x3 = 3;
    int val_retiree = 0;

    // les variables pour le test de la fonction "valeurs_alea()"
    int etendue;                 // l'étendue (max- min) des valeurs générées
    int nb_valeurs;              // le nombre de valeurs à générer
    int nb_pos = 0, nb_neg = 0;  // le nb. de positifs, nb. de négatifs (déjà initialisé)

    // TEST 1 : transfert des trois entiers
    val_retiree = transferer(&x1, &x2, &x3);  //*** APPEL à COMPLÉTER ***

    printf("TEST 1\nApres le transfert: x1 = %d, x2 = %d, x3 = %d (valeur retiree = %d)\n",
           x1, x2, x3, val_retiree);

    // TEST 2 : compiler des statistiques sur les nombres aléatoires
    srand(time(NULL));

    // on demande le nombre de valeurs (doit être > 10)
    do {
        printf("\nTEST 2 - Entrez un nombre de valeurs plus grand que 10 : ");
        scanf("%d", &nb_valeurs);
    } while (nb_valeurs <= NB_VAL_MIN);

    etendue = valeurs_alea(nb_valeurs, ALEA_MIN, ALEA_MAX, &nb_pos, &nb_neg);

    printf("\n\n%d valeurs aleatoires : %d positifs, %d negatifs, etendue = %d\n",
           nb_valeurs, nb_pos, nb_neg, etendue);

    // on termine avec le standard... "APPUYEZ UNE TOUCHE.."
    system("pause");
    return EXIT_SUCCESS;
}

/*===========================================================================*/
// Fonction qui retourne un nombre aléatoire entre [min, max]
int nombre_aleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

/***************************************************************************************/
// Fonction qui affiche des valeurs aléatoires et retourne la difference entre la plus grande et la plus petite
int valeurs_alea(int nb_valeurs, int min, int max, int *nb_pos, int *nb_neg) {
    int i,
        valeur_aleatoire,
        plus_petite = max + 1,  // Début à max + 1 comme ca n'importe quelle valeur dans l'interval [min, max] sera plus petite
        plus_grande = min - 1,  // Début à min - 1 comme ca n'importe quelle valeur dans l'interval [min, max] sera plus grande
        etendue;

    for (i = 0; i < nb_valeurs; i++) {
        valeur_aleatoire = nombre_aleatoire(min, max);
        printf("%d, ", valeur_aleatoire);

        if (valeur_aleatoire < plus_petite)
            plus_petite = valeur_aleatoire;

        if (valeur_aleatoire > plus_grande)
            plus_grande = valeur_aleatoire;

        if (valeur_aleatoire >= 0)
            (*nb_pos)++;

        if (valeur_aleatoire < 0)
            (*nb_neg)++;
    }

    etendue = plus_grande - plus_petite;

    return etendue;
}

/***************************************************************************************/
// Fonction qui intervertis des valeurs en utilisant des pointeurs et retourne la premiere valeur
int transferer(int *a, int *b, int *c) {
    int temp;

    temp = *a;
    *a = *b;
    *b = *c;
    *c = 0;

    return temp;
}
