

#ifndef GENOS_CRIUS_SPI_DATAFLASH
#define GENOS_CRIUS_SPI_DATAFLASH

#include <genos/bus/spi_dev.h>
#include <avr/io.h>
#include <genos/system/time.h>
#include <genos/bus/bus_avr_spi.h>

#define DF_MISO_PB   8
#define DF_MOSI_PB   4
#define DF_SCK_PB    2
#define DF_SS_PB     1
#define DF_RESET_PB  1
//*  Драйвер Atmel DataFlash

namespace genos{


class CRIUS_spi_dataflash : public spi_dev {
public:
void select(){PORTB &= ~DF_SS_PB;};
void deselect(){PORTB |= DF_SS_PB;};



void init()
{
	spi.disable();
   //SPCR = 0; // Отключаем SPI чтобы сконфигурировать направление ножек
   deselect();

 //  DDRB &= ~(DF_MISO_PB);

//   DDRB |= DF_MOSI_PB + DF_SCK_PB + DF_SS_PB;    
	DDRG |= DF_RESET_PB;
   
   PORTG &= ~DF_RESET_PB;  // сбрасываем dataflsah
   delay(10);          // RESET Pulse Width = 10us
   PORTG |= DF_RESET_PB;
   delay(1);           // RESET Recovery Time = 1us

   spi.enable();
   return;
};
};

};

extern genos::CRIUS_spi_dataflash CRIUS_dataflash;










#endif