#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include <avr/io.h>

#include "TIMER_INTERFACE.h"



void TIMER0_voidOfInit(void)
{
/*NORMAL MODE WAVEFORM*/
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);

	/*PRESCALLER BY 8*/

	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	/*ENABLE THE INTERRUPT*/

	SET_BIT(TIMSK,TOIE0);


}
void TIMER0_voidCtcInit(void)
{

	/*CTC MODE WAVEFORM*/
		SET_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);

	/*PRESCALLER BY 64*/

		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);

		/*ENABLE THE INTERRUPT*/

		SET_BIT(TIMSK,OCIE0);
}


void TIMER0_voidPWMFastInit(void)
{
	/*FAST PMW*/
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);

	/*NON-INVERTED MODE*/

	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);

	/*PRESCALLER BY 8*/
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


void TIMER0_voidCtcValue(u8 Copy_u8Value)
{
	OCR0=Copy_u8Value;
}
void TIMER0_voidPreLoadValue(u8 Copy_u8Value)
{
	TCNT0=Copy_u8Value;
}

