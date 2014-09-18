

#ifndef GENOS_O_H
#define GENOS_O_H


#include "genos.h"
#include "genos/io/printable.h"
//#include "genos/byte_container/gstring.h"
namespace genos { 
class gstring;


class b_ostream{
public:
virtual size_t write(byte c) = 0;
virtual size_t write(const byte *buffer, size_t size);
//virtual size_t available();
};


#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2


class ostream  : public b_ostream
{
private:
int write_error;
size_t printNumber(unsigned long, byte);
size_t printFloat(double, byte);
protected:
public:
ostream() {}
size_t write(const char *str) {
if (str == NULL) return 0;
return write(reinterpret_cast<const byte*>(str), strlen(str));
}
size_t write(const char *buffer, size_t size) {
return write(reinterpret_cast<const byte*>(buffer), size);
}
//size_t print(const __FlashStringHelper *);
//size_t print(const String &);
size_t print(const char[]);
size_t print(char);
size_t print(unsigned char, int = DEC);
size_t print(int, int = DEC);
size_t print(unsigned int, int = DEC);
size_t print(long, int = DEC);
size_t print(unsigned long, int = DEC);
size_t print(double, int = 2);

size_t print(gstring& gs);
size_t println(gstring& gs);
//size_t print(const Printable&);
//size_t println(const __FlashStringHelper *);
//size_t println(const String &s);
size_t println(const char[]);
size_t println(char);
size_t println(unsigned char, int = DEC);
size_t println(int, int = DEC);
size_t println(unsigned int, int = DEC);
size_t println(long, int = DEC);
size_t println(unsigned long, int = DEC);
size_t println(double, int = 2);
//size_t println(const Printable&);
size_t println(void);

//ostream& operator<<(gstring& gs){write(reinterpret_cast<byte*>(gs.begin()),gs.string_size);
//};

/*
template<typename T, typename T2>
ostream& operator<<(std::pair<T,T2> val){
print(val.first,val.second);
return *this;
};*/



ostream& operator<<(printable& obj){
obj.printTo(*this);
return *this;
};
/*
template<typename T>
ostream& operator<<(T val){
print(val);
return *this;
};*/

ostream& operator<<(char val){
write(val);
return *this;
}

typedef ostream&(*func_o)(ostream&);
ostream& endl(ostream& o);

ostream& operator<<(func_o f){
return f(*this);
};
/*
ostream& operator<<(gstring& gs){
write(reinterpret_cast<byte*>(gs.begin()),gs.string_size);
return *this;
};*/


using b_ostream::write;
};


ostream& endl (ostream& o);

};




#endif