
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SPI_INTERFACE.h"
#include"ADC_interface.h"
#include"options.h"
#include "LM35.h"
#include "TIMER_INTERFACE.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD_INTERFACE.h"
int main()
{
	LCD_voidInit();
	ADC_voidInit();


	_delay_ms(50000);
	//LCD_voidWriteNumber(LM35());

	u8 Local_u8ReceiveRoom;
	u8 Local_u8ReceiveComp;
	u8 Local_u8RecieveStatus;
	SPI_voidINITSlave();

	Local_u8ReceiveRoom = spi_receive();


	Local_u8ReceiveComp= spi_receive();

//	if(Local_u8ReceiveRoom=='1'){
//
//		ROOM(Local_u8ReceiveRoom);
//	}
//
//	else if(Local_u8ReceiveRoom=='2'){
//
//		ROOM(Local_u8ReceiveRoom);
//	}
//
//
//	else{
//
//
//	}



	if (Local_u8ReceiveComp=='1')
	{
		Local_u8RecieveStatus= spi_receive();
		//LCD_voidSendData(Local_u8RecieveStatus);
		LED(Local_u8ReceiveRoom ,Local_u8RecieveStatus );
	}

	else if (Local_u8ReceiveComp=='2')
	{
		Local_u8RecieveStatus= spi_receive();
		//LCD_voidSendData(Local_u8RecieveStatus);
		AC(Local_u8ReceiveRoom ,Local_u8RecieveStatus );
	}
	else if (Local_u8ReceiveComp=='3')
	{
		Local_u8RecieveStatus= spi_receive();
		//LCD_voidSendData(Local_u8RecieveStatus);
		TV(Local_u8ReceiveRoom ,Local_u8RecieveStatus );
	}
	else if (Local_u8ReceiveComp=='4'){
		LCD_voidGoToXY(0,0);
		LCD_voidSendString("Temperature in");
		LCD_voidGoToXY(1,0);
		LCD_voidSendString("This Room is: ");
		LCD_voidWriteNumber(LM35());



	}
	else{
	}

}





