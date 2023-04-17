#ifndef _WIDGETS_
#define _WIDGETS_

#include <gtk/gtk.h>

/**
 * @brief Create a window object
 * 
 * @return GtkWidget* 
*/
GtkWidget *create_window(void);

/**
 * @brief Create a board object
 * 
 * @return GtkWidget* 
*/
GtkWidget *create_board(void);

/**
 * @brief Create a button object
 * 
 * @param button_icon 
 * @return GtkWidget* 
*/
GtkWidget *create_button(const char *button_icon);

/**
 * @brief 
 * 
 * @param board 
*/
void add_label(GtkWidget *board);

/**
 * @brief Ajoute deux champs de widgets à un tableau Gtk.
 *
 * Cette fonction ajoute deux champs de widgets à un tableau Gtk spécifié. Les champs de widgets sont passés en tant que pointeurs de pointeurs, de sorte que les variables originales seront mises à jour avec les nouveaux champs créés.
 *
 * @param[in] board Un pointeur vers le widget tableau Gtk auquel ajouter les champs de widgets.
 * @param[out] field1 Un pointeur vers un pointeur de GtkWidget pour stocker le premier champ de widgets créé.
 * @param[out] field2 Un pointeur vers un pointeur de GtkWidget pour stocker le deuxième champ de widgets créé.
 *
 * @note Les variables field1 et field2 doivent être initialisées à NULL avant d'appeler cette fonction.
 *
*/
void add_field(GtkWidget *board, GtkWidget **field1, GtkWidget **field2);

/**
 * @brief 
 * 
 * @param board 
 * @param button 
 * @param error 
*/
void add_button(GtkWidget *board, GtkWidget **button, GtkWidget **error);

#endif // __WIDGETS__Test