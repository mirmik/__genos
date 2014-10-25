


#ifndef GENOS_PLATFORM_H
#define GENOS_PLATFORM_H

#ifdef ARDUINO
#include <genos/platform/Arduino.h>

static size_t stack_pointer() {return(SP);};
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif 

#endif

#include  <genos/system/halt.h>
#include  <genos/system/time.h>
#include  <genos/platform/atomic.h>




#endif