#include "pins_arduino.h"
#include <genos/bus/bus_avr_spi.h>
//#include <genos/bus/bus_avr_spi_transaction.h>

namespace genos {

void avr_spi::begin() {

  // Set SS to high so a connected chip will be "deselected" by default
  digitalWrite(SS, HIGH);

  // When the SS pin is set as OUTPUT, it can be used as
  // a general purpose output port (it doesn't influence
  // SPI operations).
  pinMode(SS, OUTPUT);

  // Warning: if the SS pin ever becomes a LOW INPUT then SPI
  // automatically switches to Slave, so the data direction of
  // the SS pin MUST be kept as OUTPUT.
  _spcr  = 0x00;
  _spcr |= _BV(MSTR);
  _spcr |= _BV(SPE);
  _spcr |= SPI_MODE3;
  enable();
  
  SPSR = (1<<SPI2X);
  // Set direction register for SCK and MOSI pin.
  // MISO pin automatically overrides to INPUT.
  // By doing this AFTER enabling SPI, we avoid accidentally
  // clocking in a single bit since the lines go directly
  // from "input" to SPI control.  
  // http://code.google.com/p/arduino/issues/detail?id=888
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
}


void avr_spi::end() {
  SPCR &= ~_BV(SPE);
}

void avr_spi::setBitOrder(uint8_t bitOrder)
{
  if(bitOrder == LSBFIRST) {
    SPCR |= _BV(DORD);
  } else {
    SPCR &= ~(_BV(DORD));
  }
}

void avr_spi::setDataMode(uint8_t mode)
{
  SPCR = (SPCR & ~SPI_MODE_MASK) | mode;
}

void avr_spi::setClockDivider(uint8_t rate)
{
  SPCR = (SPCR & ~SPI_CLOCK_MASK) | (rate & SPI_CLOCK_MASK);
  SPSR = (SPSR & ~SPI_2XCLOCK_MASK) | ((rate >> 2) & SPI_2XCLOCK_MASK);
}
/*
void avr_spi::transfer(byte _data) {
  SPDR = _data;
 // while (!(SPSR & _BV(SPIF)))
 //   ;
  return; 
  //SPDR;
}*/
};


//genos::avr_spi spi;