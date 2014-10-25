
#include <genos/bus/spi_driver.h>
#include <genos/bus/bus_avr_spi.h>

namespace genos {

};

ISR(SPI_STC_vect)
{
spi_driver.interrupt();
};

//genos::spi_driver_cls spi_driver(&spi);