/*
    Calcul pour rendre la monnaie a une caisse avec pointeurs (au Canada)
*/
#include <stdio.h>
#include <stdlib.h>

#define NB_MONNAIES 12

void rendre_monnaie(float facture, float paye, int monnaie_rendue[]);
int somme_list(const int liste[], size_t longueur_liste);

int main(void) {
    const char *monnaies[NB_MONNAIES] = {
        "billet(s) de cent",
        "billet(s) de cinquante",
        "billet(s) de vingt",
        "billet(s) de dix",
        "billet(s) de cinq",
        "piece(s) de deux",
        "piece(s) de un",
        "piece(s) de 50 sous",
        "piece(s) de 25 sous",
        "piece(s) de 10 sous",
        "piece(s) de 5 sous",
        "piece(s) de 1 sous"};
    int monnaie_rendue[NB_MONNAIES];
    float facture, paye;

    // Initialiser tous les elements a zero
    for (int i = 0; i < NB_MONNAIES; i++) {
        monnaie_rendue[i] = 0;
    }

    // Demande du prix de la facture et du prix paye par le client
    printf("Quel est le prix sur la facture?: ");
    scanf("%f", &facture);

    printf("Quel montant a ete paye?: ");
    scanf("%f", &paye);

    // Calcule de la monnaie a rendre
    rendre_monnaie(facture, paye, monnaie_rendue);

    printf("%s", (facture <= paye) ? "Il faut rendre" : "Il manque");
    for (unsigned char i = 0; i < NB_MONNAIES; i++) {
        if (monnaie_rendue[i] > 0)
            printf(", %d %s", monnaie_rendue[i], monnaies[i]);
    }
    printf(".\n");

    system("pause");
    return EXIT_SUCCESS;
}

void rendre_monnaie(float facture, float paye, int monnaie_rendue[]) {
    int montant_a_rendre;
    const float valeurs[NB_MONNAIES] = {
        10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};

    facture *= 100;
    paye *= 100;

    montant_a_rendre = (paye >= facture) ? paye - facture : facture - paye;

    for (int i = 0; i < NB_MONNAIES; i++) {
        if (montant_a_rendre >= valeurs[i]) {
            monnaie_rendue[i] = montant_a_rendre / valeurs[i];
            montant_a_rendre -= monnaie_rendue[i] * valeurs[i];
        } else {
            monnaie_rendue[i] = 0;
        }
    }
}

int somme_list(const int liste[], size_t longueur_liste) {
    int somme = 0;

    for (size_t i = 0; i < longueur_liste; somme += liste[i++])
        ;

    return somme;
}
