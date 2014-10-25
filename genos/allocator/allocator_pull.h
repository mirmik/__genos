


#ifndef GENOS_ALLOCATOR_PULL
#define GENOS_ALLOCATOR_PULL


#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>
#include <genos/container/gmonolist.h>

namespace genos {



class allocator_pull {
public:
const size_t sz;
//pullfreelist* first;
gmonolist freelist;
allocator* father;

public:
allocator_pull (size_t _sz) : sz(_sz), father(&malloc_allocator) {};

	void needmoreminerals()
	{engageblock(strategy());};

	void* allocate (size_t sz) {
	if (freelist.size()==0) needmoreminerals();//return 0;
	void* temp = freelist.begin().current;
	return temp;
	};
	
	/*
	void deallocate (void* p) {
	pullfreelist* temp = first;
	first = static_cast<pullfreelist*> (p);
	new(first) pullfreelist(temp);
	};*/
/*
*/
	void engageblock(size_t num)
	{void* newpull = father->allocate(num*sz);
	for(void* i=newpull; i < (newpull+sz*(num-1)); i+=sz) freelist.push_back_placed(i);
	//new(i) pullfreelist(i+sz);
	//new(newpull+sz*(num-1)) pullfreelist(first);
	//first = static_cast<pullfreelist*> (newpull);	
	};

/*void print () {
Serial.print((int)this, HEX);Serial.print('\t');Serial.print(sz);Serial.print('\t');Serial.print((int)freelist.head.next,HEX);Serial.print('\n');
pullfreelist* temp = first;
int i=0;
while (temp!=0) {i++; Serial.print(i);Serial.print('\t'); Serial.print((int)temp,HEX);Serial.print('\t');Serial.println((int)temp->next,HEX); temp=temp->next;};
};*/

size_t strategy()
{if (sz<=8) return 8;
if (sz<=32) return 4;
 return 2;};

};
};
#endif