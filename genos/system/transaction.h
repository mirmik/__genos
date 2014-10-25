



#ifndef GENOS_TRANSACTION
#define GENOS_TRANSACTION

#include <genos/container/flagbyte.h>
#include <genos/bus/spi_driver.h>

#include <genos/container/glist.h>


namespace genos {

enum driver_mode{
TRANSACTION_WORK=0,
SEARCH_NEW
};

enum trans_return{
WORK=0,
FINISH,
ERROR
};

enum _status{
IS_FINISHED=0,
IS_RETURNED,
IS_CMD,
EMPTY,
CMD0,
CMD1,
CMD2,
CMD3
};

class transaction 
{
	public:
	flagbyte status;
	
virtual trans_return exec();	
virtual void destruct();	
};



//Универсальный автомат - драйвер транзакций.
class transaction_driver 
{
public:
transaction* current;
glist lst;
uint8_t mode;


transaction_driver() : mode(SEARCH_NEW) {};
void interrupt(){
	
	if (mode==SEARCH_NEW)
	{	
		if (lst.size() == 0) return;
		current = static_cast<transaction*> (lst.begin().ptr()); 
		mode = TRANSACTION_WORK;
	};

	if (mode==TRANSACTION_WORK){	
		if (current->exec() == FINISH)
		{
			//if (!current->status.sts(IS_RETURNED)) current->destruct();
			lst.__pop_back();
			mode = SEARCH_NEW;
		};
	};
};

};


};


#endif