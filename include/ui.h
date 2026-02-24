#ifndef UI_H
#define UI_H

/* ANSI Color Codes */
#define CLR_RESET  "\033[0m"
#define CLR_HEADER "\033[1;34m"
#define CLR_ACCENT "\033[1;36m"
#define CLR_ERROR  "\033[1;31m"
#define CLR_SUCCESS "\033[1;32m"

/* UI Functions */
void ui_clear_screen();
void ui_print_header(const char *title);
void ui_print_error(const char *message);
void ui_print_success(const char *message);
void ui_pause();

/* * Displays a formatted menu and returns the selected option.
 * options: array of strings with the menu items.
 * count: number of items in the array.
 */
int ui_display_menu(const char *title, const char *options[], int count);

/* Robust input helpers */
void ui_get_string(const char *prompt, char *buffer, int size);
int ui_get_int(const char *prompt);

#endif
