#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "DIO_INTERFACE.h"
#include <avr/interrupt.h>


u8 EXTI_u8SenseControl(u8 Copy_Int,u8 Copy_Sense)
{
	u8 LocalError=0;

	if(Copy_Int==INT0)
	{
		switch(Copy_Sense)
		{
		case LOW_LEVEL:CLR_BIT(MCUCR,0);CLR_BIT(MCUCR,0);break;
		case ANY_CHANGE:SET_BIT(MCUCR,0);CLR_BIT(MCUCR,1);break;
		case FALLING_EDGE:CLR_BIT(MCUCR,0);SET_BIT(MCUCR,1);break;
		case RISING_EDGE:SET_BIT(MCUCR,0);SET_BIT(MCUCR,1);break;
		default : LocalError=1;
		}
	}
	else if(Copy_Int==INT1)
	{
		switch(Copy_Sense)
		{
		case LOW_LEVEL:CLR_BIT(MCUCR,3);CLR_BIT(MCUCR,2);break;
		case ANY_CHANGE:SET_BIT(MCUCR,2);CLR_BIT(MCUCR,3);break;
		case FALLING_EDGE:CLR_BIT(MCUCR,2);SET_BIT(MCUCR,3);break;
		case RISING_EDGE:SET_BIT(MCUCR,3);SET_BIT(MCUCR,2);break;
		default : LocalError=1;
		}
	}
	else if(Copy_Int==INT2)
	{
		switch(Copy_Sense)
				{
				case FALLING_EDGE:CLR_BIT(MCUCSR,6);break;
				case RISING_EDGE:SET_BIT(MCUCSR,6);break;
				default : LocalError=1;
				}
	}
	else
	{
		//do nothing
		LocalError=1;
 }
 return LocalError;

}
u8 EXTI_u8IntEnable(u8 Copy_Int)
{
	u8 LocalError=0;

		 switch(Copy_Int)
		 {
		 case INT0:SET_BIT(GICR,6);break;
		 case INT1:SET_BIT(GICR,7);break;
		 case INT2:SET_BIT(GICR,5);break;
		 default:LocalError=1;
		 }


return LocalError;
}
u8 EXTI_u8IntDisable(u8 Copy_Int)
{
u8 LocalError=0;
	 {
		 switch(Copy_Int)
		 {
		 case INT0:CLR_BIT(GICR,6);break;
		 case INT1:CLR_BIT(GICR,7);break;
		 case INT2:CLR_BIT(GICR,5);break;
		 default: LocalError=1;
		 }
	 }
return LocalError;
}



