#ifndef GENOS_RINGBUFFER_H
#define GENOS_RINGBUFFER_H

#include <genos.h>
//#include "genos/io/bytequeue.h"
#include "genos/allocator/allocator.h"
#include "genos/allocator/allocator_malloc.h"
#include "genos/byte_container/byte_dequeue.h"

//#include <genos/io/i.h>
//#include <genos/io/o.h>

namespace genos {

//class ostream;

class ringbuffer : public byte_dequeue //public b_istream, b_ostream
{
public:
size_t tail;
size_t size;
size_t buffer_size;
byte* buffer;

ringbuffer (byte* _buffer,size_t _sz) : tail(0), buffer_size(_sz), buffer(_buffer), size(0) {};
ringbuffer (size_t sz) : tail(0), size(0) {engage(&malloc_allocator,sz);};

byte pop_back();
byte pop_front();
size_t push_back(byte c);
size_t push_front(byte c);

void to_string(char* str);

void clean() {tail=0;size=0;};
size_t available();

void engage(allocator* alloc, size_t sz);
};

};
#endif