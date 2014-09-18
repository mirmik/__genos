

#ifndef GENOS_ALLOCATOR
#define GENOS_ALLOCATOR



#include <stdio.h>
#include <stdlib.h>
#include <genos.h>

namespace genos {


class allocator
{
public:
virtual ptr_t allocate (size_t sz);
virtual void deallocate (ptr_t p);

virtual size_t getFreeMemory(){};

virtual ptr_t rebind(){};
virtual void engage(){};
};

};

#endif