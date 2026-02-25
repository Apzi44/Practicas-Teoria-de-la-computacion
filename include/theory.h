#ifndef THEORY_H
#define THEORY_H

#define MAX_STR_LEN 50
#define MAX_REGISTRY_SIZE 20

typedef struct {
    char *symbols;
    int size;
} Alphabet;

typedef struct {
    char data[MAX_STR_LEN];
    int length;
} TString;

typedef struct {
    TString items[MAX_REGISTRY_SIZE];
    int size;
} StringRegistry;

void print_alphabet(Alphabet sigma);

void registry_add(StringRegistry *reg, const char *raw_text);

TString theory_concat(TString u, TString v);
TString theory_reverse(TString u);
TString theory_power(TString u, int n);
void theory_print_prefixes(TString u);
void theory_print_suffixes(TString u);
void theory_print_substrings(TString u);
void theory_print_subsequences(TString u);
#endif
