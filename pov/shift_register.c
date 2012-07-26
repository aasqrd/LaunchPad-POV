#include "shift_register.h"

/***************************************************************************//*
 * @brief   Initialize Shift Register Latch and Clock BITS
 * @param   None
 * @return  None
 *****************************************************************************/
void shift_init(void)
{
  SHIFT_DIR |= (SHIFT_LATCH_LCD | SHIFT_LATCH_IO);
  SHIFT_OUT &= ~(SHIFT_LATCH_LCD | SHIFT_LATCH_IO); 
}

void latch_shift_lcd(void)
{
  SHIFT_OUT |= SHIFT_LATCH_LCD;
  //_delay_us(500);
  SHIFT_OUT &= ~SHIFT_LATCH_LCD;  
}

void latch_shift_io(void)
{
  SHIFT_OUT |= SHIFT_LATCH_IO;
  //_delay_us(500);
  SHIFT_OUT &= ~SHIFT_LATCH_IO;  
}