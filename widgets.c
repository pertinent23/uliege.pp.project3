#include <gdk/gdk.h>
#include "tools.h"
#include "widgets.h"

GtkWidget *create_window(void)
{
    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "CALCULATRICE");
    gtk_window_set_default_size(GTK_WINDOW(window), CALC_WIDTH, CALC_HEIGHT);

    g_signal_connect(
        G_OBJECT(window), "destroy",
        G_CALLBACK(destroy_window), NULL
    );

    return window;
}

GtkWidget *create_board(void)
{
    GtkWidget *board;

    board = gtk_table_new(5, 4, TRUE);

    return board;
}

void add_label(GtkWidget *board)
{
    GtkWidget 
        *label1 = gtk_label_new("NOMBRE 1"),
        *label2 = gtk_label_new("NOMBRE 2");

    gtk_table_attach(GTK_TABLE(board), label1, 1, 2, 1, 2, GTK_EXPAND, GTK_EXPAND, 0, 0);
    gtk_table_attach(GTK_TABLE(board), label2, 1, 2, 2, 3, GTK_EXPAND, GTK_EXPAND, 0, 0);
}

void add_field(GtkWidget *board, GtkWidget **field1, GtkWidget **field2)
{
    GtkWidget 
        *fd1 = gtk_entry_new(),
        *fd2 = gtk_entry_new();
    
    gtk_table_attach(GTK_TABLE(board), fd1, 2, 3, 1, 2, GTK_EXPAND|GTK_FILL, GTK_EXPAND, 0, 0);
    gtk_table_attach(GTK_TABLE(board), fd2, 2, 3, 2, 3, GTK_EXPAND|GTK_FILL, GTK_EXPAND, 0, 0);

    gtk_entry_set_max_length(GTK_ENTRY(fd1), 15);
    gtk_entry_set_max_length(GTK_ENTRY(fd2), 15);

    *field1 = fd1;
    *field2 = fd2;
}

GtkWidget *create_button(const char *button_icon){
    GtkWidget *button = gtk_button_new();
    GdkPixbuf *temp = gdk_pixbuf_new_from_file(button_icon, NULL);

    if (temp != NULL){
        gtk_button_set_image(GTK_BUTTON(button), gtk_image_new_from_pixbuf(
            gdk_pixbuf_scale_simple(temp, 100, 100, GDK_INTERP_NEAREST)
        ));
    }

    return button;
}

void add_button(GtkWidget *board, GtkWidget **button, GtkWidget **error)
{
    const char image[] = "./images/icon.png";
    GtkWidget 
        *bt = create_button(image),
        *er = gtk_label_new(" ");
    
    gtk_button_set_label(GTK_BUTTON(bt), "ADDITION");
    gtk_table_attach(GTK_TABLE(board), bt, 1, 2, 3, 4, GTK_EXPAND|GTK_FILL, GTK_EXPAND, 0, 0);
    gtk_table_attach(GTK_TABLE(board), er, 2, 3, 3, 4, GTK_EXPAND|GTK_FILL, GTK_EXPAND, 0, 0);

    *button = bt;
    *error = er; 
}