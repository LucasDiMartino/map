/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#ifndef _CALLBACK_H_
#define _CALLBACK_H

#include "widget.h"
#include "../inc/gtk-image-viewer.h"

#include <gtk/gtk.h>

void cb_quit(GtkWidget *p_widget, gpointer user_data);
void cb_open_map(GtkWidget *p_widget, gpointer user_data);
void cb_open_logs(GtkWidget *p_widget, gpointer user_data);
void cb_about(GtkWidget *p_widget, gpointer user_data);
void cb_image_annotate(GtkImageViewer *imgv, GdkPixbuf *pixbuf, gint shift_x, gint shift_y, gdouble scale_x, gdouble scale_y, gpointer user_data);

#endif //_CALLBACK_H
