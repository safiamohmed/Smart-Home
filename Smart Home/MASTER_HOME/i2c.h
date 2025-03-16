/*
 * i2c.h
 *
 *  Created on: Aug 26, 2023
 *      Author: nor
 */

#ifndef I2C_H_
#define I2C_H_
void TWI_MasterInit();
void TWI_Start();
void TWI_Stop();
void TWI_Send(u8 val);
u8 TWI_Receive();


#endif /* I2C_H_ */
