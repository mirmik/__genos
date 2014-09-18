

#ifndef GENOS_GSTRING_H
#define GENOS_GSTRING_H


#include <genos/container/dynamic_array.h>
//class genos::ringbuffer;
//#include <genos/io/ringbuffer.h>

namespace genos {


class gstring : public dynamic_array {
	public:
	size_t string_size;
	
	public:	
	gstring() : string_size(0), dynamic_array() {
	Serial.println("CONSTRUCT2");};
	
	gstring(char* str) : string_size(0), dynamic_array() 
	{
	Serial.println("CONSTRUCT");
	size_t len = strlen(str);
	reserve(string_size=len);
	memcpy(data,str,len);
	};
	
	gstring(const gstring& gstr){
	Serial.println("CONSTRUCT3");
	reserve(gstr.string_size);
	string_size=gstr.string_size;
	memcpy(data,gstr.data,string_size);
	};
	
	gstring& operator+ (char c) { 
	reserve(string_size += 1); 
	*(end() - 1) = c;
	return *this;}; 
	
	gstring& operator+ (const char* str) {
	size_t len = strlen(str);
	reserve(string_size+=len);	
	memcpy(end() - len,str,len);	
	return *this;}; 
	
	gstring& operator= (const char* str) {
	size_t len = strlen(str);
	reserve(string_size=len);
	memcpy(data,str,len);
	return *this;}; 
	
	//gstring& operator= (gstring& gstr) {
	//if (&gstr!=this)	
	//return *this;}; 
	
	char* c_str(){
	reserve(string_size+1);
	*((static_cast<char*>(data)+string_size))=0;
	return static_cast<char*>(data);};
	
	char* begin() {return static_cast<char*>(data);};
	char* end() {return static_cast<char*>(data) + string_size;};

// LOCAL

/*
	void from_ringbuffer(ringbuffer& rb)
	{
	size_t temp=rb.available();
	reserve(temp);
	for (size_t i=0;i<temp;i++) *((byte*)data+i)=rb.read();
	string_size=temp;
	};
	*/
	
};

};














#endif