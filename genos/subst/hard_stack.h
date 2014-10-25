#ifndef HARD_STACK_H
#define HARD_STACK_H

#include <genos.h>
#include <genos/platform.h>
#include "stdio.h"
#include "string.h"

namespace genos {



class hard_stack{
public:
/*
enum{
UNDER_CONSTRUCTED=0,
RUN	
	};*/
	size_t stack_size;
	hard_stack(size_t _sz) : stack_size(_sz) {};

	void format() {memset(outop(), 0xAB, stack_size);};
	void* begin() {return (outop()+stack_size-1);};

	//INFO
	size_t roof() {size_t i=0; while (*static_cast<unsigned char*>(outop()+i) == 0xAB) i++; return i;};

	inline void* outop() {return(static_cast<void*>(this + 1));}
	};
};
#endif