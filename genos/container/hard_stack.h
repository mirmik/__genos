#ifndef HARD_STACK_H
#define HARD_STACK_H

#include <genos.h>
#include <genos/platform.h>
#include "stdio.h"
#include "string.h"

namespace genos {



class hard_stack{
public:


enum{
UNDER_CONSTRUCTED=0,
RUN	
	};

size_t stack_size;
int status;
size_t sp;

inline void* outop() {return(static_cast<void*>(this + 1));}

hard_stack(size_t n) : stack_size(n-sizeof(hard_stack)) {};

size_t roof() {size_t i=0; while (*static_cast<unsigned char*>(outop()+i) == 0xAB) i++; return i;};
void format() {memset(outop(), 0xAB, stack_size);};

size_t size() {return (reinterpret_cast<size_t>(outop()) + stack_size-1 - stack_pointer());};
size_t begin() {return reinterpret_cast<size_t>(outop()+stack_size-1);};


bool isActive() {return ((stack_pointer()>=(size_t)outop()) && (stack_pointer()<=(size_t)outop()+stack_size-1));};
};
};
#endif