#include <stdio.h>  // Added to fix warnings
#include "theory.h"
#include "ui.h"

int main() {
    char buffer[101];
    
    const char *main_menu[] = {
        "Concatenacion", "Potencia", "Longitud", 
        "Prefijos", "Sufijos", "Subcadenas", "Subsecuencias", "Salir"
    };

    ui_clear_screen();
    ui_print_header("PRACTICA 1: ALFABETOS Y CADENAS");

    ui_get_string("Ingrese cadena A", buffer, 50);
    ui_get_string("Ingrese cadena B", buffer, 50);

    int choice = -1;
    while (choice != 0) {
        ui_clear_screen();
        ui_print_header("PRACTICA 1: ALFABETOS Y CADENAS");
        
        choice = ui_display_menu("OPERACIONES DISPONIBLES", main_menu, 8);

        if (choice == 0) { 
          ui_print_success("Saliendo del programa...");  
          break;
        }
        
        // Logic will go here
        
        ui_pause(); // Cleaner and uses our UI module
    }
    return 0;
}
