/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#ifndef _GUI_H_
#define _GUI_H

#include "callback.h"

#include <gtk/gtk.h>

void gui_load(GtkWidget **p_main_box);
void gui_map(GtkWidget **p_main_box, char *file_map);

#endif //_GUI_H
