#ifndef GENOS_BYTE_DEQUEUE_H
#define GENOS_BYTE_DEQUEUE_H

#include <genos.h>

namespace genos {

//class ostream;

class byte_dequeue 
{
public:
virtual byte pop_front();
virtual byte pop_back();
virtual size_t push_front(byte c);
virtual size_t push_back(byte c);
virtual size_t available();
virtual void clean();

//void engage(allocator* alloc, size_t sz);
};

};
#endif