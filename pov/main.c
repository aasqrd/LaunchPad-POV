// Microcontroller Header
#include "msp430g2553.h"

// Library Headers
#include "delay.h"
#include "shift_register.h"
#include "spi.h"
#include "xtal_2_gpio.h"

void pov(unsigned char top_nibble, unsigned char bottom_nibble)
{
	spi_write(bottom_nibble);
	spi_write(top_nibble);
	latch_shift_io();
	_delay_ms(15);
}

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  
  BCSCTL1 = CALBC1_16MHZ;                   // Set range
  DCOCTL = CALDCO_16MHZ;                    // Set DCO step and modulation
  
  xtal_2_gpio_init();
  spi_init();
  shift_init();
  
  // Initialize Pushbutton on Pin 1.3
  P1OUT |= BIT3;
  P1REN |= BIT3;                            // P1.x pullup
  P1IE  |= BIT3;                            // P1.x interrupt enabled
  P1IES |= BIT3;                            // P1.x Hi/lo edge
  P1IFG &= ~BIT3;                           // P1.x IFG cleared
  
  _BIS_SR(LPM0_bits | GIE);                // Enter LPM4 w/interrupt
}
  
// Port 1 ISR
#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
  _delay_ms(500);
  pov(0,0);
  pov(240,0);
  pov(240,0);
  pov(192,0);
  pov(199,0);
  pov(198,3);
  pov(198,7);
  pov(255,255);
  pov(255,255);
  pov(198,7);
  pov(198,3);
  pov(199,0);
  pov(192,0);
  pov(240,0);
  pov(240,0);
  pov(0,0);   
  pov(15,240);
  pov(16,8);
  pov(32,4);
  pov(64,2);
  pov(135,129);
  pov(136,65);
  pov(136,65);
  pov(136,65);
  pov(132,129);
  pov(131,193);
  pov(64,66);
  pov(32,132);
  pov(19,8);
  pov(12,48);
  pov(0,0);
  pov(128,129);
  pov(128,129);
  pov(255,255);
  pov(128,129);
  pov(128,129);
  pov(0,0);
  pov(255,255);
  pov(145,96);
  pov(145,24);
  pov(145,6);
  pov(145,255);
  pov(0,0);
  pov(195,98);
  pov(36,145);
  pov(24,145);
  pov(36,145);
  pov(195,78);
  pov(0,0);
  pov(63,128);
  pov(72,128);
  pov(136,255);
  pov(72,128);
  pov(63,128);
  pov(0,0);
  pov(98,255);
  pov(145,136);
  pov(145,140);
  pov(145,138);
  pov(78,113);
  pov(0,0);
  pov(0,254);
  pov(0,1);
  pov(0,1);
  pov(0,1);
  pov(0,254);
  pov(0,0);
  pov(0,255);
  pov(0,64);
  pov(0,48);
  pov(0,64);
  pov(0,255);
  pov(0,0);
  pov(0,255);
  pov(0,145);
  pov(0,145);
  pov(0,145);
  pov(0,145);
  pov(0,0);
  pov(0,255);
  pov(0,96);
  pov(0,24);
  pov(0,6);
  pov(0,255);
  pov(0,0);
  pov(0,128);
  pov(0,128);
  pov(0,255);
  pov(0,128);
  pov(0,128);
  pov(0,0);
  pov(0,98);
  pov(0,145);
  pov(0,145);
  pov(0,145);
  pov(0,78);
  pov(0,0);
 
  //timer_A_delay_set_reset();
  P1IFG &= ~BIT3;                     // P1.x IFG cleared
}
