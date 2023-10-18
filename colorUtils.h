/**
 * Name: Luciano Carvalho (lguedesdecarvalhon2@huskers.unl.edu)
 *
 * Date: 2023 - 10 - 05
 *
 * Utils header files to convert RBG to CMYK and CMYK to RGB
 */

typedef enum
{
    NO_ERROR,
    INVALID_NUMBER_RANGE,
    POINTER_NULL,
} ErrorCode;

/* Returns the bigger value between two given numbers
 */
double max(double a, double b);

/*Tranforms RGB values to CMYK values
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/*Tranforms CMYK values to RGB values
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);