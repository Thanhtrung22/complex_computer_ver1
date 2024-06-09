#include "ui/cui/cui_standard_calculation_window.h"

#include "backend/standard_calculation.h"

static cui_standardcalculation_window_data_t
    cui_standardcalculation_window_data;

cui_standardcalculation_window_data_t
CUI_STANDARD_CALCULATION_WINDOW_Data_GetWindowData(void)
{
    return cui_standardcalculation_window_data;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ1(complex_t z)
{
    cui_standardcalculation_window_data.z1 = z;
}

complex_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetZ1(void)
{
    return cui_standardcalculation_window_data.z1;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ2(complex_t z)
{
    cui_standardcalculation_window_data.z2 = z;
}

complex_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetZ2(void)
{
    return cui_standardcalculation_window_data.z2;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetOperator(math_operator_t op)
{
    cui_standardcalculation_window_data.op = op;
}

math_operator_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetOperator(void)
{
    return cui_standardcalculation_window_data.op;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetResult(complex_t result)
{
    cui_standardcalculation_window_data.result = result;
}

complex_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetResult(void)
{
    return cui_standardcalculation_window_data.result;
}

void CUI_STANDARD_CALCULATION_WINDOW_Launch(void)
{
    CUI_STANDARD_CALCULATION_WINDOW_DisplayMenu();
    CUI_STANDARD_CALCULATION_WINDOW_GetInputFromUser();
    CUI_STANDARD_CALCULATION_WINDOW_HandleUserInput();

    EVENT_MANAGER_TriggerSignal_MainWindow();
}

void CUI_STANDARD_CALCULATION_WINDOW_DisplayMenu(void)
{
    printf("\n\nWELCOME TO COMPLEX CALCULATOR");
    printf("\n-----------------------------");
    printf("\nMODE: STANDARD CALCULATION");
    printf("\nAvailable math operation: z1 [+,-,*,/] z2");
    printf("\nz1 = a1 + b1.i");
    printf("\nz2 = a2 + b2.i");
    printf("\n");
}

void CUI_STANDARD_CALCULATION_WINDOW_GetInputFromUser(void)
{
    complex_t z1;
    z1.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a1");
    z1.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b1");
    printf("\nReceived: z1 = %.15g + %.15g.i\n", z1.real, z1.imagine);

    complex_t z2;
    z2.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a2");
    z2.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b2");
    printf("\nReceived: z2 = %.15g + %.15g.i\n", z2.real, z2.imagine);

    math_operator_t op =
        CUI_INPUT_VALIDATION_GetOperatorFromUser("Operator [+,-,*,/]");
    printf("\nReceived: op = %c\n", op);

    CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ1(z1);
    CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ2(z2);
    CUI_STANDARD_CALCULATION_WINDOW_Data_SetOperator(op);
}

void CUI_STANDARD_CALCULATION_WINDOW_HandleUserInput(void)
{
    STANDARD_CALCULATION_SetZ1(cui_standardcalculation_window_data.z1);
    STANDARD_CALCULATION_SetZ2(cui_standardcalculation_window_data.z2);
    STANDARD_CALCULATION_SetOperator(cui_standardcalculation_window_data.op);
    STANDARD_CALCULATION_UpdateResult();
    cui_standardcalculation_window_data.result =
        STANDARD_CALCULATION_GetResult();

    CUI_STANDARD_CALCULATION_WINDOW_DisplayResult();
}

void CUI_STANDARD_CALCULATION_WINDOW_DisplayResult(void)
{
    cui_standardcalculation_window_data_t data =
        CUI_STANDARD_CALCULATION_WINDOW_Data_GetWindowData();
    switch (data.op)
    {
        case CHAR_PLUS:
        case CHAR_SUBTRACT:
        case CHAR_MULTIPLY:
        case CHAR_DIVIDE:
            printf("\nResult: (%.15g + %.15g.i) %c (%.15g + %.15g.i) = %.15g + "
                   "%.15g.i\n",
                   data.z1.real, data.z1.imagine, data.op, data.z2.real,
                   data.z2.imagine, data.result.real, data.result.imagine);
            break;

        default:
            printf("\nThis math operation is currently in development!");
            break;
    }
}
