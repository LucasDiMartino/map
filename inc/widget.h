/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <gtk/gtk.h>

GtkWidget *find_child(GtkWidget *parent, const gchar *name);

#endif //_WIDGET_H_
