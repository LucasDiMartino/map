#ifndef _CALLBACK_H_
#define _CALLBACK_H

#include "widget.h"

#include <gtk/gtk.h>

void cb_quit(GtkWidget *p_widget, gpointer user_data);
void cb_open_map(GtkWidget *p_widget, gpointer user_data);
void cb_open_logs(GtkWidget *p_widget, gpointer user_data);
void cb_about(GtkWidget *p_widget, gpointer user_data);
//void cb_zoom_in(GtkWidget *p_widget, gpointer user_data);

//gint cb_key_event(GtkWidget *p_widget, GdkEventKey *p_event);

#endif //_CALLBACK_H
