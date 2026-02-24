#ifndef THEORY_H
#define THEORY_H

/* Basic structure representing a formal alphabet (Sigma) */
typedef struct {
    char *symbols;
    int size;
} Alphabet;

typedef struct {
    char data[101]; // Enough for concatenation (50+50) and power
    int length;
} TString; // 'T' for Theory

/* Prints the alphabet in standard set notation: Sigma = {s1, s2, ...} */
void print_alphabet(Alphabet sigma);

#endif
