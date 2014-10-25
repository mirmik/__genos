
#include "genos/subst/subst_shed.h"
#include "genos/gcontext/gcontext.h"
#include "genos_obj_subst.h"
#include "genos/debug/errserv.h"
#include "genos/platform/atomic.h"
#include <genos/debug/dump.h>
#include <genos/debug/debug_print.h>
#include <avr/cpufunc.h>

extern int main();
namespace genos {
/*
 void subst_shed::substitution () 
	{
		saveContext();
		//save_state((void*)&(now->state));
		//cli();
		now->stack.sp=getSP();
		now=chg;
		setSP(now->stack.sp);
		//load_state((void*)&(now->state));
		loadContext();
	};

	
	void subst_shed::kkk(){
		chg = add_new_process_with_hard_stack(subst.stsz);
		chg->status=process::CONSTRUCT1;
		
		//chg->stack.sp=chg->stack.start;
		old->stack.copy_to_stack(chg->stack);
		return;
		};
	
 int  subst_shed::fork()
	{	
		ATOMIC();
		old=now;
		old->stack.sp=getSP();
		kkk();


		now=chg;			//Хитрый мув ушами.
		setSP(chg->stack.sp);		//Смена контекста на самого себя.
		substitution(); 	//Приводит к образованию копии.
		
		if (now->status==genos::process::CONSTRUCT2) 
		{	
			//debug_printhex_int16(SP);
			//while(1);
			now->status=genos::process::RUN;
			DEATOMIC();
			//debug_print("deb2");
			return 0;
			
		}
		
		else //CONSTRUCT1
		{
			now->status=genos::process::CONSTRUCT2;
			int pid=now->pid;
			
			now=old;					//restore parent		
			setSP(subst.now->stack.sp);
			DEATOMIC();
			return pid;
		};	
						
	};
	*/
	
	procstate ccc;
	
	void subst_shed::kkk(){
	
		crt = add_new_process_with_hard_stack(subst.stsz);		
		crt->status = genos::process::CONSTRUCT1;	
	};
	
	void subst_shed::lll(){now->cntxt.stack.copy_to_stack(crt->cntxt.stack);
		crt->cntxt.state.state.sp = (size_t)crt->cntxt.stack.sp;}
	
	 int  subst_shed::fork()
	{	
		ATOMIC();
		
		
		/*procstate_operate = &(ccc.state);
		save_procstate();
		strmout << proclist.find(0)->cntxt.state << genos::endl;
		strmout << proclist.find(1)->cntxt.state << genos::endl; 
		sei();
		delay(1000);
		cli();
		strmout << ccc << genos::endl; 
		sei();
		delay(1000);
		cli();*/
		
		kkk();
		
		procstate_operate = &(crt->cntxt.state.state);
		save_procstate();
		
		if (now->status==genos::process::CONSTRUCT1) 
		{	
			now->status=genos::process::RUN;
			DEATOMIC();
			return 0;
		}
		
		else //CONSTRUCT1
		{
		now->cntxt.stack.sp = getSP();
		crt->status=genos::process::CONSTRUCT1;
		lll();
		DEATOMIC();
		
			
			return crt->pid;
		};	
						
	};
	
	
	
	
	void subst_shed::change(process* chg)
	{	
	process* old = now;
		now=chg;
		change_process(old,chg);
	};

	
	
	void subst_shed::change_process(process* old, process* set)
	{
	procstate_operate = &(old->cntxt.state.state);
	save_procstate();
	
	if (old->status==process::RUN)
	{
	old->status=process::PAUSE;
	//set->status=process::RUN;
	procstate_operate = &(set->cntxt.state.state);
	load_procstate();
	}
	
	else 
	{
	//if (old->status==process::PAUSE) old->status=process::RUN;
	
	old->status=process::RUN;	
	//set->status=process::PAUSE;
	return;	};
	
	};
	
};


 