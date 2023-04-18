#include <stdlib.h>
#include <gtk/gtk.h>

#include "tools.h"
#include "widgets.h"

int main(int argc, char **argv){
    gtk_init(&argc, &argv);

    GtkWidget *window = create_window();
    GtkWidget *board = create_board();
    GtkActionData *data;
    GtkWidget 
        *field1 = NULL, 
        *field2 = NULL, 
        *button = NULL, 
        *error = NULL;

    add_label(board);
    add_field(board, &field1, &field2);
    add_button(board, &button, &error);

    data = create_data(field1, field2, error, window);

    g_signal_connect(
        G_OBJECT(button), "pressed", 
        G_CALLBACK(button_clicked), data
    );

    gtk_container_add(GTK_CONTAINER(window), board);
    gtk_widget_show_all(window);
    gtk_main();

    destroy_data(data);

    return EXIT_SUCCESS;
}//fin programme