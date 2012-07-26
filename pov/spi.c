#include "spi.h"

/******************************************************************//*
 * @brief   3-wire Master SPI Initialization
 * @param   None
 * @return  None
 ********************************************************************/ 
void spi_init(void)
{
  // (1)
  UCB0CTL1 = UCSWRST;		// Put state machine in reset
  
  // (2)
  SPI_SEL  |= SCLK | SIMO;
  SPI_SEL2 |= SCLK | SIMO;
  
  // (3) 3-pin, 8-bit SPI master           
  UCB0CTL0 = UCCKPH | UCMST | UCSYNC; 
                                          
  UCB0CTL1 |= UCSSEL_2;		// Use SMCLK
  
  //Timing SMCLK / (UCBxBR0 + UCBxBR1 × 256)
  UCB0BR0 = 10;			// Initial SMCLK Clock to 16 MHz 
  UCB0BR1 = 0;				// f_UCxCLK = 16MHz/128 = 125 KHz
  
  // (4)
  UCB0CTL1 &= ~UCSWRST;		// Release USCI state machine
}

/******************************************************************//*
 * @brief   Pushes data into SPI transmit buffer for serial writes 
 * @param   SPI data out
 * @return  None
 ********************************************************************/
void spi_write(unsigned char sdata)
{
  UCB0TXBUF = sdata;
  while (UCB0STAT & UCBUSY);//  Wait for SPI transmission to complete
}
