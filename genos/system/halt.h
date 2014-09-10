


#ifndef GENOS_HALT_H
#define GENOS_HALT_H

#include <genos/platform.h>


#ifdef ARDUINO
#include <util/delay.h>
static void halt () 
{cli();
pinMode(13,1); 
while(1)
{_delay_ms(200);
digitalWrite(13,1);
_delay_ms(200);
digitalWrite(13,0);
};
};
#endif

















#endif 