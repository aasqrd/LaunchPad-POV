#ifndef DELAY_H_
#define DELAY_H_

#include "msp430g2553.h"
#define F_CPU 16000000UL

// Delay Functions
#define _delay_ns(__ns) \
  if((unsigned long) (F_CPU/1000000000.0 * __ns) != F_CPU/1000000000.0 * __ns)\
        __delay_cycles((unsigned long) ( F_CPU/1000000000.0 * __ns)+1);\
  else __delay_cycles((unsigned long) ( F_CPU/1000000000.0 * __ns))
#define _delay_us(__us) \
  if((unsigned long) (F_CPU/1000000.0 * __us) != F_CPU/1000000.0 * __us)\
        __delay_cycles((unsigned long) ( F_CPU/1000000.0 * __us)+1);\
  else __delay_cycles((unsigned long) ( F_CPU/1000000.0 * __us))
#define _delay_ms(__ms) \
  if((unsigned long) (F_CPU/1000.0 * __ms) != F_CPU/1000.0 * __ms)\
        __delay_cycles((unsigned long) ( F_CPU/1000.0 * __ms)+1);\
  else __delay_cycles((unsigned long) ( F_CPU/1000.0 * __ms))
#define _delay_s(__s) \
  if((unsigned long) (F_CPU/1.0 * __s) != F_CPU/1.0 * __s)\
        __delay_cycles((unsigned long) ( F_CPU/1.0 * __s)+1);\
  else __delay_cycles((unsigned long) ( F_CPU/1.0 * __s))

#endif /*DELAY_H_*/
