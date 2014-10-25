




#ifndef GENOS_MANUAL_GSTRING_H
#define GENOS_MANUAL_GSTRING_H

#include <genos/container/dynamic_array.h>
#include <genos/io/printable.h>
#include <genos/stl_impl/algorithm>
#include <genos/function.h>

namespace genos {

class manual_gstring : public dynamic_array, public printable {
	public:
	size_t string_size;
	
	public:	
	manual_gstring() : string_size(0), dynamic_array() {};
	
	~manual_gstring(){};
	
	manual_gstring(char* str) : dynamic_array() 
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
	
	manual_gstring& operator << (char c) { 
	if (string_size < data_size) *(static_cast<byte*>(data) + string_size) = c;
	string_size++;
	return *this;}; 
	/*
	gstring& operator+ (const char* str) {
	size_t len = strlen(str);
	reserve(string_size+=len);	
	memcpy(end() - len,str,len);	
	return *this;}; 
	*/
	manual_gstring& operator= (const char* str) {
	size_t len = strlen(str);
	reserve(string_size=len);
	memcpy(data,str,len);
	return *this;}; 
	
	byte operator[](int i) {return *static_cast<byte*>(data+i);}
	
	size_t size() {return string_size;}
	
	char* c_str(){
	reserve(string_size+1);
	*((static_cast<char*>(data)+string_size))=0;
	return static_cast<char*>(data);};
	
	
		ostream& printTo(ostream& o)
		{
		printChar probj(&o);
		gstd::for_each(begin(),end(),probj);
		};
	
	
	byte* begin() {return static_cast<byte*>(data);};
	byte* end() {return static_cast<byte*>(data) + string_size;};

	
};

};














#endif