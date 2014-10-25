
#ifndef SUBST_SHED_H
#define SUBST_SHED_H

#include <genos.h>
#include "genos/subst/SubstMacro.h"
#include "genos/gcontext/stack_header.h"
#include "genos/subst/hard_stack.h"
#include "genos/allocator/allocator.h"
#include <genos/container/list.h>
#include <genos/subst/process.h>
//#include <genos_obj_subst.h>
//#include <genos_obj.h>


extern genos::process_list proclist;

namespace genos {

enum{
UNDER_CONSTRUCTED,
RUN	
	};

class subst_shed 
{
	public:
	//var
	//List L;
	uint8_t substed_stat;
	static int pid_gen;	
	process* now;	
	process* crt;
	size_t stsz;
	allocator* alloc;
	list<process>::iterator subst_it;
	
	//process_list proclist;
	//list<hard_stack> HStack;
	
	public:
	//constr
	subst_shed() : alloc(&malloc_allocator), stsz(200), subst_it(0) {};	
	//func
	process* create(void(*func)());
	 void change(process* h);
	 void change_process(process*,process*);
	 
		//local
	 int fork()__attribute__((naked));
	void substitution()__attribute__((noinline));
	 void copy_substitution();
	void kkk();
	void lll();
	void init() {
	now = proclist.initproc();
	subst_it=proclist.lst.begin();
	pid_gen=0;
	};
	
	void on() {substed_stat=1;};
	void off() {substed_stat=0;};
	int is_substed() {return substed_stat;};
	
	int generate_pid() {
	while (proclist.find(pid_gen) != 0) pid_gen++;
	return pid_gen;
	};
/*
	stack_header* add_stack(size_t n) {
	 stack_header* temp = HStack.push_back_spaced(n,hard_stack(n));
	 temp->format();
	 return(temp);
	 };
*/	 
	 //void init_mainstack(hard_stack* mainstack);
	 
process* add_new_process_with_hard_stack(size_t _stsz){

		hard_stack* hard = static_cast<hard_stack*> (alloc->allocate(sizeof(hard_stack) + _stsz));
		new (hard) hard_stack(_stsz);
		process* proc = proclist.lst.push_front(process(hard->begin()));
		proc->pid = generate_pid();
		proc->hard = hard;
		proc->hard->format();
		//strmout << (int)proc->hard;
		//strmout << (int)proc->hard->begin();
		//strmout << (int)proc->stack.start;
		//while(1);
		return proc;
	};	 
};
};

//#define INIT_SUBST(sz) Shed.now = Shed.add_stack(sz); setSP(Shed.now->begin());

#endif
