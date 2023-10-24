/*
    Comparaison entre optimisation RAM et CPU
*/
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nb_termes1(int max) {
    int somme = 0;
    uint16_t i;
    while ((somme += i++) < max)
        ;
    return i;
}

int nb_termes2(int max) {
    int somme = 0, i = 1;
    while ((somme += i++) < max)
        ;
    return i;
}

double timeit(int max, int (*func)(int)) {
    clock_t start, end;
    start = clock();
    func(max);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void) {
    int max_value = INT_MAX;  // Choose the maximum value for testing

    double time_taken1 = timeit(max_value, nb_termes1);
    double time_taken2 = timeit(max_value, nb_termes2);

    printf("Execution time for the first function: %.4f seconds\n", time_taken1);
    printf("Execution time for the second function: %.4f seconds\n", time_taken2);

    return EXIT_SUCCESS;
}
