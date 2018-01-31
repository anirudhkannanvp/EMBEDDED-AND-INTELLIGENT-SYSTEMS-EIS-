/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include "stdio.h"
int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    AMux_1_Start();
    ADC_DelSig_1_Start();
    UART_1_Start();
    ADC_DelSig_1_StartConvert();
    char msg[32];
    int k = 1;
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    
    for(;;)
    {
        
        /* Place your application code here. */
        AMux_1_Select(k);
        if(Timer_1_ReadCounter()==250){
            if(ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_RETURN_STATUS))
            {
             if(k==0){
                sprintf(msg, "Tempature = %d\n", (ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_GetResult16()))/10);
                k=1;
            }
            else{
                sprintf(msg, "LDR = %d\n", ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_GetResult16()));
                k=0;
            }
            }
            UART_1_PutString(msg);
        }
    }
}

/* [] END OF FILE */
