

#include <genos/allocator/allocator_malloc.h>
#include <genos_obj.h>


namespace genos {



void* allocator_malloc::allocate (size_t sz) {
void* temp = malloc(sz);
if (temp == 0) sysErr(MALLOC_ERROR,this); else return temp;
};
void allocator_malloc::deallocate (void* p) {free(p);};























};