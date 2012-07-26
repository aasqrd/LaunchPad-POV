#ifndef SHIFT_REGISTER_H_
#define SHIFT_REGISTER_H_

// Microcontroller Header
#include "msp430g2553.h"

// Additional Headers
#include "delay.h"

// Pin Definitions
#define SHIFT_LATCH_LCD   BIT7	//pin 2.7
#define SHIFT_LATCH_IO	  BIT5	//pin 2.5

// Port Definitions
#define SHIFT_DIR     P2DIR
#define SHIFT_OUT     P2OUT

// Function Prototypes
void shift_init(void);
void latch_shift_lcd(void);
void latch_shift_io(void);

#endif /*SHIFT_REGISTER_H_*/
