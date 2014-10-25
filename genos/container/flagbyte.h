

#ifndef GENOS_FLAGBYTE
#define GENOS_FLAGBYTE

#include <genos.h>
#include <genos/io/printable.h>

namespace genos{

class flagbyte : public printable{
byte b;
public:


flagbyte() : b(0) {};
inline void set(uint8_t s) {b|=(1<<s);};
inline void clr(uint8_t s) {b&=~(1<<s);};
inline bool sts(uint8_t s) {return (b & (1<<s));};

uint8_t lenmask(uint8_t b)
{
switch(b)
	{
	case 8: return 0b11111111;
	case 7: return 0b01111111;
	case 6: return 0b00111111;
	case 5: return 0b00011111;
	case 4: return 0b00001111;
	case 3: return 0b00000111;
	case 2: return 0b00000011;
	case 1: return 0b00000001;
	case 0: return 0b00000000;	
	};
}

uint8_t get_cntr(uint8_t a, uint8_t len) {return((b>>a) & lenmask(len));};
void set_cntr(uint8_t a, uint8_t len, uint8_t _b) {
uint8_t m = _b << a; 
uint8_t mask = lenmask(len) << a; 
b &= ~mask;
b |= m;
};

ostream& printTo(ostream& o) {o.printByteBin(b);};
};

};

#define SETB(b,s) {b|=(1<<s);};
#define CLRB(b,s) {b&=~(1<<s);};
#define STSB(b,s) (b & (1<<s))

#endif