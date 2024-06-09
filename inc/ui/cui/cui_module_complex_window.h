/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUI_MODULE_COMPLEX_WINDOW_H
#define CUI_MODULE_COMPLEX_WINDOW_H

/* Includes ------------------------------------------------------------------*/
#include "cui_common.h"


/* Structure Declaration -----------------------------------------------------*/
// Structure to hold data in window
typedef struct {
    complex_t z;
    double result;
} cui_module_complex_window_data_t;

/* Getter and Setter Functions -----------------------------------------------*/
void CUI_MODULE_COMPLEX_WINDOW_SetComplex(complex_t z);
complex_t CUI_MODULE_COMPLEX_WINDOW_GetComplex(void);
cui_module_complex_window_data_t CUI_MODULE_COMPLEX_WINDOW_GetDataWindow(void);

/* Window Management Functions -----------------------------------------------*/
void CUI_COMPLEX_MODULE_Launch(void);
void CUI_COMPLEX_MODULE_WINDOW_DisplayMenu(void);
void CUI_COMPLEX_MODULE_GetInputFromUser(void);
void CUI_COMPLEX_MODULE_HandleUserInput(void);

/* Window Helpers Functions --------------------------------------------------*/
void CUI_COMPLEX_MODULE_DisplayResult(void);

#endif
