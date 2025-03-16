#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"


void EEPROM_voidSendData(u16 Copy_u16Address,u8 Copy_u8Data)
{
	/*1010(A2)(B1)(B0)(W/R)*/
	u8 SLV_W=0b10100000;

	TWI_voidStartCondition();

	/*BLOCK SELECTION WITH WRITE*/
	TWI_voidSendData(SLV_W);

	/*BYTE SELECTION IN THE DESIRED BLOCK*/
	TWI_voidSendData((u8)Copy_u16Address);

	/*SENDING THE DATA*/
	TWI_voidSendData(Copy_u8Data);

	TWI_voidStopCondition();
}

u8 EEPROM_voidReceiveData(u16 Copy_u16Address)
{
	u8 SLV_W=0b10100000;
	u8 SLV_R=SLV_W+1;

	TWI_voidStartCondition();
	TWI_voidSendData(SLV_W);
	TWI_voidSendData((u8)Copy_u16Address);


	TWI_voidStartCondition();
	TWI_voidSendData(SLV_R);

	u8 Data=TWI_u8ReceiveData();

	TWI_voidStopCondition();
	return Data;
}
