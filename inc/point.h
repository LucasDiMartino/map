/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#ifndef _POINT_H
#define _POINT_H

#include <stdio.h>
#include <stdlib.h>

struct point
{
    unsigned long int date;
    unsigned long int x;
    unsigned long int y;
};

struct point point_init(unsigned long int date, unsigned long int x, unsigned long int y);

struct node_point
{
    struct point current;
    struct node_point *prev;
    struct node_point *next;
};

struct dll_point
{
    unsigned int size;
    
    struct node_point *first;
    struct node_point *last;
};

void dll_point_init(struct dll_point *header);
void dll_point_add(struct dll_point *header, struct point new_point);
void dll_point_free(struct dll_point *header);

#endif //_POINT_H
