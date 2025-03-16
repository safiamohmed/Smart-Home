#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "keypad.h"
#include "SPI_INTERFACE.h"
#include "EEPROM_interface.h"
#include "TIMER_INTERFACE.h"
#include "main_confgration.h"
#include <avr/interrupt.h>
#include <util/delay.h>
u8 pass[4]={'#','7','2','*'};

int main(){
	/*        INIT      */
	LCD_voidInit();
	KPD_INIT();
	SPI_voidINITMaster();
	/*    LCD             */
	LCD_voidSendString("HOLA,");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("IN MY SMART HOME");
	_delay_ms(50000);
	LCD_voidClearScreen();


	u8 Local_Counter=0,Local_Counter1=3,Local_flag=0;
	while(1){

		u8 Local_u8pass;
		for(Local_Counter1=3;Local_Counter1>0;Local_Counter1--){
			LCD_voidSendString("Enter Your Pass");
			LCD_voidGoToXY(1,0);
			for(Local_Counter=0;Local_Counter<4;Local_Counter++){

				do{
					Local_u8pass=KPD_u8GetPressedKey();

				}
				while(Local_u8pass==0xff );
				if(pass[Local_Counter]!=Local_u8pass){
					Local_flag=1;

				}

				LCD_voidSendData('*');
			}
			if(Local_flag==1){
				LCD_voidGoToXY(1,0);
				LCD_voidSendString("Wrong Pass");
				_delay_ms(2000);
				LCD_voidClearScreen();
				Local_flag=0;
			}
			else if(Local_flag==0) {
				LCD_voidClearScreen();
				LCD_voidSendString("OH YOUR GOOD Man");
				_delay_ms(2000);
				break;
			}
		}


		if(Local_Counter1==0){
			LCD_voidGoToXY(0,0);
			LCD_voidSendString("Sorry Try 3 Times");
			break;
		}
		Options();

		break;
	}


}

