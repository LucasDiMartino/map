/**
 * INSA CVL Bourges
 *
 * Ce fichier est l'oeuvre d'eleves de l'INSA CVL de Bourges. Il ne peut etre
 * reproduit, ou modifie sans l'avis express de ses auteurs.
 *
 * @author DI MARTINO Lucas <lucas.di_martino-cvl.fr>
 **/

#include "../inc/conversion.h"

struct coordinates long_lat_to_lambert(double lon, double lat)
{
    struct coordinates conv;

    float lat_iso = log(tan((M_PI/4) + (lat * M_PI/(180*2))) * pow(((1 - E * sin( lat * M_PI/180)) / (1 + E * sin(lat * M_PI/180))), E / 2));
    conv.x = floor(X_P + CONSTANT_EXPONENT * exp(-PROJECTION_EXPONENT * lat_iso) * sin(PROJECTION_EXPONENT * (M_PI/180) * (lon - LON_CENTER)));
    conv.y = floor(Y_P - CONSTANT_EXPONENT * exp(-PROJECTION_EXPONENT * lat_iso) * cos(PROJECTION_EXPONENT * (M_PI/180) * (lon - LON_CENTER)));

    /*CORRECTION*/

    conv.x += 2;
    conv.y += 348;

    return conv;
}

/*LIRE LES VARIABLES DE REF !!!*/

struct point lambert_to_xy_img(struct coordinates point)
{
    struct point img;
    struct coordinates lambert_one, lambert_two;

    lambert_one.x = 648522;
    lambert_one.y = 6670399;

    lambert_two.x = 658192;
    lambert_two.y = 6659791;

/* A MODIFIER AUTO */

    unsigned long int x = 11982;
    unsigned long int y = 12973;

    img.x = x * (point.x - lambert_one.x) / (lambert_two.x - lambert_one.x);
    img.y = -y * (point.y - lambert_one.y) / (lambert_one.y - lambert_two.y);

    return img;
}
