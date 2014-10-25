#ifndef GENOS_RINGBUFFER_H
#define GENOS_RINGBUFFER_H

#include <genos.h>
#include "genos/allocator/allocator.h"
#include "genos/allocator/allocator_malloc.h"
#include "genos/function.h"
#include "genos/stl_impl/algorithm"
#include "genos/io/printable.h"

namespace genos {

//class ostream;
class ringbuffer : public printable //public b_istream, b_ostream
{
public:
size_t tail;
size_t size;
size_t buffer_size;
byte* buffer;

//ringbuffer (byte* _buffer,size_t _sz) : tail(0), buffer_size(_sz), buffer(_buffer), size(0) {};
//ringbuffer (allocator* alloc, size_t sz) : tail(0), size(0) {engage(alloc,sz);};
ringbuffer () :  tail(0), size(0), buffer_size(0), buffer(0) {};
ringbuffer (size_t sz) :  tail(0), size(0), buffer_size(0), buffer(0) {engage(&malloc_allocator,sz);};

byte pop_back();
byte pop_front();
size_t push_back(byte c);
size_t push_front(byte c);


	class iterator {
				public:
					byte* current;
					byte* buffer_end;
					byte* buffer_start;
				public:
					iterator(byte* p, byte* _buffer_end, byte* _buffer_start) : 
					current(p), buffer_end(_buffer_end) ,
					buffer_start(_buffer_start){};		
					
					iterator operator++(int) { iterator i = *this; current++;
					if (current >= buffer_end) current=buffer_start ;
					return i; }
					
					iterator operator++() { current++;
					if (current >= buffer_end) current=buffer_start ;
					return *this; }
					
					//iterator operator++() { current=current+sz; return *this; }
					bool operator!= (const iterator& b) {return current != b.current;};
					char operator*() {return (*current);};
		};


void to_string(char* str);

void clean() {tail=0;size=0;};
size_t available();
size_t available_write();

iterator begin() {return iterator(buffer+tail, buffer+buffer_size, buffer);};
iterator end() {return iterator(buffer + ((tail+size)%buffer_size), buffer+buffer_size, buffer);};

ostream& printTo(ostream& o) {
		printChar probj(&o);
		gstd::for_each(begin(),end(),probj);
}

void engage(allocator* alloc, size_t sz);
};

};
#endif