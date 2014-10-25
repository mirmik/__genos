

#ifndef GENOS_O_H
#define GENOS_O_H


//#include "genos.h"
#include "genos/io/printable.h"
#include "stdio.h"
#include "genos/platform.h"
//#include <genos/io/nullstrm.h>
//#include "genos/container/gstring.h"
namespace genos { 
class gstring;

typedef size_t inthex;

class b_ostream{
public:
virtual size_t write(byte c) = 0;
//virtual size_t write(char c){write((byte)c);};
virtual size_t write(const byte *buffer, size_t size);


size_t write(const char *buffer, size_t size){write((const byte*)buffer, size);};
//virtual size_t available();
size_t write(const char *str) {
if (str == NULL) return 0;
return write(reinterpret_cast<const byte*>(str), strlen(str));
}
//size_t write(const char *buffer, size_t size) {
//return write(reinterpret_cast<const byte*>(buffer), size);
//}
};


#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2


class ostream  : public b_ostream
{
private:
b_ostream* strm;
//int write_error;
size_t printNumber(unsigned long, byte);
size_t printFloat(double, byte);
protected:
public:
uint8_t NumPr;

virtual size_t write(byte c) {strm->write(c);};

ostream(b_ostream* _strm) : strm(_strm), NumPr(10) {}
//ostream() : strm() {}

void connect (b_ostream* _strm) {strm=_strm;}


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

size_t printByte(byte c)
{
print(c>>4,HEX);
print(c%16,HEX);
};


size_t printByteBin(byte c)
{
for (int i=7; i >= 0; i--)
write((c & (1 << i)) ? '1' : '0');
};

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

typedef ostream&(*func_o)(ostream&);


ostream& endl(ostream& o);
ostream& operator<<(func_o f){return f(*this);};

ostream& operator<<(printable& obj){obj.printTo(*this); return *this;};
ostream& operator<<(char val){write(val);return *this;};
//ostream& operator<<(byte val){write(val);return *this;};
ostream& operator<<(uint8_t val){printNumber(val, NumPr);return *this;};
ostream& operator<<(int val){printNumber(val, NumPr);return *this;};
ostream& operator<<(unsigned int val){printNumber(val, NumPr);return *this;};
ostream& operator<<(long long int val){printNumber(val, NumPr);return *this;};

ostream& operator<<(long val){printNumber(val, NumPr);return *this;};
ostream& operator<<(unsigned long val){printNumber(val, NumPr);return *this;};
ostream& operator<<(double val){printFloat(val, 2);return *this;};
ostream& operator<<(float val){printFloat(val, 2);return *this;};

ostream& operator<<(const char* val){write(val);return *this;};


//ostream& operator<<(inthex val){print(val,HEX);return *this;};


using b_ostream::write;
};


ostream& endl (ostream& o);
ostream& hex (ostream& o);

};




#endif