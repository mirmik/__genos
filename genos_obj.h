
#ifndef GENOS_OBJ_H
#define GENOS_OBJ_H

#include <genos.h>

#ifdef STREAM_OUTPUT
#include <genos/io/o.h>
extern genos::ostream strmout;
//extern genos::ostream strmout;
extern genos::ostream strmdebug;
#endif


/*
#ifdef ARDUINO_SPI
#include <genos/bus/spi/SPI_transaction.h>
extern genos::SPI_driver_cls SPI_driver;
#endif
*/
/*
#ifdef CRIUS_SPI_DATAFLASH
#include <genos/board/CRIUS_spi_dataflash.h>
extern CRIUS_spi_dataflash CRIUS_dataflash;
#endif
*/

#endif