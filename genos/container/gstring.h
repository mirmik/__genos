

#ifndef GENOS_GSTRING_H
#define GENOS_GSTRING_H


//class genos::ringbuffer;
#include <genos/container/dynamic_array.h>
#include <genos/io/printable.h>
#include <genos/stl_impl/algorithm>
#include <genos/function.h>

namespace genos {


class gstring : public dynamic_array, public printable {
	public:
	int string_size;
	
	public:	
	gstring() : string_size(0), dynamic_array() {};
	
	~gstring(){};
	//for destruct() -> dynamic_array method.	
	
	gstring(char* str) : dynamic_array() 
	{
	size_t len = strlen(str);
	reserve(string_size=len);
	memcpy(data,str,len);
	};
	
	/*
	gstring(const gstring& gstr){
	reserve(gstr.string_size);
	string_size=gstr.string_size;
	memcpy(data,gstr.data,string_size);
	};*/
	
	byte& operator[](int i) {
	return *static_cast<byte*>(data+i);}
	
	gstring& operator+ (char c) { 
	if (string_size>=data_size)	reserve(string_size + 8); 
	*(static_cast<byte*>(data) + string_size) = c;
	string_size++;
	return *this;}; 
	
	gstring& operator+ (const char* str) {
	size_t len = strlen(str);
	reserve(string_size+=len);	
	memcpy(end() - len,str,len);	
	return *this;}; 
	
	void guaranty(int n){
	while (n > data_size) moresize();	
	if (string_size < n) string_size = n;	
	};
	
	void mb_downsize()
	{
	int temp = data_size - string_size;
	if (temp > 8) reserve(string_size);
	};
	
	gstring& operator= (const char* str) {
	size_t len = strlen(str);
	reserve(string_size=len);
	memcpy(data,str,len);
	return *this;}; 
	
	size_t size() {return string_size;}
		
	char* c_str(){
	guaranty(string_size+1);
	operator[](string_size-1)=0;
	return static_cast<char*>(data);};
	
	void moresize(){reserve(data_size+8);}; // STRATEGY
	
/*	class rider : public b_ostream
		{
		gstring* gs;
		size_t pos;
		
		public:
		rider(gstring& _gs) : gs(&_gs), pos(0) {};
		rider(gstring& _gs, size_t _pos) : gs(&_gs), pos(_pos) {};
		
		void set(size_t _pos){pos=_pos; gs->guaranty(pos);};
		size_t write(byte b) {
		gs->guaranty(gs->string_size + 1); 
		gs->operator[](pos++)=b; 
		return 1;};
		
		size_t write(const byte *buffer, size_t size)
		{
		gs->guaranty(gs->string_size + size); 
		memcpy(&gs->operator[](pos),buffer,size);
		};
		};
*/	
	class cursor : public b_ostream
		{
		gstring* gs;
		size_t pos;
		
		public:
		cursor(gstring& _gs) : gs(&_gs), pos(0) {};
		cursor(gstring& _gs, size_t _pos) : gs(&_gs), pos(_pos) {};
		
		void set(size_t _pos){pos=_pos; gs->guaranty(pos);};
		size_t write(byte b) {
		gs->guaranty(gs->string_size + 1); 
		memmove(&gs->operator[](pos)+1, &gs->operator[](pos), gs->string_size - pos - 1); 
		gs->operator[](pos++)=b; 
		return 1;};
		
		size_t write(const byte *buffer, size_t size)
		{
		gs->guaranty(gs->string_size + size); 
		memmove(&gs->operator[](pos) + size, &gs->operator[](pos), gs->string_size - pos - size); 
		memcpy(&gs->operator[](pos),buffer,size);
		};
		
		void del()
		{
		memmove(&gs->operator[](pos), &gs->operator[](pos)+1, gs->string_size - pos - 1); 
		gs->string_size -= 1;
		gs->mb_downsize();
		};
		
		void del(int size)
		{
		memmove(&gs->operator[](pos), &gs->operator[](pos)+size, gs->string_size - pos - size); 
		gs->string_size -= size;
		gs->mb_downsize();
		};
		
		void bs()
		{
		if (pos - 1 < 0) return;
		else pos -= 1; 
		del(1);
		};
		
		cursor operator++(int) { cursor i = *this; pos=pos+1; return i; }
		cursor operator++() { pos=pos+1; return *this; }
		cursor operator--(int) { cursor i = *this; if (pos!=0) pos=pos-1; return i; }
		cursor operator--() { if (pos!=0) pos=pos-1; return *this; }
	
		
		using b_ostream::write;
		};
	
		ostream& printTo(ostream& o)
		{
		printChar probj(&o);
		gstd::for_each(begin(),end(),probj);
		};
	
	void clean(){
	string_size=0;
	data_size=0;
	destruct();
	data=0;
	};
	
	char* begin() {return static_cast<char*>(data);};
	char* end() {return static_cast<char*>(data) + string_size;};

	cursor begin_cursor() {return cursor(*this);};
	cursor end_cursor() {return cursor(*this,string_size);};
	
};

};














#endif