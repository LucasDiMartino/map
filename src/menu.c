#include "../inc/menu.h"

static void menu_item_new(GtkMenu *p_menu, const gchar *title, GCallback callback, gpointer user_data)
{
    GtkWidget *p_menu_item = NULL;

    p_menu_item = gtk_menu_item_new_with_mnemonic(title);
    gtk_menu_shell_append(GTK_MENU_SHELL(p_menu), p_menu_item);

    g_signal_connect(G_OBJECT(p_menu_item), "activate", callback, user_data);
}

GtkMenuBar *menu_new(gpointer user_data)
{
    GtkWidget *p_menu_bar = gtk_menu_bar_new();

    {
        GtkWidget *p_menu = gtk_menu_new();
        GtkWidget *p_menu_item = gtk_menu_item_new_with_mnemonic("_Fichier");

        menu_item_new(GTK_MENU(p_menu), "_Ouvrir carte", G_CALLBACK(cb_open_map), user_data);
        menu_item_new(GTK_MENU(p_menu), "_Ouvrir traces", G_CALLBACK(cb_open_logs), user_data);
        menu_item_new(GTK_MENU(p_menu), "_Quitter", G_CALLBACK(cb_quit), user_data);

        gtk_menu_item_set_submenu(GTK_MENU_ITEM(p_menu_item), p_menu);
        gtk_menu_shell_append(GTK_MENU_SHELL(p_menu_bar), p_menu_item);
    }


    {
        GtkWidget *p_menu = gtk_menu_new();
        GtkWidget *p_menu_item = gtk_menu_item_new_with_mnemonic("_?");

        menu_item_new(GTK_MENU(p_menu), "_A propos", G_CALLBACK(cb_about), user_data);

        gtk_menu_item_set_submenu(GTK_MENU_ITEM(p_menu_item), p_menu);
        gtk_menu_shell_append(GTK_MENU_SHELL(p_menu_bar), p_menu_item);
    }

    return GTK_MENU_BAR(p_menu_bar);
}
