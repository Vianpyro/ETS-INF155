/*
	Écrivez une fonction "main" qui permet de calculer et afficher le salaire d'un employé.
	Pour ce faire, déclarez trois variables;
	- `nbr_heures`: entier
	- `taux_horaire`, `salaire`: réels.
	Saisissez d'abord au clavier
		le nombre d'heures travaillées par l'employé (une valeur que vous mettez dans nbr_heures)
		et son taux horaire (une valeur que vous mettez dans taux_horaire).
	Ensuite, calculez le salaire (une valeur que vous mettez dans salaire).
	Finalement, affichez le salaire à l'écran.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // #include <stdio.h> pour les fonctions d'entrée/sortie en C
#include <stdlib.h> // #include <stdio.h> pourl la fonction `system()`

int main(void) {
	int nbr_heures;
	float taux_horaire, 
		salaire;

	printf("Nombre d'heures de travail: ");
	scanf_s("%d", &nbr_heures);

	printf("Taux horaire: ");
	scanf_s("%f", &taux_horaire);

	salaire = nbr_heures * taux_horaire;

	printf("Salaire: %.2f\n", salaire);

	system("pause");
}
