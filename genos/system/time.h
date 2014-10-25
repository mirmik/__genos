


#ifndef GENOS_TIME
#define GENOS_TIME

#include <genos/platform.h>


namespace genos {




static void cpu_delay(long a) __attribute__((always_inline));

static void cpu_delay(long a)
{
volatile long long b = a * a;
while (b--);
return;
};

#ifndef ARDUINO
//#include "Arduino.h"
// delay. //_delay_ms
#endif



};




#endif