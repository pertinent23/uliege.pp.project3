#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tools.h"

struct GtkActionData_t
{
    GtkWidget *field1;
    GtkWidget *field2;
    GtkWidget *error;
    GtkWidget *window;
};

void destroy_window(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
    UNUSED(window);
    UNUSED(data);
}

static int is_valid_number(const char *number)
{
    int length = (int) strlen(number);

    if (!length)
        return -1;

    for(int i = 0; i< length; i++)
    {
        if (strchr("0123456789", number[i]) == NULL)
            return -2;
    }

    return 1;
}

static int max(int a, int b)
{
    return a ? a>b: b ; 
}

static void create_popup(GtkWidget *container, char *message)
{
    GtkWidget 
        *dialog, *button,
        *label = gtk_label_new(message);

    dialog = gtk_dialog_new();
    button = gtk_dialog_add_button(GTK_DIALOG(dialog), "OK", 0);

    gtk_window_set_default_size(GTK_WINDOW(dialog), (int) CALC_WIDTH/2, (int) CALC_HEIGHT/3);

    g_signal_connect_swapped(
        G_OBJECT(dialog), "response",
        G_CALLBACK(gtk_widget_destroy), dialog
    );

    g_signal_connect_swapped(
        G_OBJECT(button), "pressed",
        G_CALLBACK(gtk_widget_destroy), dialog
    );
    
    gtk_container_add(
        GTK_CONTAINER(
            gtk_dialog_get_content_area(
                GTK_DIALOG(dialog)
            )
        ), 
        label
    );

    gtk_widget_show_all(dialog);
    gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(container));
}

void button_clicked(GtkWidget *button, gpointer pt)
{
    UNUSED(button);
    GtkActionData *data = (GtkActionData *) pt;
    const char 
        *nb1 = get_field1_value(data), 
        *nb2 = get_field2_value(data);
    
    char *result = malloc(sizeof(char) * (max((int)strlen(nb1), (int)strlen(nb2)) + 1));
    
    if (result != NULL)
    {
        if (is_valid_number(nb1) == 1 && is_valid_number(nb2) == 1)
        {
            sprintf(result, "%ld", atol(nb1) + atol(nb2));
            show_message(data, result);
        }
        else if (is_valid_number(nb1) == -1 || is_valid_number(nb2) == -1)
        {
            create_popup(get_window(data), "Case non remplie");
        }
        else
        {
            create_popup(get_window(data), "Données d'une case invalide");
        }

        free(result);
    }
    else
    {
        create_popup(get_window(data), "Erreur d'allocation mémoire");
    }
}

struct GtkActionData_t *create_data(GtkWidget *field1, GtkWidget *field2, GtkWidget *error, GtkWidget *window)
{
    assert(field1 != NULL && field2 != NULL && error != NULL && window != NULL);
    struct GtkActionData_t *data = malloc(sizeof(struct GtkActionData_t));

    if (data != NULL)
    {
        data->field1 = field1;
        data->field2 = field2;
        data->error = error;
        data->window = window;
    }

    return data;
}

void destroy_data(struct GtkActionData_t *data)
{
    if (data != NULL)
    {
        free(data);
        data = NULL;
    }
}

const char *get_field1_value(struct GtkActionData_t *data)
{
    assert(data != NULL && data->field1 != NULL);

    return gtk_entry_get_text(
        GTK_ENTRY(data->field1)
    );
}

GtkWidget *get_window(struct GtkActionData_t *data)
{
    assert(data != NULL);

    return data->window;
}

const char *get_field2_value(struct GtkActionData_t *data)
{
    assert(data != NULL && data->field2 != NULL);

    return gtk_entry_get_text(
        GTK_ENTRY(data->field2)
    );
}

void show_message(struct GtkActionData_t *data, const char *message)
{
    assert(data != NULL && data->error != NULL);

    gtk_label_set_text(GTK_LABEL(data->error), message);
}