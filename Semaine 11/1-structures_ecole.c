/*
    But du programme: <...>
*/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************************************************************/
/*                            DEFINITION DES MACROS                           */
/******************************************************************************/

#define NB_ECOLES 10
#define NB_ENS 50
#define NB_COURS 3

/******************************************************************************/
/*                            DEFINITION DES TYPES                            */
/******************************************************************************/

typedef struct {
    char sigle[7];
    char desc[80];
} t_cours;

typedef struct {
    char nom[80];
    char prenom[80];
} t_personne;

typedef struct {
    char numero[7];
    t_personne identite;
    t_cours* cours_enseignes;
    int nb_cours;
} t_enseignant;

typedef struct {
    char nom[80];
    t_enseignant* enseignants;
    int nb_ens;
} t_ecole;

/******************************************************************************/
/*                          PROTOTYPES DES FONCTIONS                          */
/******************************************************************************/

int nb_cours_total(const t_ecole* ecole);

/******************************************************************************/
/*                             PROGRAMME PRINCIPAL                            */
/******************************************************************************/

int main(void) {
    // A. Definition d'un tableau dynamique d'ecoles
    t_ecole* tab_ec;

    // B. Allocation de l'espace memoire pour NB_ECOLES ecoles
    tab_ec = (t_ecole*)calloc(NB_ECOLES, sizeof(t_ecole));

    // C. Allocation de l'espace memoire pour NB_ENS enseignants par ecole
    for (int i = 0; i < NB_ECOLES; i++) {
        tab_ec[i].enseignants = (t_enseignant*)calloc(NB_ENS, sizeof(t_enseignant));
        tab_ec[i].nb_ens = NB_ENS;
    }

    // D. Allocation de l'espace memoire pour NB_COURS aux enseignants
    for (int i = 0; i < NB_ECOLES; i++)
        for (int j = 0; j < NB_ENS; j++) {
            tab_ec[i].enseignants[j].cours_enseignes = (t_cours*)calloc(NB_COURS, sizeof(t_cours));
            tab_ec[i].enseignants[j].nb_cours = NB_COURS;
        }

    // E. Affichage du nom de la troisieme ecole
    printf("%s\n", tab_ec[2].nom);

    // F. Affichage du numero du deuxieme professeur de la premiere ecole
    printf("%s\n", tab_ec[0].enseignants[1].numero);

    // G. Affichage du nom du deuxieme professeur de la premiere école
    printf("%s\n", tab_ec[0].enseignants[1].identite.nom);

    // H. Affichage du sigle du troisieme cours enseigne par le deuxieme professeur de la troisieme ecole
    printf("%s\n", tab_ec[2].enseignants[2].cours_enseignes->sigle);

    // I. Affichage du nombre total de cours enseignes par TOUS les enseignants de l'ecole recue
    printf("%d\n", nb_cours_total(&tab_ec[0]));

    system("pause");
    return EXIT_SUCCESS;
}

/******************************************************************************/
/*                           DEFINITION DES FONCTION                          */
/******************************************************************************/

int nb_cours_total(const t_ecole* ecole) {
    int nb_cours = 0;

    for (int i = 0; ecole->nb_ens; i++)
        nb_cours += ecole->enseignants[i].nb_cours;

    return nb_cours;
}
