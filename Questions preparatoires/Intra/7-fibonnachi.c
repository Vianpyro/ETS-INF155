/*
    Programme de calcul de la suite de fibonnachi
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int fibo(int n);

int main(void) {
    int valeur;

    assert(fibo(2) == 1);
    assert(fibo(8) == 21);
    assert(fibo(9) == 34);

    printf("Entrez le numero du terme de la suite de fibonnachi que vous voulez: ");
    scanf("%d", &valeur);

    valeur = fibo(valeur);
    printf("%d", valeur);

    system("pause");
    return EXIT_SUCCESS;
}

int fibo(int n) {
    return (n <= 2) ? 1 : fibo(n - 1) + fibo(n - 2);
}
