

#ifndef DYNAMIC_BUFFER
#define DYNAMIC_BUFFER

#include <genos/container/dynamic_obj.h>
#include <genos/alloc.h>
#include "inttypes.h"
#include "stdio.h" //for size_t
//#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>

#include <genos/alloc.h>

namespace genos {

class dynamic_array{
		protected:
		void* data;
		size_t data_size;
		allocator* alloc;
		
		dynamic_array() : data(0), data_size(0), alloc(&malloc_allocator)  {};
		
		dynamic_array(allocator* _alloc) : data(0), data_size(0), alloc(_alloc)  {};
		
		public:
		void reserve(size_t n);    //need more memory!!!
		




~dynamic_array() {alloc->deallocate(data);
Serial.println("DESTRUCT");};



};	//class
	
};	//namespace
	
	
#endif