

#ifndef GENOS_HARD_DEV
#define GENOS_HARD_DEV

#include "genos.h"

namespace genos { 
class  spi_hard {

public:

// void attachInterrupt() {SPCR |= _BV(SPIE);};
// void detachInterrupt() {SPCR &= ~_BV(SPIE);};


	virtual void READ(byte* b);
	virtual void WRITE(byte* b);

	virtual void enable();
	virtual void disable();
	
};


};



#endif