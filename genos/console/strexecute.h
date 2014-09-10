

#ifndef GENOS_STREXECUTE_H
#define GENOS_STREXECUTE_H

#include <genos/container/glist.h>

namespace genos {	
	

	
class strexecute_record{
public:
	void(*func)(int,char**);
	char* name;
public:
	strexecute_record(char* _name, void(*_func)(int,char**)) : func(_func), name(_name) {};
};
	
	
class strexecute{
public:
	glist list; 

public:
	strexecute() : list(sizeof(strexecute_record)) {};
	
	void add_command(char* str, void(*f)(int,char**)) 
		{list.push_back(strexecute_record(str,f));};
};
	
};	//namespace
	
	
struct argvc_t {
char ** argv;
int argc;
};
	
	
void split(char* temp, argvc_t &a);
void strexecute(char* c);
int interpreter(int argv, const char* const* argc);


	extern genos::strexecute strExec;	
//#define add_utility(_name, _func) push_back( genos::strexecute_record, _name, (void(*)(void)) _func);
	
#endif