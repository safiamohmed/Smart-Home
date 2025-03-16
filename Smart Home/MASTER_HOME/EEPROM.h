/*
 * EEPROM.h
 *
 *  Created on: Aug 26, 2023
 *      Author: nor
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEBROM_Send(u16 address,u8 data);
u8 EEPROM_Receive(u16 address);
#endif /* EEPROM_H_ */
