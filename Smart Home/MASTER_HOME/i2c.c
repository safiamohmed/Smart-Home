/*
 * i2c.c
 *
 *  Created on: Aug 26, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "i2c.h"
#include <avr/io.h>

void TWI_MasterInit()
{
	TWBR=255;
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	TWCR=(1<<TWEN);
}
void TWI_Start()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(GET_BIT(TWCR,TWINT)==0){}

}
void TWI_Stop()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
void TWI_Send(u8 val)
{
	TWDR=val;
	TWCR=(1<<TWINT)|(1<<TWEN);
		while(GET_BIT(TWCR,TWINT)==0){}
}
u8 TWI_Receive()
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0){}
	return TWDR;
}
