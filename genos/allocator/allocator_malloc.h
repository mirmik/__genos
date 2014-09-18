


#ifndef GENOS_EXTERN_ALLOC
#define GENOS_EXTERN_ALLOC

#include <genos/allocator/allocator.h>

namespace genos {

class allocator_malloc : public allocator {
public:
void* allocate (size_t sz);
void deallocate (void* p);
};

};
extern genos::allocator_malloc malloc_allocator;
#endif