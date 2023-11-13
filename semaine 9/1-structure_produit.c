/*
    But du programme: Exercice de creation de structures
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

#define LONGUEUR_NUM_SERIE 11

typedef struct {
    char num_serie[LONGUEUR_NUM_SERIE];  // Type tableau statique
    char *nom;                           // Type tableau dynamique
    int stock;
} Produit;
