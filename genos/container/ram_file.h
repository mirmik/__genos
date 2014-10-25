#ifndef GENOS_RAM_FILE_H
#define GENOS_RAM_FILE_H


#include <genos.h>
#include <genos/container/quantum_vector.h>
#include <genos/io/printable.h>

namespace genos{

class ram_file : public quantum_vector , public printable{
public:
size_t file_size;

//byte& operator[](size_t sz) {return (sz);};
ram_file(size_t sz) : quantum_vector(sz), file_size(0) {};


	class rider {
		public:
		ram_file* rf;
		size_t m;
		size_t d;
		byte* current;
		
		rider(ram_file* _rf) : rf(_rf), current(0), m(0), d(0) {set();};
		rider(ram_file* _rf, size_t i) : rf(_rf)  {seek(i);};
		
	int seek(size_t i) {
	m = i % rf->quant_size;
	d = i / rf->quant_size; 
	set();
	};

	rider operator++(int) { rider i = *this; m++; if (m==rf->quant_size) {m=0;d++;}; set(); return i; }
	rider operator++() {  m++; if (m==rf->quant_size) {m=0;d++;}; set();  return *this; }
	
	bool operator!= (const rider& b) {return current != b.current;};
	byte& operator*() {return *current;};
	
	size_t pos() {return (m + d * rf->quant_size);}
	
	void write(byte c) {if (pos()==rf->file_size) rf->resize(rf->file_size+1); *current=c; operator++();};
	
	void set(){
	current = static_cast<quant_qv*>(rf->quants[d])->buffer + m;	
	
	};
	
	};

	void rewrite_null()
	{
	del_all();
	file_size=0;
	};
	 
	void resize(size_t nsz) {
	size_t d = quants.size();
	size_t nd = nsz / quant_size + 1;
	size_t needbuf = nd - d;
	while (needbuf--) add_quant_back();
	file_size = nsz;
	};
	
	ostream& printTo(ostream& o){
	for (rider rid = begin(); rid != end(); rid++)
	{o << *rid;};
	return o;
	};
	
	rider begin() {return rider(this , 0);};
	rider end() {return rider(this, file_size);};
	
};

};


#endif