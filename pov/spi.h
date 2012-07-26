#ifndef SPI_H_
#define SPI_H_

// Microcontroller Header
#include "msp430g2553.h"

// Pin Definitions
#define SCLK	BIT5	//SPI Clock at P1.5
#define SOMI  	BIT6	//SPI SOMI (Slave Out, Master In) at P1.6
#define SIMO  	BIT7	//SPI SIMO (Slave In, Master Out) at P1.7

// Port Definitions
#define SPI_DIR		P1DIR
#define SPI_OUT		P1OUT
#define SPI_SEL		P1SEL
#define SPI_SEL2  	P1SEL2

// Function Prototypes
void spi_init(void);
void spi_write(unsigned char sdata);

#endif /*SPI_H_*/
