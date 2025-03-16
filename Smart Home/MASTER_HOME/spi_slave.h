/*
 * spi_slave.h
 *
 *  Created on: Aug 24, 2023
 *      Author: nor
 */

#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_


void spi_masterinit();
void spi_slaveinit();
void spi_transmit(u8 val);
u8 spi_receive();

#endif /* SPI_SLAVE_H_ */
