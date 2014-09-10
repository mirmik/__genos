




#ifndef GENOS
#define GENOS

#include "stdlib.h"
#include "genos/debug/debug_print.h"

#ifdef ARDUINO
size_t stack_pointer();
#endif

#include <genos/stl_impl/utility.h>
#include <genos/container/hard_stack.h>


extern genos::hard_stack* mainstack;
namespace genos{
typedef void* ptr_t;
void printaddr(void*);



template <typename T>
void printexec (void* obj){
	static_cast<T*>(obj)->print();
};
};

//#define GENOS_ERRSERV 
//to activate errserver.
//#include  <genos/debug/errserv.h>
// platform functions.
#include  <genos/platform.h>



#endif


