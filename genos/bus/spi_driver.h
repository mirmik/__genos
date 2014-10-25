#ifndef GENOS_ARDUINO_SPI_DRIVER
#define GENOS_ARDUINO_SPI_DRIVER

#include <genos/bus/bus.h>
#include <genos/system/transaction.h>
#include <genos/bus/spi_transaction.h>
#include <genos/bus/spi_dev.h>
namespace genos{
/*
#define MISO_PB   8
#define MOSI_PB   4
#define SCK_PB    2
#define SS_PB     1
#define RESET_PB  1
*/

class spi_driver_cls : public bus_cls, public transaction_driver {
	public:
	spi_hard* spi;
	spi_driver_cls(spi_hard* _spi) : spi(_spi) {};

	spi_transaction* create_transaction(spi_dev* dev)
	{return lst.construct<spi_transaction>(spi_transaction(dev));};
	
	void add_transaction(spi_transaction* trans){
	trans->hard=spi;
	lst.__push_front(glist_container(trans));
	if ((lst.size()==1) && mode==SEARCH_NEW) interrupt(); 
	};
	
};
	
	
};


extern genos::spi_driver_cls spi_driver;

#endif