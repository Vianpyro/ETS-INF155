/*
    Ecrire programme qui calcule montant facture pour des achats a la COOP ETS.
    Pour chaque item, demander la quantitee et prix unitaire du produit.
    Apres chaque item, demander si client a d'autres items a entrer.
    La COOP offre 10% de reduction si le montant total des achats depasse $100.00.
    On applique ensuite les taxes (TPS & TVQ) de 15%.
*/
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entree/sortie
#include <stdlib.h> // Pour les fonctions d'entree/sortie et la fonction `system()`

int main(void) {
    // Taux de taxes et reduction
    float TAXES = 0.15;
    float REDUCTION = 0.1;
    float SEUIL_REDUCTION = 100.00;

    // Initialisation du sous-total et de la variable de continuation
    float sous_total = 0;
    int continuer = 1;

    // Boucle principale pour la saisie des articles
    while (continuer) {
        // Saisie de la quantite
        int quantite;
        printf("Quantite: ");
        scanf("%d", &quantite);

        // Saisie du prix unitaire
        float prix_unitaire;
        printf("Prix unitaire: ");
        scanf("%f", &prix_unitaire);

        // Calcul du sous-total
        sous_total += quantite * prix_unitaire;

        // Saisie de la reponse de l'utilisateur pour continuer
        printf("Ajouter d'autres items? [1 (oui)/0 (non)]: ");
        scanf("%d", &continuer);
    }

    // Calcul du total initial
    float total = sous_total;
    printf("Sous total: $%.2f\n", sous_total);

    // Verification de la reduction applicable
    if (sous_total > SEUIL_REDUCTION) {
        float application_reduction = total * REDUCTION;
        printf("Reduction (%.2f%%): $%.2f\n", REDUCTION * 100, application_reduction);

        total -= application_reduction;
    }

    // Calcul des taxes
    float taxes = total * TAXES;
    printf("Taxes (%.2f%%): $%.2f\n", TAXES * 100, taxes);

    // Affichage du total final
    printf("Total: $%.2f\n", total + taxes);

    system("pause");
    return EXIT_SUCCESS;
}
