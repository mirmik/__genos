#ifndef TRANSACTION_ALGORITHM
#define TRANSACTION_ALGORITHM

#include <genos.h>
#include <genos/platform.h>

namespace genos {

template <typename QuantType, 
typename ContainerType, 
typename HardType>
void transaction_algorithm(
QuantType quant, 
ContainerType container, 
HardType obj)
	{
	if (obj->hard_ready() && container.empty()) {obj->hard_write(quant); return;}
	while(container.isFull()) DoNothing();
	ATOMIC();
	container.push_back(quant);
	DEATOMIC();
	return;
	};


};

#endif