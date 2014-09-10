

#include <genos/container/allocator_malloc.h>


namespace genos {



ptr_t allocator_malloc::allocate (size_t sz) {return malloc(sz);};
void allocator_malloc::deallocate (ptr_t p , size_t sz) {free(p);};

size_t getFreeMemory(){};






















};