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
