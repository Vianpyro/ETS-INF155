/*
        Auteur: VEREMME Vianney - Groupe 3
        Date de creation: 03/10/2023
        But du programme: Exemple de conversion en devises etrangeres avec un switch..case
*/
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/***************************************************************************************/
/*                              PROTOTYPES DES FONCTIONS                               */
/***************************************************************************************/

int saisir_devise(void);
double calcul_salaire(double heures, double taux, int pays);
unsigned char caractere_devise(int pays);

/***************************************************************************************/
/*                                 PROGRAMME PRINCIPAL                                 */
/***************************************************************************************/

int main(void) {
    assert(calcul_salaire(35.5, 45.7525, 1) == 1624.21375);
    assert(calcul_salaire(35.5, 45.7525, 2) == 812.106875);
    assert((int)calcul_salaire(35.5, 45.7525, 3) == 1900);

    double heures, taux, brut;  // nb. d'heures, taux horaire et salaire brut
    int pays;                   // le code-pays de la devise desiree
    unsigned char devise;       // le caractere-devise (pour l'affichage)

    printf("\nEntrez les heures travaillees: ");
    scanf("%lf", &heures);

    printf("\nEntrez le taux horaire       : ");
    scanf("%lf", &taux);

    // Etape 1 : Saisie et validation du code-pays
    pays = saisir_devise();

    // Etape 2 : Calcul du salaire de la semaine
    brut = calcul_salaire(heures, taux, pays);

    // Etape 3 : Choix du caractere-devise selon le pays choisi
    devise = caractere_devise(pays);

    // Affichage du resultat final
    printf("\nSalaire brut      : %.2lf %c\n", brut, devise);
    system("pause");
    return EXIT_SUCCESS;
}

/***************************************************************************************/
/*                               DEFINITION DES FONCTIONS                              */
/***************************************************************************************/

// Fonction qui retourne le code-pays
int saisir_devise(void) {
    int pays;

    do {
        printf("\nQuel devises (1-Canada, 2-Angleterre, 3-Suisse) ? ");
        scanf("%d", &pays);
    } while (pays < 1 || pays > 3);

    return pays;
}

/***************************************************************************************/
// Fonction qui calcul le salaire brut et ajuste selon le pays
double calcul_salaire(double heures, double taux, int pays) {
    double brut;

    if (heures <= 40)
        brut = heures * taux;
    else
        brut = taux * (40 + 1.5 * (heures - 40));  // calcul des heures supplementaires

    // avec conversion si necessaire :
    if (pays == 2)
        brut /= 2.00;
    else if (pays == 3)
        brut /= 0.8547;

    return brut;
}

/***************************************************************************************/
// Fonction qui retourne le symbole de la devise du pays
unsigned char caractere_devise(int pays) {
    unsigned char devise = 0;

    switch (pays) {
        case 1:
            devise = '$';
            break;
        case 2:
            devise = 156;  // Code 156 = symbole de livre anglaise
            break;
        case 3:
            devise = 'F';  // 'F' = Francs Suisses
            break;
        default:
            printf("Code-pays invalide (%d)", pays);
    }

    return devise;
}
