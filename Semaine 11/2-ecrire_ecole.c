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
void ecrire_ecole(char* nom_ficher, const t_ecole* ecole);

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

    // Exercice 2
    char* nom_fichier = "2-ecrire_ecole.txt";
    ecrire_ecole(nom_fichier, &tab_ec[0]);

    system("pause");
    return EXIT_SUCCESS;
}

/******************************************************************************/
/*                           DEFINITION DES FONCTION                          */
/******************************************************************************/

int nb_cours_total(const t_ecole* ecole) {
    int nb_cours = 0;

    for (int i = 0; i < ecole->nb_ens; i++)
        nb_cours += ecole->enseignants[i].nb_cours;

    return nb_cours;
}

void ecrire_ecole(char* nom_ficher, const t_ecole* ecole) {
    FILE* f;

    f = fopen(nom_ficher, 'w');

    if (f) {  // Si le fichier est bien ouvert
        fprintf(f, "Nom de l'ecole\t: %s\n", ecole->nom);
        fprintf(f, "Nb. d'enseignants\t: %s\n", ecole->nb_ens);
        fprintf(f, '\n');  // Ligne vide

        for (int i = 0; i < ecole->nb_ens; i++) {  // Pour chaque enseignant
            fprintf(f, "\tNumero\t: %s\n", ecole->enseignants[i].numero);
            fprintf(f, "\tNom\t: %s\n", ecole->enseignants[i].identite.nom);
            fprintf(f, "\tPrenom\t: %s\n", ecole->enseignants[i].identite.prenom);
            fprintf(f, "\tNb. cours\t: %s\n", ecole->enseignants[i].nb_cours);
            fprintf(f, '\n');  // Ligne vide

            for (int j = 0; j < ecole->enseignants[i].nb_cours; j++) {  // Pour chaque cours
                fprintf(f, "\t\tSigle du cours\t: %s\n", ecole->enseignants[i].cours_enseignes[j].sigle);
                fprintf(f, "\t\tDescription\t: %s\n", ecole->enseignants[i].cours_enseignes[j].desc);
            }

            fprintf(f, '\n');  // Ligne vide
        }

        fclose(f);
    }
}
