




#ifndef GENOS_AVR_SPI_H
#define GENOS_AVR_SPI_H

#include <stdio.h>
//#include <genos.h>
#include <avr/pgmspace.h>
#include <genos/bus/spi_hard.h>

#include <genos/bus/bus.h>
#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06
//#define SPI_CLOCK_DIV64 0x07

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR


namespace genos { 
class avr_spi : public spi_hard {
byte _spcr;

public:

	void begin();
	void end();

public:
 
  void transfer(byte _data);
  
  static void setBitOrder(uint8_t);
  static void setDataMode(uint8_t);
  static void setClockDivider(uint8_t);
  
  
void attachInterrupt() {SPCR |= _BV(SPIE);};
void detachInterrupt() {SPCR &= ~_BV(SPIE);};


	void READ(byte* b){*b = SPDR;};
	void WRITE(byte* b){SPDR = *b;};
	
	inline void spcr(byte b){_spcr=b;};
	
	void enable(){SPCR = _spcr;};
	void disable(){SPCR=0;};

};


};

extern genos::avr_spi spi;


#endif

