/*
    Completion d'un code "a trous" avec les fonctions des exercices precedents
*/
/***************************************************************************************
 * Programme qui valide une date dont l'annee
 * est superieure a une annee donnee par ANNEE_MIN et inferieure a ANNEE_MAX.
 *
 * L'annee sera entree suivi du mois et le jour pour
 * finalement afficher la date sous le format jour/mois/annee
 * Le mois sera affiche sous forme litterale.
 *
 * Auteur : Pierre Belisle, Eric The
 *
 ***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define JOUR_MIN 1

#define ANNEE_MIN 1900
#define ANNEE_MAX 3000

// Pour la lisibilite lors de l'affichage.
#define JANVIER 1
#define FEVRIER 2
#define MARS 3
#define AVRIL 4
#define MAI 5
#define JUIN 6
#define JUILLET 7
#define AOUT 8
#define SEPTEMBRE 9
#define OCTOBRE 10
#define NOVEMBRE 11
#define DECEMBRE 12

/***************************************************************************************/
/*                            DECLARATIONS DES FONCTIONS                               */
/***************************************************************************************/

int saisir_annee(void);
int saisir_mois(void);
int nbr_jours_max(int annee, int mois);
int annee_bisextile(int annee);
int saisir_jour(int min, int max);
void afficher_mois(int mois);

/***************************************************************************************/
int main(void) {
    // Constituera la date a valider.
    int annee;
    int mois;
    int jour;
    int nb_jour_max_mois; // Sert au calcul du nombre de jours par mois.

    // Sous programme de saisie sans parametre qui utilise les constantes
    // ANNEE_MIN et ANNEE_MAX en entrees.
    annee = saisir_annee();

    // Sous programme de saisie sans parametre qui utilise les constantes
    // JANVIER et DECEMBRE en entrees.
    mois = saisir_mois();

    // Exemple de fonction de calcul.
    nb_jour_max_mois = nbr_jours_max(annee, mois);

    // Procedure de saisie du jour avec parametres.
    jour = saisir_jour(JOUR_MIN, nb_jour_max_mois);

    // Afficher le jour.
    printf("\nLa date est le %d ", jour);

    // Procedure d'affichage avec parametres (sans valeur de retour).
    afficher_mois(mois);

    // afficher l'annee
    printf(" %d\n\n", annee);

    system("pause");

    return EXIT_SUCCESS;
}

/***************************************************************************************/
// Saisie et retourne une annee entre ANNEE_MIN et ANNEE_MAX.
int saisir_annee(void) {
    int annee; // l'annee a saisir

    while (annee < ANNEE_MIN || annee > ANNEE_MAX) {
        printf("Entrez une annee comprise entre %d et %d: ", ANNEE_MIN, ANNEE_MAX);
        scanf("%d", &annee);
    }

    return annee;
}

/***************************************************************************************/
// Saisie et retourne un mois valide entre JANVIER et DECEMBRE.
int saisir_mois(void) {
    int mois; // le mois a saisir

    while (mois < JANVIER || mois > DECEMBRE) {
        printf("Entrez un mois compris entre %d et %d: ", JANVIER, DECEMBRE);
        scanf("%d", &mois);
    }

    return mois;
}

/***************************************************************************************/
// Retourne le nombre de jours maximum selon le mois et l'annee.
int nbr_jours_max(int annee, int mois) {
    // Utilisation d'un switch car demande dans l'ennoncee
    switch (mois) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 28 + annee_bisextile(annee);
        default:
            return 0;
    }

    return 0;
}

/***************************************************************************************/
//  Retourne 1 si l'annee est bissextile et 0 sinon.
int annee_bisextile(int annee) {
    if (annee % 400 == 0) return 1;
    if (annee % 100 == 0) return 0;
    if (annee % 4 == 0) return 1;

    return 0;
}

/***************************************************************************************/
// Saisie et retourne un jour valide entre min et max.
int saisir_jour(int min, int max) {
    int jour; // le jour a saisir

    do {
        printf("Entrez un jour compris entre %d et %d: ", min, max);
        scanf("%d", &jour);
    } while (jour < min || jour > max);

    return jour;
}

/***************************************************************************************/
// Affiche le mois en texte.
void afficher_mois(int mois) {
    switch (mois) {
        case 1: printf("janvier"); break;
        case 2: printf("fevrier"); break;
        case 3: printf("mars"); break;
        case 4: printf("avril"); break;
        case 5: printf("mai"); break;
        case 6: printf("juin"); break;
        case 7: printf("juillet"); break;
        case 8: printf("aout"); break;
        case 9: printf("septembre"); break;
        case 10: printf("octobre"); break;
        case 11: printf("novembre"); break;
        case 12: printf("decembre"); break;
        default: printf("mois invalide");
    }
}
