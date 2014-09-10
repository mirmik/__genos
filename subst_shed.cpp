
#include "genos/sheduler/subst_shed.h"
#include "genos/debug/errserv.h"

namespace genos {

int thread::number=0;


	//Black magic
	void SubstShed::substitution () 
	{
		saveContext();
		now->sp=readSP();
		now=chg;
		setSP(now->sp);
		loadContext();
	};
	
	
	hard_stack* SubstShed::create(size_t sz,void(*func)())
	{
		hard_stack* old = now;
		chg = add_stack(sz);
		//L.add(chg);				
		
		chg->sp=chg->begin();		
		old->sp=readSP();
		
		now=chg;			//Хитрый мув ушами.
		setSP(now->sp);		//Смена контекста на самого себя.
		substitution(); 	//Приводит к образованию копии.
												
		if (now->status==UNDER_CONSTRUCTED) 
		{
			now->status=RUN;
			func();	
			sysErr(SUBSTSHED,this);
			while(1);
			
		}
		
		else
		{
			now->status=UNDER_CONSTRUCTED;
			hard_stack* temp=now;
			now=old;				
			setSP(now->sp);
			return temp;
		};	
						
	};

	void SubstShed::change(hard_stack* h)
	{	chg=h;
		substitution();		
	}
	/*
	void SubstShed::init_mainstack(hard_stack* mainstack)
	{
	uint8_t* src = (uint8_t*)RAMEND;
	uint8_t* dest =(uint8_t*) mainstack->begin();
	while(src!=(uint8_t*)stack_pointer()) {*dest = *src; dest--; src--;};
	//setSP((size_t)src);
	__malloc_heap_end=(char*)RAMEND;
	};*/

};