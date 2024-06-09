/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUI_EXIT_WINDOW_H
#define CUI_EXIT_WINDOW_H

/* Includes ------------------------------------------------------------------*/
#include "cui_common.h"

typedef struct
{
    bool flag_check;
    char answer;
} cui_exit_window_cui_data_t;

/* Structure Declaration -----------------------------------------------------*/


void CUI_EXIT_WINDOW_Data_Set(char answer);
char CUI_EXIT_WINDOW_Data_Get(void);
/* Window Management Functions -----------------------------------------------*/
void CUI_EXIT_WINDOW_Launch(void);
void CUI_EXIT_WINDOW_DisplayMenu(void);
void CUI_EXIT_WINDOW_GetInputFromUser(void);
void CUI_EXIT_WINDOW_HandleUserInput(void);

/* Window Helpers Functions --------------------------------------------------*/

#endif /* CUI_EXIT_WINDOW_H */