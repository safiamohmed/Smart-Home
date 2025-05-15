#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SPI_INTERFACE.h"
#include "ADC_interface.h"
#include "options.h"
#include "LM35.h"
#include "TIMER_INTERFACE.h"
#include <util/delay.h>
#include "LCD_INTERFACE.h"

void ISR(void);

// Global variable to track AC status (1 = ON, 0 = OFF)
u8 ac_status = 0;
static u8 password_entered = 0;

int main()
{
    LCD_voidInit();
    ADC_voidInit();
    TIMER0_voidINIT();
    TIMER0_u8SetCallBack(&ISR);
    GIE_voidEnable();

    while(1)
    {
        _delay_ms(1000);
        u8 Local_u8ReceiveRoom;
        u8 Local_u8ReceiveComp;
        u8 Local_u8RecieveStatus;
        SPI_voidINITSlave();

        // Receive data from master
        Local_u8ReceiveRoom = spi_receive();

        // Check if master sent 'p' (correct password)
                if (Local_u8ReceiveRoom == 'p')
                {
                	password_entered = 1;
                	DIO_u8SetPinDir(DIO_PORTB, DIO_PIN2, DIO_PIN_OUT);
                    DIO_u8SetPinValue(DIO_PORTB, DIO_PIN2, DIO_LOW);
                    password_entered = 1; // Password entered correctly
                    // Check temperature
                    u8 Temp = LM35();
                    LCD_voidClearScreen();
                    LCD_voidGoToXY(0, 0);
                    LCD_voidSendString("Welcome!");

                    if (Temp > 22)
                    {
                        // Turn on AC for ROOM1
                        AC('1', '1'); // '1' for ROOM1, '1' to turn ON
                        AC('2', '1');
                        ac_status = 1; // Update AC status
                        LCD_voidGoToXY(1, 0);
                        LCD_voidSendString("AC: ON");
                    }
                    else
                    {
                        ac_status = 0; // Ensure AC stays OFF
                        LCD_voidGoToXY(1, 0);
                        LCD_voidSendString("Temp Too Low");
                    }
                    _delay_ms(2000); // Show message for 2 seconds
                    continue; // Wait for next transmission
                }
                else if (PIR_Check() == 1 && password_entered == 0)
                {
                    LCD_voidClearScreen();
                    LCD_voidSendString("Motion Detected!");
                    DIO_u8SetPinDir(DIO_PORTB, DIO_PIN2, DIO_PIN_OUT);
                    DIO_u8SetPinValue(DIO_PORTB, DIO_PIN2, DIO_HIGH);
                    _delay_ms(1000); // Buzzer ON for 2 seconds
                    DIO_u8SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW); // Buzzer OFF
                    continue; // Wait for next transmission
                }
                else if (PIR_Check() == 0 && password_entered == 0)
                {
                    DIO_u8SetPinDir(DIO_PORTB, DIO_PIN2, DIO_PIN_OUT);
                    DIO_u8SetPinValue(DIO_PORTB, DIO_PIN2, DIO_LOW);
                    continue; // Wait for next transmission
                }



        Local_u8ReceiveComp = spi_receive();

        if (Local_u8ReceiveComp == '1')
        {
            GET_STATUS(Local_u8ReceiveRoom, Local_u8ReceiveComp);
            Local_u8RecieveStatus = spi_receive();
            LED(Local_u8ReceiveRoom, Local_u8RecieveStatus);
        }
        else if (Local_u8ReceiveComp == '2')
        {
            GET_STATUS(Local_u8ReceiveRoom, Local_u8ReceiveComp);
            Local_u8RecieveStatus = spi_receive();
            AC(Local_u8ReceiveRoom, Local_u8RecieveStatus);
            // Update ac_status based on the command
            if (Local_u8RecieveStatus == '1') ac_status = 1;
            else if (Local_u8RecieveStatus == '2') ac_status = 0;
            // Display AC status
            LCD_voidClearScreen();
            LCD_voidGoToXY(0, 0);
            LCD_voidSendString("AC Status:");
            LCD_voidGoToXY(1, 0);
            if (ac_status == 1) LCD_voidSendString("AC: ON");
            else LCD_voidSendString("AC: OFF");
            _delay_ms(2000); // Show status for 2 seconds
        }
        else if (Local_u8ReceiveComp == '3')
        {
            GET_STATUS(Local_u8ReceiveRoom, Local_u8ReceiveComp);
            Local_u8RecieveStatus = spi_receive();
            TV(Local_u8ReceiveRoom, Local_u8RecieveStatus);
        }
        else
        {
            // Do nothing
        }
    }
}

void ISR(void)
{
    static u16 counter = 0;
    counter++;

    if (counter == 1000)
    {
        u8 Temp;
        Temp = LM35();

        if (Temp < 50)
        {
            DIO_u8SetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
            DIO_u8SetPinDir(DIO_PORTA, DIO_PIN6, DIO_PIN_OUT);
            DIO_u8SetPinValue(DIO_PORTA, DIO_PIN6, DIO_LOW);
            DIO_u8SetPinDir(DIO_PORTA, DIO_PIN7, DIO_PIN_OUT);
            DIO_u8SetPinValue(DIO_PORTA, DIO_PIN7, DIO_HIGH);

            LCD_voidClearScreen();
            LCD_voidGoToXY(0, 0);
            LCD_voidSendString("Temp= ");
            LCD_voidWriteNumber(Temp );
            LCD_voidSendData('C');
            LCD_voidGoToXY(1, 0);

            if (ac_status == 1) LCD_voidSendString("AC: ON");
            else LCD_voidSendString("AC: OFF");
        }
        else if (Temp >= 50)
        {
            DIO_u8SetPinDir(DIO_PORTA, DIO_PIN7, DIO_PIN_OUT);
            DIO_u8SetPinValue(DIO_PORTA, DIO_PIN7, DIO_LOW);
            DIO_u8SetPinDir(DIO_PORTA, DIO_PIN6, DIO_PIN_OUT);
            DIO_u8SetPinValue(DIO_PORTA, DIO_PIN6, DIO_HIGH);

            DIO_u8SetPinDir(DIO_PORTB, DIO_PIN0, DIO_PIN_OUT);
            DIO_u8SetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);

            LCD_voidClearScreen();
            LCD_voidGoToXY(0, 5);
            LCD_voidSendString("WARNING");
            _delay_ms(700);
            LCD_voidClearScreen();
            LCD_voidGoToXY(0, 3);
            LCD_voidSendString("TEMPERATURE");
            LCD_voidGoToXY(1, 4);
            LCD_voidSendString("INCREASED");

            // Turn off AC if temperature >= 50°C
            AC('1', '2'); // Turn OFF AC for ROOM1
            ac_status = 0; // Update AC status
        }

        counter = 0; // Reset counter
    }
}
