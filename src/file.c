#include "../inc/file.h"

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

    struct dll_point header;
    dll_point_init(&header);

    while(!feof(fd))
    {
        fscanf(fd, "date:%lu,lat:%lf,long:%lf;\n", &date, &lat, &lon);
        tmp = long_lat_to_lambert(lon, lat);
        
        p = lambert_to_xy_img(tmp);
        //p = point_init(date, p.x, p.y);

        g_print("%lu - %u - %u\n", date, p.x, p.y);

       // dll_point_add(&header, p);
    }

    /*struct node_point *p_node = header.first;

    while(p_node)
    {
        g_print("%u - %u - %u\n", p_node->current.date, p_node->current.x, p_node->current.y);
        
        p_node = p_node->next;
    }*/
}
