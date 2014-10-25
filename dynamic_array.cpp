	
	
	
#include <genos/container/dynamic_array.h>
#include "stdio.h"
#include "string.h"
	
namespace genos {
	
	//	allocator* alloc;
	
	
	void dynamic_array::reserve(size_t new_size){
		if (new_size == data_size) return;
		
		void* old_ptr = data;
		size_t old_size = data_size;

		data_size = new_size;
		data =  alloc->allocate(new_size);
			
		if (old_ptr!=0) {
		memcpy(data, old_ptr, old_size > new_size ? new_size : old_size);	
		alloc->deallocate (old_ptr); };
	}
	
	
	
	
	
	
	};