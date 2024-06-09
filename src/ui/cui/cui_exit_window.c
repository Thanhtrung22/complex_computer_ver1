#include "ui/cui/cui_exit_window.h"

static cui_exit_window_cui_data_t cui_exit_data;

void CUI_EXIT_WINDOW_Data_Set(char answer) { cui_exit_data.answer = answer; }

char CUI_EXIT_WINDOW_Data_Get(void) { return cui_exit_data.answer; }
void CUI_EXIT_WINDOW_Launch(void)
{
    CUI_EXIT_WINDOW_DisplayMenu();
    CUI_EXIT_WINDOW_GetInputFromUser();
    CUI_EXIT_WINDOW_HandleUserInput();
    if(cui_exit_data.flag_check)
    {
        EVENT_MANAGER_TriggerSignal_ExitWindow();
        printf("\nExitting the program......");
        printf("\nSee you again");
    }
    else
    {
        EVENT_MANAGER_TriggerSignal_MainWindow();

    }

}

void CUI_EXIT_WINDOW_DisplayMenu(void)
{
    printf("\nBan co chac muon thoat khong?");
}

void CUI_EXIT_WINDOW_GetInputFromUser(void) {
    char answer = CUI_INPUT_VALIDATION_GetAnswerFromUser("Nhap cau tra loi y or n: ");
    CUI_EXIT_WINDOW_Data_Set(answer);
}

void CUI_EXIT_WINDOW_HandleUserInput(void) { 
    switch(cui_exit_data.answer)
    {
        case 'y' : case 'Y':
        {
           cui_exit_data.flag_check = true;
            break;
        }
        case 'n' : case 'N':
        {
            cui_exit_data.flag_check = false;
            break;
        }
    }
}
