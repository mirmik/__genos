
#ifndef SUBST_SHED_H
#define SUBST_SHED_H

#include <genos.h>
#include <genos/container/glist.h>
#include "genos/sheduler/SubstMacro.h"
#include "genos/container/hard_stack.h"


namespace genos {

enum{
UNDER_CONSTRUCTED,
RUN	
	};

class thread 
{	
	public:
	static int number;
	int num;
	int status;
	size_t sp;
	
	thread() : status(RUN) {num=number++;};  
};



class SubstShed 
{
	public:
	//var
	//List L;
	hard_stack* now;	
	hard_stack* chg;
	genos::glist HStack;
	
	public:
	//constr
	SubstShed() : HStack() {
	//mainstack = add_stack(300);
	};	
	//func
	 hard_stack* create(size_t sz,void(*func)());
	 //void init(genos::hard_stack* stack, size_t sz,void(*func)());
	 void change(hard_stack* h);
	 void substitution();
	 
	 hard_stack* add_stack(size_t n) {
	 hard_stack* temp = HStack.push_back_spaced(n,genos::hard_stack(n));
	 //dpr_inthex(temp);
	 temp->format();
	 return(temp);
	 };
	 
	 void init_mainstack(hard_stack* mainstack);
	 	 
};
};

#endif
