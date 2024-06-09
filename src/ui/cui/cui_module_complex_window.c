#include "ui/cui/cui_module_complex_window.h"
#include "backend/module_complex.h"

static cui_module_complex_window_data_t cui_module_complex_window_data;

void CUI_MODULE_COMPLEX_WINDOW_SetComplex(complex_t z)
{
    cui_module_complex_window_data.z = z;
    
}


cui_module_complex_window_data_t CUI_MODULE_COMPLEX_WINDOW_GetDataWindow(void)
{
    return cui_module_complex_window_data;
}

void CUI_COMPLEX_MODULE_Launch(void)
{
    CUI_COMPLEX_MODULE_WINDOW_DisplayMenu();
    CUI_COMPLEX_MODULE_GetInputFromUser();
    CUI_COMPLEX_MODULE_HandleUserInput();

    EVENT_MANAGER_TriggerSignal_MainWindow();

}

void CUI_COMPLEX_MODULE_GetInputFromUser(void)
{
    complex_t z;
    z.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a");
    z.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b");
    printf("\nReceived: z1 = %.15g + %.15g.i\n", z.real, z.imagine);

    CUI_MODULE_COMPLEX_WINDOW_SetComplex(z);
}
void CUI_COMPLEX_MODULE_HandleUserInput(void)
{
    MODULE_COMPLEX_SetData(cui_module_complex_window_data.z);
    MODULE_COMPLEX_UpdateResult();
     cui_module_complex_window_data.result = MODULE_COMPLEX_GetResult();

    CUI_COMPLEX_MODULE_DisplayResult();
}

void CUI_COMPLEX_MODULE_DisplayResult(void)
{
    printf("Module cua so phuc vua nhap la: %.15g", cui_module_complex_window_data.result);
}

void CUI_COMPLEX_MODULE_WINDOW_DisplayMenu(void)
{
    printf("\n\nWELCOME TO COMPLEX CALCULATOR");
    printf("\n-----------------------------");
    printf("\nMODE: MODULE CALCULATION");
    printf("\nz = a + b.i");
    printf("\n");
}