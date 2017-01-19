/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#include "../inc/file.h"

extern struct dll_point header;

int read_data(const char *file_name)
{
    if(file_name)
    {
        FILE *fd = fopen(file_name, "r");

        if(fd)
        {
            parser(fd);
            fclose(fd);

            return 0;
        }

    }

    return -1;
}

void parser(FILE *fd)
{
    double lon, lat;
    unsigned long int date;

    struct coordinates tmp;

    struct point p;

    dll_point_init(&header);

    while(!feof(fd))
    {
        fscanf(fd, "date:%lu,lat:%lf,long:%lf;\n", &date, &lat, &lon);
        tmp = long_lat_to_lambert(lon, lat);
        
        p = lambert_to_xy_img(tmp);
        p = point_init(date, p.x, p.y);

        dll_point_add(&header, p);
    }
}
