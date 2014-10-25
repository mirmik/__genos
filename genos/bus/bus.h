


#ifndef GENOS_BUS_H
#define GENOS_BUS_H

#include <genos/container/flagbyte.h>


namespace genos{
	
	class bus_cls{
	
	public:
	flagbyte bus_status; 
	
	enum{TAKED=0};
	
	virtual int takeup()
	{
	bus_status.set(TAKED);
	};
	virtual void takedown()
	{
	bus_status.clr(TAKED);	
	};
	
	
	};

};

#endif