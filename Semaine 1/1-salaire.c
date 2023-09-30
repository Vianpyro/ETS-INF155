/*
	Ecrire une fonction "main" qui permet de calculer et afficher le salaire d'un employe.
	Pour ce faire, declarer trois variables;
		- `nbr_heures`: entier.
		- `taux_horaire`, `salaire`: reels.
	Saisir d'abord au clavier:
		- Nombre d'heures de travail par l'employe
		- Taux horaire.
	Ensuite, calculer le salaire.
	Finalement, afficher le salaire a l'ecran.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entree/sortie
#include <stdlib.h> // Pour les fonctions d'entree/sortie et la fonction `system()`

int main(void) {
	unsigned int nbr_heures;
	float taux_horaire, salaire;

	printf("Nombre d'heures de travail: ");
	scanf("%d", &nbr_heures);

	printf("Taux horaire: ");
	scanf("%f", &taux_horaire);

	salaire = nbr_heures * taux_horaire;

	printf("Salaire: %.2f\n", salaire);

	system("pause");
	return EXIT_SUCCESS;
}
