/*
    Completer un code pour afficher: 1 2 3 4 5
                                       2 3 4 5
                                         3 4 5
                                           4 5
                                             5
*/
#include <stdio.h>

#define MAX 5

void main() {
    int i, j;

    for (i = 1; i <= MAX; i++) {
        for (j = 0; j <= i; j++)
            printf("  ");

        for (j = i; j <= MAX; j++)
            printf("%d ", j);
        printf("\n");
    }
}
