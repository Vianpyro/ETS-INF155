/*
    Comparaison entre optimisation RAM et CPU
*/
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mode: ET binaire
int is_even1(int value) {
    return value & 1;
}

// Mode: modulo 2
int is_even2(int value) {
    return value % 2;
}

double timeit(int max, int (*func)(int)) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < max; i++) {
        func(i);
    }
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void) {
    int max_value = INT_MAX;  // Choose the maximum value for testing

    double time_taken1 = timeit(max_value, is_even1);
    double time_taken2 = timeit(max_value, is_even2);

    printf("Execution time for the first function: %.4f seconds\n", time_taken1);
    printf("Execution time for the second function: %.4f seconds\n", time_taken2);

    return EXIT_SUCCESS;
}
