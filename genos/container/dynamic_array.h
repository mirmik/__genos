

#ifndef DYNAMIC_BUFFER
#define DYNAMIC_BUFFER

#include <genos/container/dynamic_obj.h>
#include <genos/alloc.h>
#include "inttypes.h"
#include "stdio.h" //for size_t
#include <genos/container/allocator_prototype.h>
#include <genos/container/allocator_malloc.h>

#include <genos/alloc.h>

namespace genos {

class dynamic_array{
		protected:
		void* data;
		size_t data_size;
		allocator_prototype* alloc;
		
		dynamic_array() : data(0), data_size(0), alloc(&malloc_allocator)  {};
		
		dynamic_array(allocator_prototype* _alloc) : data(0), data_size(0), alloc(_alloc)  {};
		
		public:
		void reserve(size_t n);    //need more memory!!!
		








};	//class
	
};	//namespace
	
	
#endif