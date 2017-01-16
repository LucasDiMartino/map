#include "../inc/gui.h"

my_GtkMap map;

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

    window_map = 1;

    map.p_scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(map.p_scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_table_attach(GTK_TABLE(p_table), map.p_scrolled_window, 0, 3, 0, 4, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);

    GError *error = NULL;

    GtkWidget *p_image = NULL;

    map.p_pixbuf = gdk_pixbuf_new_from_file(file_map, &error);

    GdkPixbuf *pixbuf_mini = NULL;

    map.original_width = gdk_pixbuf_get_width(map.p_pixbuf);
    map.original_height = gdk_pixbuf_get_height(map.p_pixbuf);

    if(!error)
    {
        map.min_width = (*p_main_box)->allocation.width;
        map.min_height = (unsigned int)(map.original_height / (map.original_width / map.min_width));

        map.current_width = map.min_width;
        map.current_height = map.min_height;

        pixbuf_mini =  gdk_pixbuf_scale_simple(map.p_pixbuf, map.min_width * 4, map.min_height * 4, GDK_INTERP_BILINEAR);

        p_image = gtk_image_new_from_pixbuf(pixbuf_mini);
        gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(map.p_scrolled_window), p_image);
    }

    gtk_box_pack_end(GTK_BOX(*p_main_box), p_table, TRUE, TRUE, 0);

    gtk_widget_show_all(*p_main_box);
}
