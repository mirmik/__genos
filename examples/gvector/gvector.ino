

#include <genos.h>
#include <genos/container/gvector.h>
#include <genos/algorithm.h>

using namespace genos;

gvector lst(sizeof(float));

void print_op(void* op)
{
Serial.print((int)static_cast<float*>(op),HEX);
Serial.print('\t');
Serial.println(*static_cast<float*>(op));
};

void setup(){
Serial.begin(9600);

char* v = static_cast<char*> (malloc(100));
for(int i = 0; i<100; i++) *(v+i)=0;
free(v);

lst.push_back<float>(1);
for_each(lst.begin(),lst.end(),print_op);
Serial.println();
lst.push_back<float>(28);
for_each(lst.begin(),lst.end(),print_op);
Serial.println();
lst.push_back<float>(11);
for_each(lst.begin(),lst.end(),print_op);
Serial.println();
lst.push_back<float>(15);
lst.push_back<float>(122);
for_each(lst.begin(),lst.end(),print_op);
Serial.println();
}

void loop(){};