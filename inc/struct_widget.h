#ifndef _STRUCT_WIDGET_H
#define _STRUCT_WIDGET_H

#include <gtk/gtk.h>

typedef struct my_GtkMap my_GtkMap;
struct my_GtkMap
{
    GtkWidget *p_scrolled_window;
    GdkPixbuf *p_pixbuf;

    unsigned int original_width;
    unsigned int original_height;
    unsigned int min_width;
    unsigned int min_height;
    unsigned int current_width;
    unsigned int current_height;
};

#endif //_STRUCT_WIDGET_H
