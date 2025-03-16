#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define INT0  1
#define INT1  2
#define INT2  3


#define LOW_LEVEL      1
#define ANY_CHANGE     2
#define FALLING_EDGE   3
#define RISING_EDGE    4


u8 EXTI_u8SenseControl(u8 Copy_u8Int,u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisable(u8 Copy_u8Int);

#endif /* EXTI_INTERFACE_H_ */
