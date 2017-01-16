#include "../inc/gui.h"
#include "../inc/gtk-image-viewer.h"

char *logs = NULL;
int window_map = 0;

void gui_load(GtkWidget **p_main_box)
{
    GtkWidget *p_table = gtk_table_new(5, 3, TRUE);
    gtk_widget_set_name(p_table, "table");

    {
        GtkWidget *p_button = gtk_button_new_with_mnemonic("Charger la carte");
        gtk_table_attach(GTK_TABLE(p_table), p_button, 1, 2, 1, 2, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
        g_signal_connect(G_OBJECT(p_button), "clicked", G_CALLBACK(cb_open_map), p_main_box);
    }

    {
        GtkWidget *p_button = gtk_button_new_with_mnemonic("Charger les traces");
        gtk_table_attach(GTK_TABLE(p_table), p_button, 1, 2, 3, 4, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
        g_signal_connect(G_OBJECT(p_button), "clicked", G_CALLBACK(cb_open_logs), p_main_box);
    }

    gtk_box_pack_end(GTK_BOX(*p_main_box), p_table, TRUE, TRUE, 0);
}

void gui_map(GtkWidget **p_main_box, char *file_map)
{
    GtkWidget *p_table = gtk_table_new(5, 3, TRUE);

    GtkWidget *p_scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(p_scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_table_attach(GTK_TABLE(p_table), p_scrolled_window, 0, 3, 0, 4, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);

    GtkWidget *image_viewer = gtk_image_viewer_new_from_file(file_map);
    g_signal_connect(G_OBJECT(image_viewer), "image-annotate", G_CALLBACK(cb_image_annotate), NULL);

    gtk_container_add(GTK_CONTAINER(p_scrolled_window), image_viewer);

    gtk_box_pack_end(GTK_BOX(*p_main_box), p_table, TRUE, TRUE, 0);

    window_map = 1;

    gtk_widget_show_all(*p_main_box);
}
