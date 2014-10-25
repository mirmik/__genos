


#ifndef LAZY_STARTUP_H
#define LAZY_STARTUP_H

#include <genos.h>
#include <genos/stl_impl/algorithm>
#include <genos/container/glist.h>
#include <genos/functor_drv.h>

namespace genos {


enum lazy_timer_status
{ONCE=0,
REPEAT};

namespace sheduler {

class LazyStartupF;

class lazy_timer_f {
public:
	unsigned long start;
	unsigned int timeout;
	voidFunctor* f;
	lazy_timer_status st;
	size_t opsize;

	lazy_timer_f (unsigned long _start, unsigned int _timeout, voidFunctor* _f ,lazy_timer_status _st, size_t _opsize) : 
	start(_start), timeout(_timeout), f(_f) ,st(_st), opsize(_opsize) {
	};
};



class LazyStartupF {
glist timers;

public:
LazyStartupF() : timers() {}


lazy_timer_f* add_timer(unsigned int _timeout, lazy_timer_status _st, voidFunctor& _f) {
lazy_timer_f* lt = timers.push_back<lazy_timer_f>(lazy_timer_f(millis(), _timeout, &_f, _st, 0));
};

void check();
};

};};


#endif