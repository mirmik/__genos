







#ifndef GENOS_EXTERN_ALLOC
#define GENOS_EXTERN_ALLOC




#include <genos/alloc.h>
#include <genos/container/allocator_prototype.h>



namespace genos {


class allocator_nullstd : public allocator_prototype {
protected:
allocator_prototype* father;

struct freelist {
size_t sz;
freelist* next;
freelist(size_t _sz) : sz(_sz), next(0) {};
};


public:
allocator_nullstd()  {};
void* heap;
size_t heap_size;
void* allocate (size_t sz);
void deallocate (void* p , size_t sz);

//void engage(ptr_t _buffer, );

};

};

#endif
