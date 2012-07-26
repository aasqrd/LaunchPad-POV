#define XTAL_2_GPIO_C
#include "xtal_2_gpio.h"

/******************************************************************//*
 * @brief   Converts Pins 2.6 and 2.7 From Default XTAL Pins to GPIOS
 * @param   None
 * @return  None
 ********************************************************************/
void xtal_2_gpio_init(void)
{
  XTAL_SEL &= ~(XIN | XOUT);                   
  XTAL_DIR |= (XIN | XOUT);
  XTAL_OUT &= ~(XIN | XOUT);
}