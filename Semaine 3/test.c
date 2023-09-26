/*
    For loops
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // a
    printf("Nombres impairs entre 1 et 100: ");
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2)
            printf("%d ", i);
    }

    // b
    printf("\n\nNombres pair entre 100 et 1: ");
    for (int i = 100; i >= 1; i--)
    {
        if (i % 2 == 0)
            printf("%d ", i);
    }

    // c
    printf("\n\nNombres divisibles par 3 entre 99 et 300: ");
    for (int i = 99; i <= 300; i++)
    {
        if (i % 3 == 0)
            printf("%d ", i);
    }

    // d
    printf("\n\nNombres divisibles par 7 entre 700 et 600: ");
    for (int i = 700; i >= 600; i--)
    {
        if (i % 7 == 0)
            printf("%d ", i);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
