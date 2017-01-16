#include "../inc/callback.h"
#include "../inc/gui.h"

extern my_GtkMap map;
extern char *logs;
extern int window_map;

void cb_quit(GtkWidget *p_widget, gpointer user_data)
{
    gtk_main_quit();

    (void)p_widget;
    (void)user_data;
}

void cb_open_map(GtkWidget *p_widget, gpointer user_data)
{
    GtkWidget *dialog_window = NULL;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;

    gint res;

    dialog_window = gtk_file_chooser_dialog_new("Choisir la carte", NULL, action, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog_window));

    if(res == GTK_RESPONSE_ACCEPT)
    {
        GtkWidget **parent = (GtkWidget **)user_data;

        char *file_name = NULL;

        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog_window);

        file_name = gtk_file_chooser_get_filename(chooser);

        GtkWidget *child = find_child(*parent, "table");

        if(child)
        {
            gtk_widget_destroy(dialog_window);

            gui_map(parent, file_name);

            gtk_widget_destroy(child);
            gtk_widget_show_all(*parent);

            if(logs == NULL)
            {
                 cb_open_logs(p_widget, user_data);
            }
        }

        g_free(file_name);
    }

    (void)p_widget;
}

void cb_open_logs(GtkWidget *p_widget, gpointer user_data)
{
    GtkWidget *dialog_window = NULL;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;

    gint res;

    dialog_window = gtk_file_chooser_dialog_new("Choisir les traces", NULL, action, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog_window));

    if(res == GTK_RESPONSE_ACCEPT)
    {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog_window);

        logs = gtk_file_chooser_get_filename(chooser);

        if(logs)
        {
            gtk_widget_destroy(dialog_window);
            g_print("%s\n", logs);
            g_free(logs);

            if(window_map == 0)
            {
                cb_open_map(p_widget, user_data);
            }
        }
    }

    (void)user_data;
    (void)p_widget;
}

void cb_about(GtkWidget *p_widget, gpointer user_data)
{
    GtkWidget *p_about_dialog = gtk_about_dialog_new();
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(p_about_dialog), "1.0a");
    gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(p_about_dialog), "INSA-CVL Bourges Map");

    const gchar *authors[2] = {"Lucas Di Martino", NULL};
    gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(p_about_dialog), authors);

    gtk_dialog_run(GTK_DIALOG(p_about_dialog));

    (void)user_data;
    (void)p_widget;
}