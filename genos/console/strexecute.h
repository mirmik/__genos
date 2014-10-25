

#ifndef GENOS_STREXECUTE_H
#define GENOS_STREXECUTE_H

//#include <string.h>
#include <genos/container/list.h>
#include <genos/stl_impl/algorithm>
#include <genos/io/printable.h>

namespace genos {	
	

	
class strexecute_record : public printable{
public:
	void(*func)(int,char**);
	char* name;
public:
	strexecute_record() : func(0), name(0) {};
	strexecute_record(char* _name, void(*_func)(int,char**)) : func(_func), name(_name) {};
	
	
	ostream& printTo(ostream& o)
	{
	o << "strexecreccord";
	return o;};
	
	//bool operator<(const strexecute_record b){return true;};
};
bool operator<(const strexecute_record& a, const strexecute_record& b);	
//bool exec_comp(const genos::strexecute_record a, const genos::strexecute_record b);

class strexecute : public printable{
public:
	list<strexecute_record> lst; 

public:
	strexecute() : lst() {};
	
	void add_command(char* str, void(*f)(int,char**)) 
		{lst.push_back(strexecute_record(str,f));
		strexecute_record val;
		//gstd::sort(lst.begin(),lst.end(),exec_comp);
		gstd::sort(lst.begin(),lst.end());
		};
		
	ostream& printTo(ostream& o)
	{
	for(list<strexecute_record>::iterator it= lst.begin();it!=lst.end();it++)
	o << it->name << endl;
	return o;};
};
	
	//namespace
	
		
};
	
struct argvc_t {
char ** argv;
int argc;
};

void split(char* temp, argvc_t &a);
void strexec(char* c);
int interpreter(int argv, const char* const* argc);


//bool operator<(const genos::strexecute_record a, const genos::strexecute_record b);
//bool operator>(const genos::strexecute_record a, const genos::strexecute_record b);
	
#endif