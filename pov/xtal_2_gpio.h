#ifndef XTAL_2_GPIO_H_
#define XTAL_2_GPIO_H_

// Microcontroller Header
#include "msp430g2553.h"

//Pin Definitions
#define XIN 		 BIT6
#define XOUT		 BIT7

// Port Definitions
#define XTAL_DIR     P2DIR
#define XTAL_OUT     P2OUT
#define XTAL_SEL     P2SEL

// Function Prototypes
void xtal_2_gpio_init(void);

#endif /*XTAL_2_GPIO_H_*/
