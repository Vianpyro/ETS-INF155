#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int nb_termes1(int max) {
    int somme = 0, i = 1;
    while ((somme += i++) < max)
        ;
    return i;
}

int nb_termes2(int max) {
    int somme = 0;
    int i = 1;
    while ((somme += i++) < max)
        ;
    return i;
}

int main() {
    clock_t start, end;
    int max_value = INT_MAX;  // Choisir la valeur max pour les tests

    // Mesure du temps pour la premiere fonction
    start = clock();
    nb_termes1(max_value);
    end = clock();
    double time_taken1 = (double)(end - start) / CLOCKS_PER_SEC;

    // Mesure du temps pour la deuxieme fonction
    start = clock();
    nb_termes2(max_value);
    end = clock();
    double time_taken2 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Temps d'exécution pour la première fonction : %f secondes\n", time_taken1);
    printf("Temps d'exécution pour la deuxième fonction : %f secondes\n", time_taken2);

    return 0;
}
