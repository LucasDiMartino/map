#ifndef _CONVERSION_H
#define _CONVERSION_H

#include "point.h"

#include <math.h>

#define E 0.08248325676
#define PROJECTION_EXPONENT 0.7256077650
#define CONSTANT_EXPONENT 11754255.426
#define X_P 700000.000
#define Y_P 12655612.050
#define LON_CENTER 3.0

struct coordinates
{
    unsigned long int x;
    unsigned long int y;
};

struct coordinates long_lat_to_lambert(double lon, double lat);
struct point lambert_to_xy_img(struct coordinates lambert);

#endif //_CONVERSION_H
