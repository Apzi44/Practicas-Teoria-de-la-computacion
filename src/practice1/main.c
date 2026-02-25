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

            case 2: { // Power
                int idx = ui_get_int("Indice de la cadena: ");
                int n = ui_get_int("Ingrese la potencia (n): ");

                if (idx >= 0 && idx < my_registry.size) {
                    TString result = theory_power(my_registry.items[idx], n);
                    
                    printf(CLR_ACCENT "\nResultado de la operacion: " CLR_RESET);
                    if (result.length == 0) {
                        printf("(epsilon / cadena vacia)\n");
                    } else {
                        printf("\"%s\"\n", result.data);
                    }

                    registry_add(&my_registry, result.data);
                    ui_print_success("Operacion guardada en el registro.");
                } else {
                    ui_print_error("Indice invalido.");
                }
                break;
            }

            case 3: {
                int idx = ui_get_int("Indice de la cadena: ");
                if (idx >= 0 && idx < my_registry.size) {
                    printf("\nLa longitud de la cadena \"%s\" es: %d\n",
                           my_registry.items[idx].data,
                           my_registry.items[idx].length);
                } else {
                    ui_print_error("Indice invalido.");
                }
                break;
            }

            case 4: {
                int idx = ui_get_int("Indice de la cadena: ");
                if (idx >= 0 && idx < my_registry.size) {
                    theory_print_prefixes(my_registry.items[idx]);
                } else {
                    ui_print_error("Indice invalido.");
                }
                break;
            }

            case 5: {
                int idx = ui_get_int("Indice de la cadena: ");
                if (idx >= 0 && idx < my_registry.size) {
                    theory_print_suffixes(my_registry.items[idx]);
                } else {
                    ui_print_error("Indice invalido.");
                }
                break;
            }

            case 6: {
                int idx = ui_get_int("Indice de la cadena: ");
                if (idx >= 0 && idx < my_registry.size) {
                    theory_print_substrings(my_registry.items[idx]);
                } else {
                    ui_print_error("Indice invalido.");
                }
                break;
            }

            case 7: {
                int idx = ui_get_int("Indice de la cadena: ");
                if (idx >= 0 && idx < my_registry.size) {
                    theory_print_subsequences(my_registry.items[idx]);
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
