


#include <genos/sheduler/LazyStartupF.h>
#include <genos/system/time.h>
#include <genos/container/dynamic_obj.h>
#include <genos/gstl_impl/algorithm>

namespace genos{
namespace sheduler {


void check_and_run_f (void* obj){
		lazy_timer_f* tm = static_cast<lazy_timer_f*>(obj);
		unsigned long now = millis();
		if (now - tm->start >= tm->timeout) 
			{
			tm->start += tm->timeout;
			(tm->f)->operator()();
			};
		};
	
	
void LazyStartupF::check()
{
gstd::for_each_ptr(timers.begin(),timers.end(),check_and_run_f);
};






};
};