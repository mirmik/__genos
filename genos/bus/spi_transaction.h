
#ifndef GENOS_ARDUINO_SPI_TRANSACTION
#define GENOS_ARDUINO_SPI_TRANSACTION


#include <genos/container/manual_gstring.h>
#include <genos/bus/bus.h>
#include <genos/system/transaction.h>
#include <genos/bus/spi_dev.h>
#include <genos/bus/spi_hard.h>
#include <genos_obj.h>

namespace genos{

class spi_transaction : public transaction {
public:
manual_gstring gs;
spi_dev *dev;
spi_hard *hard;


public:
int iter;
	spi_transaction() : iter(0) {};
	
	spi_transaction(spi_dev* _dev) : iter(0), dev(_dev) {};
	
	trans_return exec(){
	
	if (status.sts(IS_CMD)) {
	switch(status.get_cntr(4,4))
	{
	case 0: dev->init(); break;
	
	default: break;
	};
	goto last;
	};	
	
	//strmout << "iter:" << iter << endl;
	if (iter==0) {dev->select(); goto write;};  	
	
	hard->READ(gs.begin() + iter - 1);	if (iter>=gs.size()) goto last;		 
	write: {
	hard->WRITE(gs.begin() + iter); goto exit;};
	
	last: status.set(IS_FINISHED);
	
	exit:
	iter++;
	if (status.sts(IS_FINISHED)) {dev->deselect(); return FINISH;}
	return WORK;
	};
	
	void destruct(){gs.destruct();
	//delete glist_container(this);
	};
	
};
};


#endif