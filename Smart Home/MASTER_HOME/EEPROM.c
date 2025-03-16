/*
 * EEPROM.c
 *
 *  Created on: Aug 26, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "i2c.h"
#include "EEPROM.h"
#include <avr/io.h>
void EEBROM_Send(u16 address,u8 data)
{
	u8 SLV_W=0b10100000;
	TWI_Start();
	TWI_Send(SLV_W);
	TWI_Send((u8)address);
	TWI_Send(data);
	TWI_Stop();

}
u8 EEPROM_Receive(u16 address)
{
	u8 SLV_W=0b10100000;
	u8 SLV_R=SLV_W+1;
	TWI_Start();
	TWI_Send(SLV_W);
	TWI_Send((u8)address);
	TWI_Start();
	TWI_Send(SLV_R);
	u8 data=TWI_Receive();
	TWI_Stop();
	return data;
}
