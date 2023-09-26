/*
	�crivez une fonction "main" qui permet de calculer et afficher le salaire d'un employ�.
	Pour ce faire, d�clarez trois variables;
	- `nbr_heures`: entier
	- `taux_horaire`, `salaire`: r�els.
	Saisissez d'abord au clavier
		le nombre d'heures travaill�es par l'employ� (une valeur que vous mettez dans nbr_heures)
		et son taux horaire (une valeur que vous mettez dans taux_horaire).
	Ensuite, calculez le salaire (une valeur que vous mettez dans salaire).
	Finalement, affichez le salaire � l'�cran.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entr�e/sortie
#include <stdlib.h> // Pour les fonctions d'entr�e/sortie et la fonction `system()`

int main(void) {
	int nbr_heures;
	float taux_horaire, 
		salaire;

	printf("Nombre d'heures de travail: ");
	scanf("%d", &nbr_heures);

	printf("Taux horaire: ");
	scanf("%f", &taux_horaire);

	salaire = nbr_heures * taux_horaire;

	printf("Salaire: %.2f\n", salaire);

	system("pause");
}
