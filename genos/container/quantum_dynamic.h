#ifndef GENOS_QUANTUM_DYNAMIC
#define GENOS_QUANTUM_DYNAMIC

#include <genos/alloc.h>
#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>
#include <genos/container/dynamic_obj.h>
#include <genos/io/printable.h>
#include <genos/debug/dump.h>
#include <genos/container/glist.h>

namespace genos {

class quantum_dynamic {

protected:
size_t quant_size;
glist quants;
public:
quantum_dynamic(size_t _quant) : quant_size(_quant) {};

void add_quant_front () {quants._push_front(quant_size);};
void add_quant_back () {quants._push_back(quant_size);};

void remove_quant_front () {quants.pop_front();};
void remove_quant_back () {quants.pop_back();};
		
size_t size() {return quants.size();}
		
};

};


#endif