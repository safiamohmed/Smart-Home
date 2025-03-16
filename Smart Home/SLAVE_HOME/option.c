/*
 * option.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Sara Gomaa
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "LM35.h"
#include"DIO_INTERFACE.h"
#include"ADC_interface.h"
#include"options.h"

void LED (u8  Copy_u8ROOM , u8 Copy_u8Status)
{

	if(Copy_u8ROOM=='1')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
		}}
		else if(Copy_u8ROOM=='2')
		{
			if(Copy_u8Status=='1')
			{
				DIO_u8SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);
			}
			else if(Copy_u8Status=='2')
			{
				DIO_u8SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
			}
		}
	}

void TV  (u8  Copy_u8ROOM , u8 Copy_u8Status)
{

	if(Copy_u8ROOM=='1')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN1,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN1,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);
		}}
		else if(Copy_u8ROOM=='2')
		{
			if(Copy_u8Status=='1')
			{
				DIO_u8SetPinDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUT);
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_HIGH);
			}
			else if(Copy_u8Status=='2')
			{
				DIO_u8SetPinDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUT);
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_LOW);
			}
		}
	}

void AC  (u8  Copy_u8ROOM , u8 Copy_u8Status)
{

	if(Copy_u8ROOM=='1')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
		}
		else if(Copy_u8Status==2)
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
		}}
		else if(Copy_u8ROOM=='2')
		{
			if(Copy_u8Status=='1')
			{
				DIO_u8SetPinDir(DIO_PORTC,DIO_PIN5,DIO_PIN_OUT);
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_HIGH);
			}
			else if(Copy_u8Status=='2')
			{
				DIO_u8SetPinDir(DIO_PORTC,DIO_PIN5,DIO_PIN_OUT);
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_LOW);
			}
		}
	}
void ROOM  (u8  Copy_u8ROOM )
{
	if(Copy_u8ROOM=='1')
		{

			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN6,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_HIGH);

		}
		else if(Copy_u8ROOM=='2')
		{

			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN7,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);

		}
	}
u8 LM35(void){

	DIO_u8SetPinDir(DIO_PORTA,DIO_PIN0,DIO_PORT_IN);
	u8 Local_u8Temp=0;

	Local_u8Temp=TEMP_u8Read(0);

	return Local_u8Temp;
}
