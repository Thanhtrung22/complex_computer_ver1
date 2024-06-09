#include "backend/module_complex.h"

#include <math.h>

static module_complex_t module_complex_var;

void MODULE_COMPLEX_SetData(complex_t z)
{
    module_complex_var.z = z;
}
double module_complex(complex_t z)
{
    double result = 0;

    result = sqrt(z.real * z.real + z.imagine * z.imagine);
    return result;
}

void MODULE_COMPLEX_UpdateResult()
{
   
    double result = module_complex(module_complex_var.z);
    module_complex_var.result = result;
}

double MODULE_COMPLEX_GetResult(void)
{
    return module_complex_var.result;
}