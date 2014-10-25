#ifndef GENOS_QUANTUM_BUFFER
#define GENOS_QUANTUM_BUFFER

#include <genos/alloc.h>
#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>
#include <genos/container/quantum_dynamic.h>
#include <genos/io/printable.h>
#include <genos/debug/dump.h>
#include <genos/container/glist.h>

namespace genos {



class quantumbuffer : public printable, public quantum_dynamic {
protected:
byte* tail_buffer;
byte* head_buffer;
size_t tail;
size_t head;
size_t size;
size_t maxsize;

public:
quantumbuffer(size_t sz) : quantum_dynamic(sz),
tail_buffer(0), head_buffer(0), tail(0), head(0), size(0) ,maxsize(0) {};

size_t available() {return size;};
void clean() {restart();};

void push_back(byte c);
byte pop_front();

void restart() {
quants.del_all();
tail_buffer=0;
head_buffer=0;
tail=0;
head=0;
size=0;};

ostream& printTo (ostream& o) 
		{int i =0;
		for (glist::iterator it = quants.begin() ; it != quants.end(); it++)
			{i++;
			o << "QUANT " << i << " DUMP:" << endl;
			dump_to_ostream(o,it.ptr(),quant_size);	
			};
			
		o << "TAIL :" << tail << endl;
		o << "TAILB:"; o.print((int)tail_buffer,HEX); o << endl;
		o << "HEAD :" << head << endl;
		o << "HEADB:"; o.print((int)head_buffer,HEX); o << endl;
		};
	
int isFull(){return 0;};
int empty(){if (size==0) return 1; else return 0; };

};



};





#endif