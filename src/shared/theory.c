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
    snprintf(result.data, MAX_STR_LEN*2, "%s%s", u.data, v.data);
    result.length = strlen(result.data);
    return result;
}

TString theory_reverse(TString u) {
    TString result;
    result.length = u.length;
    for (int i = 0; i < u.length; i++) {
        result.data[i] = u.data[u.length - 1 - i];
    }
    result.data[u.length] = '\0';
    return result;
}

TString theory_power(TString u, int n) {
    TString result;
    result.data[0] = '\0';
    result.length = 0;

    if (n == 0) return result; // Returns empty string (epsilon)

    TString base = (n < 0) ? theory_reverse(u) : u;
    int abs_n = (n < 0) ? -n : n;

    for (int i = 0; i < abs_n; i++) {
        // Check if adding another 'base' exceeds our buffer
        if (result.length + base.length < MAX_STR_LEN) {
            strcat(result.data, base.data);
            result.length += base.length;
        } else {
            break; // Truncate if it exceeds MAX_STR_LEN
        }
    }
    return result;
}

void theory_print_prefixes(TString u) {
    printf("\nPrefijos de la cadena \"%s\":\n", u.data);
    printf(" - (epsilon)\n");

    for(int i = 1; i <= u.length; i++) {
        printf(" - %.*s\n", i, u.data);
    }
}

void theory_print_suffixes(TString u) {
    printf("\nSufijos de la cadena \"%s\":\n", u.data);
    printf(" - (epsilon)\n");

    for(int i = u.length - 1; i >= 0; i--) {
        printf(" - %s\n", u.data + i);
    }
}

void theory_print_substrings(TString u) {
    printf("\nSubcadenas de la cadena \"%s\":\n", u.data);
    printf(" - (epsilon)\n");

    for(int len = 1; len <= u.length; len++) {
        for(int start = 0; start <= u.length - len; start++) {
            printf(" - %.*s\n", len, u.data + start);
        }
    }
}

void theory_print_subsequences(TString u) {
    if (u.length > 12) {
        printf("\n[!] Error: La cadena es muy larga para generar todas sus subsecuencias.\n");
        return;
    }
    printf("\nSubsecuencias de la cadena \"%s\":\n", u.data);
    printf(" - (epsilon)\n");

    int total_subsequences = 1 << u.length;
    for(int i = 1; i < total_subsequences; i++) {
        printf(" - ");
        for(int j = 0; j < u.length; j++) {
            if(i & (1 << j)) {
                printf("%c", u.data[j]);
            }
        }
        printf("\n");
    }
}