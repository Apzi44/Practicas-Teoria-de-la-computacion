#include <stdio.h>
#include <string.h>
#include "theory.h"
#include "ui.h"

/* Helper to display the registry contents using the UI style */
void display_current_registry(StringRegistry *reg) {
    printf(CLR_ACCENT "\n--- Registro de Cadenas Disponibles ---" CLR_RESET "\n");
    if (reg->size == 0) {
        printf("(Vacio)\n");
    } else {
        for (int i = 0; i < reg->size; i++) {
            printf("[%d] \"%s\" (len: %d)\n", i, reg->items[i].data, reg->items[i].length);
        }
    }
    printf("---------------------------------------\n");
}

int main() {
    // Initializing the registry object
    StringRegistry my_registry = { .size = 0 };
    char buffer[MAX_STR_LEN];
    
    const char *main_menu[] = {
        "Concatenacion", "Potencia", "Longitud", 
        "Prefijos", "Sufijos", "Subcadenas", "Subsecuencias", "Salir"
    };

    ui_clear_screen();
    ui_print_header("PRACTICA 1: ALFABETOS Y CADENAS");

    /* Initial string collection */
    ui_get_string("Ingrese la primera cadena (A)", buffer, 50);
    registry_add(&my_registry, buffer);

    ui_get_string("Ingrese la segunda cadena (B)", buffer, 50);
    registry_add(&my_registry, buffer);

    int choice = -1;
    while (1) {
        ui_clear_screen();
        ui_print_header("PRACTICA 1: ALFABETOS Y CADENAS");
        
        display_current_registry(&my_registry);
        
        choice = ui_display_menu("OPERACIONES DISPONIBLES", main_menu, 8);
        
        // Exit case
        if (choice == 0) { 
          ui_print_success("Saliendo del programa..."); 
          break;
        }

        switch (choice) {
            case 1: { // Concatenation
                int idx1 = ui_get_int("Indice de la primera cadena: ");
                int idx2 = ui_get_int("Indice de la segunda cadena: ");

                if (idx1 >= 0 && idx1 < my_registry.size && idx2 >= 0 && idx2 < my_registry.size) {
                    TString result = theory_concat(my_registry.items[idx1], my_registry.items[idx2]);
                    registry_add(&my_registry, result.data);
                    ui_print_success("Cadena concatenada con exito.");
                } else {
                    ui_print_error("Uno o ambos indices son invalidos.");
                }
                break;
            }
            default:
                ui_print_error("Esta operacion aun no ha sido implementada.");
                break;
        }

        ui_pause();
    }

    ui_print_success("Programa finalizado correctamente.");
    return 0;
}
