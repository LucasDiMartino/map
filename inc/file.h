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
