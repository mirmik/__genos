

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
		int data_size;
		allocator* alloc;
		
		dynamic_array() : data(0), data_size(0), alloc(&malloc_allocator)  {};
		
		dynamic_array(allocator* _alloc) : data(0), data_size(0), alloc(_alloc)  {};
		
		public:
		void reserve(size_t n);    //need more memory!!!
		
		//void upsize(size_t n){
		//if (data_size < n) reserve(n);
	//}
	
//	void downsize(size_t n){
//		if (data_size > n) reserve(n);
//	}

	

//~dynamic_array() {alloc->deallocate(data);};
		void destruct(){alloc->deallocate(data);};


};	//class
	
};	//namespace
	
	
#endif