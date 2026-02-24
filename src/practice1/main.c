#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "theory.h"

/* ANSI Color Codes for a modern look */
#define CLR_RESET  "\033[0m"
#define CLR_HEADER "\033[1;34m" // Bold Blue
#define CLR_ACCENT "\033[1;36m" // Bold Cyan
#define CLR_ERROR  "\033[1;31m" // Bold Red
#define CLR_SUCCESS "\033[1;32m" // Bold Green

#define MAX_STRINGS 20

/* Global registry to store strings generated during the session */
TString registry[MAX_STRINGS];
int string_count = 0;

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_header() {
    printf(CLR_HEADER "====================================================\n");
    printf("        TEORIA DE LA COMPUTACION - PRACTICA 1       \n");
    printf("====================================================\n" CLR_RESET);
}

void print_registry() {
    printf(CLR_ACCENT "\n--- Registro de Cadenas Disponibles ---\n" CLR_RESET);
    for (int i = 0; i < string_count; i++) {
        printf("[%d] \"%s\" (Longitud: %d)\n", i, registry[i].data, registry[i].length);
    }
    printf("---------------------------------------\n");
}

int main() {
    char input_buffer[101];

    clear_screen();
    print_header();

    /* Initial data collection */
    printf("\nIngrese la primera cadena (Alfabeto alfanumerico): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = 0;
    // TODO: Create TString and add to registry
    
    printf("Ingrese la segunda cadena (Alfabeto alfanumerico): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = 0;
    // TODO: Create TString and add to registry

    int choice = -1;
    while (choice != 0) {
        clear_screen();
        print_header();
        print_registry();

        printf("\n" CLR_ACCENT "MENU DE OPERACIONES" CLR_RESET "\n");
        printf("1. Concatenacion (Genera nueva)\n");
        printf("2. Potencia (Genera nueva)\n");
        printf("3. Calcular Longitud\n");
        printf("4. Generar Prefijos\n");
        printf("5. Generar Sufijos\n");
        printf("6. Generar Subcadenas\n");
        printf("7. Generar Subsecuencias\n");
        printf("0. Salir\n");
        
        printf(CLR_ACCENT "\n[?] Seleccione una opcion: " CLR_RESET);
        scanf("%d", &choice);
        getchar(); // Clean newline from buffer

        switch (choice) {
            case 1:
                printf("\n--- Operacion: Concatenacion ---\n");
                /* Logic will be added here */
                break;
            case 0:
                printf(CLR_SUCCESS "Saliendo del programa...\n" CLR_RESET);
                break;
            default:
                printf(CLR_ERROR "Opcion no valida.\n" CLR_RESET);
                break;
        }

        if (choice != 0) {
            printf("\nPresione Enter para continuar...");
            getchar();
        }
    }

    return 0;
}
