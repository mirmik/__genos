#ifndef GENOS_QUANTUM_DYNAMIC
#define GENOS_QUANTUM_DYNAMIC

#include <genos/alloc.h>
#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>
#include <genos/debug/dump.h>
#include <genos/container/gvector.h>
#include <genos/io/printable.h>
#include <genos_obj.h>


namespace genos {

struct quant_qv{
byte* buffer;
size_t sz;

quant_qv (size_t _sz) : sz(_sz) {buffer = static_cast<byte*>(malloc(sz));};
void destruct() {free (buffer);};
};


class quantum_vector  {

protected:
size_t quant_size;
size_t data_size;
gvector quants;
public:
quantum_vector(size_t qs) : quant_size(qs), quants(sizeof(quant_qv)) {};

void add_quant_back () {quants.push_back(quant_qv(quant_size)); data_size += quant_size;
strmout << "add_quant_back" << endl;};


void del_all () 
{
	for (gvector::iterator it = quants.begin() ; it != quants.end(); it++)
	{
	quant_qv* qv = static_cast<quant_qv*>(*it);
	qv->destruct();
	};
	quants.del_all();
	data_size=0;
};

size_t size() {return quants.size();}
		
};

};


#endif