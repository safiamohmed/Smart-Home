/***************************************************/
/*************     Author: Sara Gomaa **************/
/*************     Layer:   MCAL      **************/
/*************     SWC:     ADC       **************/
/*************     Version: 1.00      **************/
/***************************************************/
/***************************************************/


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define   ADMUX           *((volatile  u8*)0X27)
#define   ADMUX_REFS1         7
#define   ADMUX_REFS0         6
#define   ADMUX_ADLAR         5
#define   ADMUX_MUX4          4
#define   ADMUX_MUX3          3
#define   ADMUX_MUX2          2
#define   ADMUX_MUX1          1
#define   ADMUX_MUX0          0


 #define  ADCSRA         *((volatile  u8*)0X26)
 #define  ADCSRA_ADEN        7
 #define  ADCSRA_ADSC        6
 #define  ADCSRA_ADATE       5
 #define  ADCSRA_ADIF        4
 #define  ADCSRA_ADIE        3
 #define  ADCSRA_ADPS2       2
 #define  ADCSRA_ADPS1       1
 #define  ADCSRA_ADPS0       0




 #define  ADCH          *((volatile  u8*)0X25)
 #define  ADCL          *((volatile  u8*)0X24)




 #define  SFIOR         *((volatile  u8*)0X50)
 #define  SFIOR_ADT2        7
 #define  SFIOR_ADT1        6
 #define  SFIOR_ADT0        5


#endif  /*  ADC_REGISTER_H_  */
