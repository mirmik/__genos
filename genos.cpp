


#include <genos.h>
#include <genos/allocator/allocator_malloc.h>
#include <genos/console/strexecute.h>
#include <genos/container/hard_stack.h>

genos::allocator_malloc malloc_allocator;
genos::strexecute strExec;
size_t stack_pointer() {return(SP);};
genos::hard_stack* mainstack;