/*
 * spislave.c
 *
 *  Created on: Aug 24, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "spi_slave.h"
#include <avr/io.h>
void spi_masterinit()
{
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void spi_slaveinit()
{
	SPCR=(1<<SPE);
}
void spi_transmit(u8 val)
{SPDR=val;
	while(GET_BIT(SPSR,SPIF)==0){}

}
u8 spi_receive()
{
	while(GET_BIT(SPSR,SPIF)==0){}
		return SPDR;
}

