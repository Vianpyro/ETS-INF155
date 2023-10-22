#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int nb_termes1(int max) {
    int somme = 0, i;
    for (i = 1; (somme += i) < max; i++)
        ;
    return i;
}

int nb_termes2(int max) {
    int somme = 0, i = 1;
    while ((somme += i++) < max)
        ;
    return i;
}

int nb_termes3(int max) {
    int somme = 0;
    uint16_t i;
    for (i = 1; (somme += i) < max; i++)
        ;
    return i;
}

int nb_termes4(int max) {
    int somme = 0;
    uint16_t i = 1;
    while ((somme += i++) < max)
        ;
    return i;
}

int main() {
    clock_t start, end;
    int max_value = INT_MAX;  // Choix de la valeur max pour les tests

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

    // Mesure du temps pour la troisieme fonction
    start = clock();
    nb_termes3(max_value);
    end = clock();
    double time_taken3 = (double)(end - start) / CLOCKS_PER_SEC;

    // Mesure du temps pour la quatrieme fonction
    start = clock();
    nb_termes4(max_value);
    end = clock();
    double time_taken4 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Temps d'execution pour la premiere fonction : %f secondes\n", time_taken1);
    printf("Temps d'execution pour la deuxieme fonction : %f secondes\n", time_taken2);
    printf("Temps d'execution pour la troisieme fonction : %f secondes\n", time_taken3);
    printf("Temps d'execution pour la quatrieme fonction : %f secondes\n", time_taken4);

    return 0;
}
