/*
    Creer un gestionnaire de taches simple en ligne de commande.
    Le programme devrait permettre a l'utilisateur d'ajouter, supprimer, afficher et marquer comme terminees des taches.
    Vous pouvez stocker les taches dans un tableau.

    Instructions:
        - L'utilisateur doit pouvoir ajouter une nouvelle tache en saisissant une description.
        - L'utilisateur doit pouvoir afficher la liste des taches en cours.
        - L'utilisateur doit pouvoir marquer une tache comme terminee.
        - L'utilisateur doit pouvoir supprimer une tache de la liste.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FFLUSH while(getchar() != '\n') {} // A inserer devant tous les scanf("%c", ...)!

#define MAX_TACHES 100
#define MAX_CHAR_TACHE 100

typedef unsigned char u8;
typedef unsigned short u16;

u8 choix(void); // Utilisation d'un unsigned char parce que besoin de peu de memoire
void ajout(char* tableau[], u16 *longueur);
void retrait(char* tableau[], u16 *longueur);
void supprimer(char* tableau[], u16 *longueur, u16 index);
void affichage(char* tableau[], u16 longueur, char* tableau_finies[], u16 longueur_finies);
void marquer(char* tableau[], u16 *longueur, char* tableau_finies[], u16 *longueur_finies);
void afficher_tableau(char *tableau[], u16 longueur);

int main(void) {
    char* taches[MAX_TACHES];
    u16 longueur_taches = 0;

    char* taches_finies[MAX_TACHES]; // * Si la liste devient trop grande, supprimer le plus vieil element (index 0)
    u16 longueur_taches_finies = 0;

    u8 choix_utilisateur;

    do {
        choix_utilisateur = choix();
        
        switch (choix_utilisateur) {
            case 0: break;
            case 1: {
                printf("Vous avez choisi \"ajouter une tache\".\n");
                ajout(taches, &longueur_taches);
                break;
            }
            case 2: {
                printf("Vous avez choisi \"supprimer une tache\".\n");
                retrait(taches, &longueur_taches);
                break;
            }
            case 3: {
                printf("Vous avez choisi \"afficher la liste des taches\".\n");
                affichage(taches, longueur_taches, taches_finies, longueur_taches_finies);
                break;
            }
            case 4: {
                printf("Vous avez choisi \"marquer une tache comme finie\".\n");
                marquer(taches, &longueur_taches, taches_finies, &longueur_taches_finies);
                break;
            }
            default: {
                printf("Choix invalide!");
                return EXIT_FAILURE;
            }
        }
    } while (choix_utilisateur);

    system("pause");
    return EXIT_SUCCESS;
}

u8 choix(void) {
    u8 choix_utilisateur;

    do {
        printf(
            "Selectionnez ce que vous souhaitez faire: \n"
            "1 - Ajouter une tache.\n"
            "2 - Supprimer une tache.\n"
            "3 - Afficher la liste des taches.\n"
            "4 - Marquer une tache comme finie.\n"
            "0 - Quitter le programme.\n"
        );
        scanf("%hhu", &choix_utilisateur);

        if (choix_utilisateur >= 0 && choix_utilisateur <= 4)
            break;
        
        printf("Choix invalide! Veuillez reessayer:\n");
    } while (1);

    return choix_utilisateur;
}

void ajout(char *tableau[], u16 *longueur) {
    char nouvelle_tache[MAX_CHAR_TACHE];
    
    if (*longueur >= MAX_TACHES) {
        printf("Il y'a trop de taches dans la liste, veuillez en retirer avant de pouvoir en ajouter d'autres...\n");
        return;
    }

    printf("Entrez la description de la tache que vous souhaitez ajouter (sans espaces :<): ");
    FFLUSH; scanf("%s", nouvelle_tache);

    tableau[*longueur] = strdup(nouvelle_tache);
    (*longueur)++;
}

void retrait(char* tableau[], u16 *longueur) {
    if (*longueur < 1) {
        printf("Aucune tache en cours.\n");
        return;
    }

    u8 choix_utilisateur;

    do {
        printf("Selectionnez le numero de la tache a supprimer: \n");
        afficher_tableau(tableau, *longueur);
        scanf("%hhu", &choix_utilisateur);

        choix_utilisateur--;

        if (choix_utilisateur >= 0 && choix_utilisateur <= *longueur)
            break;
        
        printf("Choix invalide! Veuillez reessayer:\n");
    } while (1);

    // Suppression de l'element choisi
    supprimer(tableau, longueur, choix_utilisateur);
}

void supprimer(char* tableau[], u16 *longueur, u16 index) {
    free(tableau[index]);

    for (u16 i = index; i < (*longueur - 1); i++)
        tableau[i] = tableau[i + 1];

    (*longueur)--;
}

void affichage(char *tableau[], u16 longueur, char *tableau_finies[], u16 longueur_finies) {
    // Affichage des taches a faire
    if (longueur > 0) 
        printf("A faire:\n");

    afficher_tableau(tableau, longueur);

    // Affichage des taches finies
    if (longueur_finies > 0)
        printf("Fini:\n");

    afficher_tableau(tableau_finies, longueur_finies);
}

void afficher_tableau(char *tableau[], u16 longueur) {
    for (u16 i = 0; i < longueur; i++)
        printf("%d - %s\n", i + 1, tableau[i]);
}

void marquer(char *tableau[], u16 *longueur, char *tableau_finies[], u16 *longueur_finies) {
    if (*longueur < 1) {
        printf("Aucune tache en cours.\n");
        return;
    }

    u16 choix_utilisateur;
    char* tache_finie;

    do {
        printf("Selectionnez la tache finie:\n");
        afficher_tableau(tableau, *longueur);
        FFLUSH;
        scanf("%hhu", &choix_utilisateur);

        choix_utilisateur--;

        if (choix_utilisateur >= 0 && choix_utilisateur <= *longueur)
            break;
        
        printf("Choix invalide! Veuillez reessayer:\n");
    } while (1);

    if (longueur_finies >= MAX_TACHES) {
        printf("La liste des taches finies est pleine, la tache finie la plus ancienne est supprimee");
        supprimer(tableau_finies, longueur_finies, 0);
    }

    tache_finie = tableau[choix_utilisateur];
    tableau_finies[*longueur_finies] = strdup(tache_finie);
    (*longueur_finies)++;

    // Suppression de l'element choisi
    supprimer(tableau, longueur, choix_utilisateur);
}
