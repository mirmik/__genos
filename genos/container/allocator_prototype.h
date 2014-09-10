

#ifndef GENOS_ALLOCATOR_PROTOTYPE
#define GENOS_ALLOCATOR_PROTOTYPE



#include <stdio.h>
#include <stdlib.h>
#include <genos.h>

namespace genos {


class allocator_prototype
{
public:
virtual ptr_t allocate (size_t sz);
virtual void deallocate (ptr_t p , size_t sz);

virtual size_t getFreeMemory(){};

virtual ptr_t rebind(){};
virtual void engage(){};
};

};

#endif