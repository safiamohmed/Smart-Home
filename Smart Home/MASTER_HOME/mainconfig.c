/*
 * mainconfig.c
 *
 *  Created on: Sep 5, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "keypad.h"
#include "main_confgration.h"
#include "SPI_INTERFACE.h"
#include <util/delay.h>
void ROOM_OPTIONS(u8 roomnum){
	u8 Local_press=0,Local_flag=0;

	/*if(roomnum=='1'){

		spi_transmit(roomnum);
	}
	else if(roomnum=='2'){

			spi_transmit(roomnum);
		}*/
	if(roomnum=='1'){
		DIO_u8SetPinDir(DIO_PORTD,DIO_PIN3,DIO_PIN_OUT);
		DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);}
	else if(roomnum=='2'){
		DIO_u8SetPinDir(DIO_PORTD,DIO_PIN4,DIO_PIN_OUT);
		DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_HIGH);
	}

	LCD_voidClearScreen();
	LCD_voidSendString("1-LIGHT ");
	LCD_voidGoToXY(0,7);
	LCD_voidSendString("2-AC ");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("3-TV ");
	LCD_voidGoToXY(1,7);
	LCD_voidSendString("4-TEMP");
	do{
		Local_press=KPD_u8GetPressedKey();

	}
	while(Local_press==0xff );

	spi_transmit(Local_press);
     /*CONTROLL LED*/
	if(Local_press=='1'){
		LCD_voidClearScreen();
		LCD_voidSendString("1-ON ");
		LCD_voidGoToXY(0,7);
		LCD_voidSendString("2-OFF");
		do{
			Local_press=KPD_u8GetPressedKey();

		}
		while(Local_press==0xff );
		spi_transmit(Local_press);

	}
	/*CONTROLL AC*/
	else if(Local_press=='2')
	{
		LCD_voidClearScreen();
		LCD_voidSendString("1-ON ");
		LCD_voidGoToXY(0,7);
		LCD_voidSendString("2-OFF");
		do{
			Local_press=KPD_u8GetPressedKey();

		}
		while(Local_press==0xff );
		spi_transmit(Local_press);


	}
	/*CONTROLL TV*/
	else if(Local_press=='3')
	{
		LCD_voidClearScreen();
		LCD_voidSendString("1-ON ");
		LCD_voidGoToXY(0,7);
		LCD_voidSendString("2-OFF");
		do{
			Local_press=KPD_u8GetPressedKey();

		}
		while(Local_press==0xff );
		spi_transmit(Local_press);

	}
	/*CONTROLL TEMP*/
	else if(Local_press=='4'){
		LCD_voidClearScreen();





	}



}



void Options(void){
	u8 Local_press=0,Local_flag=0;
	LCD_voidClearScreen();
	LCD_voidSendString("1-ROOM1:");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("2-ROOM2:");

	do{
		Local_press=KPD_u8GetPressedKey();

	}
	while(Local_press==0xff );


	if(Local_press!=0){
		Local_flag=1;

	}
	if(Local_flag==1){
		spi_transmit(Local_press);
		LCD_voidSendData(Local_press);
		ROOM_OPTIONS(Local_press);


	}

}

