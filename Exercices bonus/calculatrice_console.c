/*
    Calculatrice simple en C

    Instructions:
        - Declarer des variables pour des deux nombres et l'operation.
        - Demander a l'utilisateur de saisir le premier nombre et le stocker.
        - Demander a l'utilisateur de saisir le caractere de l'operation (+, -, *, /, %) et le stocker.
        - Demander a l'utilisateur de saisir le deuxieme nombre et le stocker.
        - Utiliser des declarations conditionnelles (if/else) pour effectuer l'operation appropriee en fonction du caractere de l'operation.
        - Afficher le resultat.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define FFLUSH while(getchar() != '\n') {} // A inserer devant tous les scanf("%c", ...)!

int main(void) {
    float a, b;
    char operateur;

    printf("Entrez la premiere valeur (reel) de l'operation: ");
    scanf("%f", &a);

    printf("Entrez le caractere de l'operateur (+, -, *, /, %%): ");
    FFLUSH; scanf("%c", &operateur);

    printf("Entrez la deuxieme valeur (reel) de l'operation: ");
    scanf("%f", &b);

    printf("%.2f %c %.2f = ", a, operateur, b);

    if (operateur == '+') printf("%.2f\n", a + b);
    else if (operateur == '-') printf("%.2f\n", a - b);
    else if (operateur == '*') printf("%.2f\n", a * b);
    else if (operateur == '/') printf("%.2f\n", a / b);
    else if (operateur == '%') printf("%d\n", (int) a % (int) b);

    system("pause");
    return EXIT_SUCCESS;
}
