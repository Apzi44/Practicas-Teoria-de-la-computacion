#include <string.h>
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

void registry_add(StringRegistry *reg, const char *raw_text) {
    if (reg->size < MAX_REGISTRY_SIZE) {
        // Use strncpy to prevent overflows
        strncpy(reg->items[reg->size].data, raw_text, MAX_STR_LEN - 1);
        reg->items[reg->size].data[MAX_STR_LEN - 1] = '\0';
        reg->items[reg->size].length = strlen(reg->items[reg->size].data);
        reg->size++;
    }
}

TString theory_concat(TString u, TString v) {
    TString result;
    // Now with MAX_STR_LEN = 256, 100+100 fits perfectly
    snprintf(result.data, MAX_STR_LEN*2, "%s%s", u.data, v.data);
    result.length = strlen(result.data);
    return result;
}
