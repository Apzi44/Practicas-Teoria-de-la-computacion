#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

void ui_clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ui_print_header(const char *title) {
    printf(CLR_HEADER "====================================================\n");
    printf("  %s\n", title);
    printf("====================================================\n" CLR_RESET);
}

void ui_print_error(const char *message) {
    printf(CLR_ERROR "[!] Error: %s" CLR_RESET "\n", message);
}

void ui_print_success(const char *message) {
    printf(CLR_SUCCESS "[+] %s" CLR_RESET "\n", message);
}

void ui_pause() {
    printf("\nPresione Enter para continuar...");
    getchar();
}

int ui_display_menu(const char *title, const char *options[], int count) {
    printf(CLR_ACCENT "\n--- %s ---\n" CLR_RESET, title);
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", (i == count - 1) ? 0 : i + 1, options[i]);
    }

    return ui_get_int(CLR_ACCENT "\n[?] Seleccione una opcion: " CLR_RESET);
}

int ui_get_int(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        ui_print_error("Entrada invalida. Ingrese un numero.");
        while (getchar() != '\n'); // Clear buffer
        printf("%s", prompt);
    }
    getchar(); // Clean newline
    return value;
}

void ui_get_string(const char *prompt, char *buffer, int size) {
    printf("%s: ", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline
}
