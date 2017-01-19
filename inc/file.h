/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversion.h"
#include "point.h"

int read_data(const char *file_name);
void parser(FILE *fd);

#endif //_FILE_H
