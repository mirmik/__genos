


#include <genos/byte_container/ringbuffer.h>



namespace genos {




byte ringbuffer::pop_front(){
char c=buffer[(tail+size)%buffer_size];
//tail%=buffer_size;
size--;
return c;
};

byte ringbuffer::pop_back(){
char c=buffer[tail++];
tail%=buffer_size;
size--;
return c;
};

size_t ringbuffer::push_back(byte c){
if (size>=buffer_size) return -1;
tail=(tail - 1 +buffer_size) % buffer_size;
buffer[tail]=c;
size++;
return 1;
};

size_t ringbuffer::push_front(byte c){
if (size>=buffer_size) return -1;
buffer[(tail+size) % buffer_size]=c;
size++;
return 1;
};


size_t ringbuffer::available(){
return size;};

void ringbuffer::engage (allocator* alloc, size_t sz)
{
buffer = reinterpret_cast<byte*> (alloc->allocate(sz));
buffer_size=sz;
};

void ringbuffer::to_string(char* str)
{size_t a=available();
for(int i=0;i<a+1;i++) *(str+i)=(char)pop_back();
*(str+a)=0;
};

};