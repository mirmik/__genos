

#include <genos/io/i.h>

namespace genos {

void b_istream::read(byte* str, size_t sz){
for(int i=0; i<sz; i++) *(str+i)=read();};




};