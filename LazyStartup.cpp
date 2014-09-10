


#include <genos/sheduler/LazyStartup.h>
#include <genos/system/time.h>
#include <genos/container/dynamic_obj.h>
#include <genos/algorithm.h>

namespace genos{
namespace sheduler {


void check_and_run (void* obj){
		lazy_timer* tm = static_cast<lazy_timer*>(obj);
		unsigned long now = millis();
		if (now - tm->start >= tm->timeout) 
			{
			tm->start += tm->timeout;
			tm->f(tm->outop());
			};
		};
	
	
void LazyStartup::check()
{
for_each(timers.begin(),timers.end(),check_and_run);
};






};
};