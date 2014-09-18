

#ifndef GENOS_I_H
#define GENOS_I_H


#include <genos.h>

//#include <genos/container/gstring.h>
namespace genos { 


class b_istream{
public:
virtual byte read()=0;
virtual void read(byte* str, size_t sz);
virtual size_t available();
};

class istream : public b_istream{
public:
size_t read(char *buffer, size_t size) {
read(reinterpret_cast<byte*>(buffer), size);}
/*
gstring& read_string() 
{
gstring gs("kekeke");
return gs;
};*/


using b_istream::read;
};

};

#endif