#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
/*
 * TIMER0_voidOfInit: initialization Normal Mode for TIMER0
 *
 * TIMER0_voidCtcInit: initialization Compare Match Mode for TIMER0
 *
 * TIMER0_voidPWMFastInit: initialization Normal Mode for TIMER0
 *
 * TIMER0_voidCtcValue: To Set Compare Value
 *
 *TIMER0_voidPreLoadValue: To Set PRELOAD Value
 *
 */



/*****************PROTOTYPE***********************/
void TIMER0_voidOfInit(void);
void TIMER0_voidCtcInit(void);
void TIMER0_voidCtcValue(u8 Copy_u8Value);
void TIMER0_voidPreLoadValue(u8 Copy_u8Value);
void TIMER0_voidPWMFastInit(void);

#endif /* TIMER_INTERFACE_H_ */
