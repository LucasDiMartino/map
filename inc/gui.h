#ifndef _GUI_H_
#define _GUI_H

#include "callback.h"
#include "struct_widget.h"

#include <gtk/gtk.h>

void gui_load(GtkWidget **p_main_box);
void gui_map(GtkWidget **p_main_box, char *file_map);

#endif //_GUI_H
