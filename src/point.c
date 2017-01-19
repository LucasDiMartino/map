/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#include "../inc/point.h"

#include <gtk/gtk.h>

struct point point_init(unsigned long int date, unsigned long int x, unsigned long int y)
{
    struct point new_point;

    new_point.date = date;
    new_point.x = x;
    new_point.y = y;

    return new_point;
}

void dll_point_init(struct dll_point *header)
{
    header->first = NULL;
    header->last = NULL;
    header->size = 0;
}

void dll_point_add(struct dll_point *header, struct point new_point)
{
    struct node_point *new_node = (struct node_point *)malloc(sizeof(struct node_point));

    if(new_node)
    {
        new_node->current = new_point;
        new_node->next = NULL;
        new_node->prev = header->last;

        if(header->last)
        {
            header->last->next = new_node;
        }

        else
        {
            header->first = new_node;
        }

        header->last = new_node;
        header->size++;
    }
}

void dll_point_free(struct dll_point *header)
{
    struct node_point *tmp = NULL;
    struct node_point *p_node = header->first;

    while(p_node)
    {
        tmp = p_node;
        p_node = p_node->next;

        free(tmp);
    }

    header->first = NULL;
    header->last = NULL;
    header->size = 0;
}
