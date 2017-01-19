/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#include "../inc/gui.h"
#include "../inc/menu.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    GtkWidget *p_main_window = NULL;
    GtkWidget *p_main_box = NULL;

    gtk_init(&argc, &argv);

    p_main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(p_main_window), "INSA-CVL : Bourges Map");
    gtk_window_set_position(GTK_WINDOW(p_main_window), GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_maximize(GTK_WINDOW(p_main_window));
    gtk_window_set_policy(GTK_WINDOW(p_main_window), TRUE, TRUE, FALSE);

    g_signal_connect(G_OBJECT(p_main_window), "destroy", G_CALLBACK(cb_quit), NULL);

    p_main_box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(p_main_window), p_main_box);

    gtk_box_pack_start(GTK_BOX(p_main_box), GTK_WIDGET(menu_new(NULL)), FALSE, FALSE, 0);

    gui_load(&p_main_box);

    gtk_widget_show_all(p_main_window);
    gtk_main();

    return EXIT_SUCCESS;
}
