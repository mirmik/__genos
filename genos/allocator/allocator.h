

#ifndef GENOS_ALLOCATOR
#define GENOS_ALLOCATOR



#include <stdio.h>
#include <stdlib.h>

namespace genos {


class allocator
{
public:
virtual void* allocate (size_t sz);
virtual void deallocate (void* p);

virtual size_t getFreeMemory(){};

virtual void* rebind(){};
virtual void engage(){};



};


};


void* operator new(size_t sz, genos::allocator* a);
void* operator new(size_t sz, genos::allocator* a, size_t space);
void operator delete(void* p, genos::allocator* a);

#endif