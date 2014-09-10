#ifndef GENOS_QUANT
#define GENOS_QUANT

#include <genos/container/dynamic_array.h>

namespace genos {

class quant{
size_t quant_size;
char* buffer;

/*
	class iterator
	{
	char* buffer;
	iterator() : num(0) {};
	iterator(size_t _num) : num(_num) {};
	iterator operator++(int) { iterator i = *this; num++; return i; }
	iterator operator++() { num++; return *this; }
	char* operator*() {return (buffer+num);};
	};*/

	char* begin() {return buffer;};
	char* end() {return buffer+quant_size;};
	
//	void* outop() {return(static_cast<void*>(this + 1));};
	
	protected:
	char* r;
	char* w;
	
};

};

#endif