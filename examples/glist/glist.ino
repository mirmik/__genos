






#include <genos.h>
#include <genos_obj.h>
#include <genos/container/glist.h>
#include <genos/stl_impl/algorithm>

using namespace genos;

glist lst;

void print_op(void* op)
{
strmout.print((int)static_cast<float*>(op),HEX);
strmout.print('\t');
strmout.println(*static_cast<float*>(op));
};

void setup(){
//strmout.begin(9600);

char* v = static_cast<char*> (malloc(100));
for(int i = 0; i<100; i++) *(v+i)=0;
free(v);
strmout.println('1');
for_each(lst.begin(),lst.end(),print_op);
strmout.println('2');
lst.push_back<float>(1);
lst.pop_front();
for_each(lst.begin(),lst.end(),print_op);
strmout.println('3');
strmout.println();
lst.push_back<float>(28);
lst.pop_back();
lst.push_back<float>(11);
for_each(lst.begin(),lst.end(),print_op);
strmout.println('4');
lst.push_front<float>(15);
lst.push_back<float>(122);
for_each(lst.begin(),lst.end(),print_op);
strmout.println();
}

void loop(){};