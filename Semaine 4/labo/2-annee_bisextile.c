/*
    Annee bisextile (meme exercice qu'a la semaine 2 donc copie/colle...)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int nbr_jours_max(int annee, int mois);

int main(void) {
    int mois, annee;
    const char* mois_litteral[] = {
        "de janvier", "de fevrier", "de mars", "d'avril",
        "de mai", "de juin", "de juillet", "d'aout",
        "de septembre", "d'octobre", "de novembre", "de decembre"
    };

    assert(nbr_jours_max(2000, 2) == 29);
    assert(nbr_jours_max(2001, 2) == 28);

    printf("Entrez un mois et une annee: ");
    scanf("%d%d", &mois, &annee);
    
    printf("Il y'a %d jour au mois %s %d.\n", nbr_jours_max(annee, mois), mois_litteral[mois - 1], annee);

    return EXIT_SUCCESS;
}

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

int annee_bisextile(int annee) {
    if (annee % 400 == 0) return 1;
    if (annee % 100 == 0) return 0;
    if (annee % 4 == 0) return 1;

    return 0;
}
