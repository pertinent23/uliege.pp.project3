#ifndef _TOOLS_
#define _TOOLS_

#include <gtk/gtk.h>

#define CALC_HEIGHT 400
#define CALC_WIDTH 500

/**
 * @brief 
 * Est utilisé pour contenir les informations
 * lors d'un évènement de click 
*/
typedef struct GtkActionData_t GtkActionData;

/**
 * @brief Create a data object
 * 
 * @param field1 
 * @param field2 
 * @param error 
 * @param window 
 * @return GtkActionData* 
*/
GtkActionData *create_data(GtkWidget *field1, GtkWidget *field2, GtkWidget *error, GtkWidget *window);

/**
 * @brief Get the window object
 * 
 * @param data 
 * @return GtkWidget* 
*/
GtkWidget *get_window(struct GtkActionData_t *data);

/**
 * @brief 
 * 
 * @param data 
*/
void destroy_data(struct GtkActionData_t *data);

/**
 * @brief 
 * 
 * @param data 
 * @param message 
*/
void show_message(struct GtkActionData_t *data, const char *message);

/**
 * @brief 
 * 
 * @param window 
 * @param data 
*/
void destroy_window(GtkWidget *window, gpointer data);

/**
 * @brief 
 * 
 * @param button 
 * @param data 
*/
void button_clicked(GtkWidget *button, gpointer data);

/**
 * @brief Get the field1 value object
 * 
 * @param data 
 * @return const char* 
*/
const char *get_field1_value(struct GtkActionData_t *data);

/**
 * @brief Get the field2 value object
 * 
 * @param data 
 * @return const char* 
*/
const char *get_field2_value(struct GtkActionData_t *data);

#endif // __TOOLS__