#ifndef THEORY_H
#define THEORY_H

#define MAX_STR_LEN 50
#define MAX_REGISTRY_SIZE 20

/* Basic structure representing a formal alphabet (Sigma) */
typedef struct {
    char *symbols;
    int size;
} Alphabet;

typedef struct {
     char data[MAX_STR_LEN]; // Enough for concatenation (50+50) and power
    int length;
} TString; // 'T' for Theory

typedef struct {
    TString items[MAX_REGISTRY_SIZE];
    int size;
} StringRegistry;

/* Prints the alphabet in standard set notation: Sigma = {s1, s2, ...} */
void print_alphabet(Alphabet sigma);

/* Registry management */
void registry_add(StringRegistry *reg, const char *raw_text);

/* Mathematical operations */
TString theory_concat(TString u, TString v);
TString theory_reverse(TString u);
TString theory_power(TString u, int n);

#endif
