/*
    �crire un programme qui calcule le montant d�une facture pour des achats faits � la COOP ETS.
    Pour chaque item achet�, on doit demander la quantit� et le prix unitaire du produit.
    Apr�s chaque item entr�, le programme va demander si le client a d�autres items � entrer.
    La COOP offre 10% de r�duction si le montant total des achats d�passe $100.00.
    On applique ensuite les taxes (TPS & TVQ) de 15%.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entr�e/sortie
#include <stdlib.h> // Pour les fonctions d'entr�e/sortie et la fonction `system()`

int main(void) {
    // Taux de taxes et r�duction
    float TAXES = 0.15;
    float REDUCTION = 0.1;
    float SEUIL_REDUCTION = 100.00;

    // Initialisation du sous-total et de la variable de continuation
    float sous_total = 0;
    int continuer = 1;

    // Boucle principale pour la saisie des articles
    while (continuer) {
        // Saisie de la quantit�
        int quantite;
        printf("Quantite: ");
        scanf("%d", &quantite);

        // Saisie du prix unitaire
        float prix_unitaire;
        printf("Prix unitaire: ");
        scanf("%f", &prix_unitaire);

        // Calcul du sous-total
        sous_total += quantite * prix_unitaire;

        // Saisie de la r�ponse de l'utilisateur pour continuer
        printf("Ajouter d'autres items? [1 (oui)/0 (non)]: ");
        scanf("%d", &continuer);
    }

    // Calcul du total initial
    float total = sous_total;
    printf("Sous total: $%.2f%\n", sous_total);

    // V�rification de la r�duction applicable
    if (sous_total > SEUIL_REDUCTION) {
        float application_reduction = total * REDUCTION;
        printf("Reduction (%.2f%%): $%.2f%\n", REDUCTION * 100, application_reduction);

        total -= application_reduction;
    }

    // Calcul des taxes
    float taxes = total * TAXES;
    printf("Taxes (%.2f%%): $%.2f\n", TAXES * 100, taxes);

    // Affichage du total final
    printf("Total: $%.2f\n", total + taxes);


    system("pause");
}
