#include <project.h>
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow usage of the floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define USBFS_DEVICE    (0u)

/* The buffer size is equal to the maximum packet size of the IN and OUT bulk
* endpoints.
*/
#define USBUART_BUFFER_SIZE (64u)
#define LINE_STR_LENGTH     (20u)


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main function performs the following actions:
*   1. Waits until VBUS becomes valid and starts the USBFS component which is
*      enumerated as virtual Com port.
*   2. Waits until the device is enumerated by the host.
*   3. Waits for data coming from the hyper terminal and sends it back.
*   4. PSoC3/PSoC5LP: the LCD shows the line settings.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
uint8 command[64], i=0;

void USB_initialization()
{


     /* Host can send double SET_INTERFACE request. */
    if (0u != USBUART_IsConfigurationChanged())
    {
        /* Initialize IN endpoints when device is configured. */
        if (0u != USBUART_GetConfiguration())
        {
            /* Enumeration is done, enable OUT endpoint to receive data 
             * from host. */
            USBUART_CDC_Init();
        }
    }
}

void USB_Print(char8 * outText)
{
    while (USBUART_CDCIsReady() == 0u){} //wait for usbuart to be ready
    USBUART_PutData((uint8 *) outText, strlen(outText));
}

void parse_command()
{
    
    char comm[5];
    //while (0u == USBUART_CDCIsReady()){}
    //USBUART_PutString("Parse Received: ");
    //USB_Print((char *) command);
    strncpy(comm, (char *)command, 4);
    comm[4] = '\0';
    USB_Print((char *) comm);
    USB_Print((char *)"\r\n");
    
         
    if (strcmp(comm, "star") == 0)
    {
        while (0u == USBUART_CDCIsReady()){}
        USBUART_PutString ("Found STAR\r\n");
        PWM_1_Start();
        
    }
    else if(strcmp(comm, "stop") == 0)
    {
        while (0u == USBUART_CDCIsReady()){}
        USBUART_PutString ("Found STOP\r\n");
        PWM_1_Stop();
    }
   
    else 
    {
        while (0u == USBUART_CDCIsReady()){}
        int atoi(const char*str), COMP;
        COMP=atoi(comm);
        
        PWM_1_Start();
        PWM_1_WriteCompare(COMP);  
         
    }   
           
    
    
}

void USB_GetCommand()
{
    uint16 count;
    uint8 buffer[64], j;
    
    if (0u != USBUART_GetConfiguration())
        {
            /* Check for input data from host. */
            if (0u != USBUART_DataIsReady())
            {
                /* Read received data and re-enable OUT endpoint. */
                count = USBUART_GetAll(buffer);

                if (0u != count)
                {

                    while (USBUART_CDCIsReady() == 0u){} //wait for usbuart to be ready
                    USBUART_PutData(buffer, count);
                    /* Send data back to host. */

                    for (j=0;j<count;j++)
                    {
                        command[i+j] = buffer[j];
                        if (buffer[j] == 0xD)
                        {
                            //while (0u == USBUART_CDCIsReady()){}
                            //USBUART_PutString("Found CR! \n\r");
                            command [i+j] = '\r';
                            command [i+j+1] = '\n';
                            command [i+j+2] = '\0';
                            //USB_Print((char *)command);
                            
                            i=0;
                            count = 0;
                            parse_command();
                        }
                    }
                    
                    i+=count;
                    
                    /* If the last sent packet is exactly the maximum packet 
                    *  size, it is followed by a zero-length packet to assure
                    *  that the end of the segment is properly identified by 
                    *  the terminal.
                    */
                    if (USBUART_BUFFER_SIZE == count)
                    {
                        /* Wait until component is ready to send data to PC. */
                        while (0u == USBUART_CDCIsReady()){}

                        /* Send zero-length packet to PC. */
                        USBUART_PutData(NULL, 0u);
                    }
                }
            }

        }
}



int main()
{
    uint16 getCCD;
    char CCDReading[64];
    CyGlobalIntEnable;

    /* Start USBFS operation with 5-V operation. */
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION);
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    Control_Reg_1_Write(0b00000001);
    for(;;)
    {
       
        USB_initialization();
        USB_GetCommand();
        ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
        
        getCCD = ADC_SAR_1_GetResult16();      
        getCCD = getCCD * 5000 / 4096;
        sprintf(CCDReading, "%hu\r\n", getCCD);
        USB_Print(CCDReading);
        
        //sprintf(plebbie, "Your temperature is %.4f K \r\n", temperature);
        
        
        
        
        //while (USBUART_CDCIsReady() == 0u){}
        
        
        //USB_Print((char8 *)command);
        
        
    }
}



/* [] END OF FILE */