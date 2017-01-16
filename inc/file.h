#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversion.h"
#include "point.h"

#define ERROR_NO_DATA -1
#define ERROR_PATH_GENERATION -2
#define ERROR_FILE_NOT_FOUND -3

int read_data(const char *file_name, const char *path_bin);
void parser(FILE *fd);

#endif //_FILE_H
