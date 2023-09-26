/*
    Notation litterale
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define note_min 0
#define note_max 100

int note_litterale(float note);

int main(void) {
    float note;

    printf("Entrez une note (entre %d et %d): ", note_min, note_max);
    scanf_s("%f", &note);

    note_litterale(note);

    return EXIT_SUCCESS;
}

int note_litterale(float note) {
    if (note < note_min || note > note_max) {
        printf("Cette note (%f.2f) est invalide", note);
        return 0;
    }

    printf("Cette note correspond a ");

    if (note >= 89.5) printf("A+, Excellent");
    else if (note >= 84.5) printf("A, Excellent");
    else if (note >= 79.5) printf("A-, Excellent");
    else if (note >= 74.5) printf("B+, Tres bien");
    else if (note >= 69.5) printf("B, Tres bien");
    else if (note >= 64.5) printf("B-, Tres bien");
    else if (note >= 59.5) printf("C+, Bien");
    else if (note >= 54.5) printf("C, Bien");
    else if (note >= 49.5) printf("C-, Bien");
    else if (note >= 44.5) printf("D+, Passable");
    else if (note >= 39.5) printf("D, Passable");
    else printf("E, Echec");

    printf(".\n");
    
    return 1;
}
