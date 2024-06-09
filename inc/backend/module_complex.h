#ifndef MODULE_COMPLEX_H
#define MODULE_COMPLEX_H

#include "data_structure.h"


typedef struct
{
    complex_t z;
    double result;
}module_complex_t;

double module_complex(complex_t z);

/* get and set */

void MODULE_COMPLEX_SetData(complex_t z);
double MODULE_COMPLEX_GetResult(void);
void MODULE_COMPLEX_UpdateResult();

#endif