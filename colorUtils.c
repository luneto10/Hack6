/**
 * Name: Luciano Carvalho (lguedesdecarvalhon2@huskers.unl.edu)
 *
 * Date: 2023 - 10 - 05
 *
 * Utils functions to convert RBG to CMYK and CMYK to RGB
 */

#include <stdio.h>
#include <math.h>

#include "colorUtils.h"

double max(double a, double b)
{
    return (a > b) ? (a) : (b);
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k)
{
    if (c == NULL || m == NULL || y == NULL || k == NULL)
    {
        return POINTER_NULL;
    }

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        return INVALID_NUMBER_RANGE;
    }

    double newR, newG, newB;
    newR = r / 255.0;
    newG = g / 255.0;
    newB = b / 255.0;

    *k = 1 - max(max(newR, newG), newB);
    *c = (1 - newR - (*k)) / (1 - (*k));
    *m = (1 - newG - (*k)) / (1 - (*k));
    *y = (1 - newB - *(k)) / (1 - (*k));

    if (r == 0 && g == 0 && b == 0)
    {
        *k = 1;
        *c = 0;
        *m = 0;
        *y = 0;
    }
    
    return NO_ERROR;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b)
{
    if (r == NULL || g == NULL || b == NULL)
    {
        return POINTER_NULL;
    }

    if (c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1)
    {
        return INVALID_NUMBER_RANGE;
    }

    *r = round(255 * (1 - c) * (1 - k));
    *g = round(255 * (1 - m) * (1 - k));
    *b = round(255 * (1 - y) * (1 - k));

    return NO_ERROR;
}