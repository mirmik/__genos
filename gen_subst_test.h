

#include <genos_obj_subst.h>





/*
static void change(genos::process* h)
	{	
		subst.chg=subst.now;
		subst.now=h;
		change_gcontext(subst.now->gc, subst.chg->gc);
	}
*/




	/*



static 	int fork()
	{	
		//ATOMIC();
		 subst.chg2 = subst.add_new_process_with_hard_stack(300);
		
		//process* old = now;
		//old->gc.stack.sp=getSP();
		//old->gc.stack.copy(chg->stack);
		
		gcontext_init(subst.chg2->gc, subst.now->gc);
		//load_stack_pointer(chg->gc.stack);
		//change_gcontext(chg->gc,chg->gc);
		
		//load_stack_pointer(now->gc.stack);
		//now=chg;			//Хитрый мув ушами.
		//setSP(now->stack.sp);		//Смена контекста на самого себя.
		//substitution(); 	//Приводит к образованию копии.
			strmout << "MI";
delay(100);			
		if (subst.now->status==genos::process::CONSTRUCT) 
		{
			subst.now->status=genos::process::RUN;
			//DEATOMIC();
			return 0;
			
		}
		
		else //RUN
		{
			//int pid=chg->pid;
			//DEATOMIC();
			return 1;
		};	
						
	};
	**/