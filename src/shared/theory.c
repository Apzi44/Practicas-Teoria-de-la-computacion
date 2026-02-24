#include <stdio.h>
#include "theory.h"

void print_alphabet(Alphabet sigma) {
    printf("Sigma = {");
    for (int i = 0; i < sigma.size; i++) {
        // Only add a comma if it's not the last element
        printf("%c%s", sigma.symbols[i], (i < sigma.size - 1) ? ", " : "");
    }
    printf("}\n");
}
