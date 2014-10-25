



#include <genos.h>
#include <genos_obj_subst.h>
#include <genos_obj.h>
#include <genos/container/list.h>


#include <gen_subst_test.h>
namespace genos {

	
	volatile void os_time_tick() {
	
	#ifdef SUBST_SHED
	if (subst.substed_stat) 
		{
		//subst.off();
		subst.subst_it++;
		if (subst.subst_it == proclist.lst.end()) subst.subst_it = proclist.lst.begin();
		subst.change(&subst.subst_it);		
		};
	#endif
	};
	
	
	
	
	
	
	
	
	
};