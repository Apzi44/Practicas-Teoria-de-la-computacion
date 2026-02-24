#include "theory.h"

int main() {
    /* Example: Defining a binary alphabet Sigma = {0, 1} */
    char binary_symbols[] = {'0', '1'};
    Alphabet binary_sigma = {binary_symbols, 2};

    print_alphabet(binary_sigma);
    return 0;
}
