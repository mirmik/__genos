


#ifndef LAZY_STARTUP_H
#define LAZY_STARTUP_H

#include <genos.h>
#include <genos/algorithm.h>
#include <genos/container/glist.h>
//#include <genos/container/space.h>
 
//typedef void(*func_op_t)(genos::sheduler::lazy_timer*);
 typedef void(*func_op_t)(void*);

 
namespace genos {


enum lazy_timer_status
{ONCE=0,
REPEAT};

namespace sheduler {

class LazyStartup;

class lazy_timer {
public:
	unsigned long start;
	unsigned int timeout;
	func_op_t f;
	lazy_timer_status st;
	size_t opsize;

	lazy_timer (unsigned long _start, unsigned int _timeout, func_op_t _f ,lazy_timer_status _st, size_t _opsize) : 
	start(_start), timeout(_timeout), f(_f) ,st(_st), opsize(_opsize) {
	};
	void* outop() {return ((void*)(this+1));};

};



class LazyStartup {
glist timers;

public:
LazyStartup() : timers(sizeof(lazy_timer)) {}


template<typename optype>
lazy_timer* add_timer(unsigned int _timeout, lazy_timer_status _st, func_op_t _f, optype op) {
lazy_timer* lt = timers.push_back_spaced<lazy_timer>(sizeof(optype), lazy_timer(millis(), _timeout, _f, _st, sizeof(optype)));
new (static_cast<optype*>(lt->outop())) optype(op); 
};

lazy_timer* add_timer(unsigned int _timeout, lazy_timer_status _st, func_op_t _f) {
lazy_timer* lt = timers.push_back<lazy_timer>(lazy_timer(millis(), _timeout, _f, _st, 0));
};

void check();
};

};};


//#define add_lazy_timer(startup, timeout, st, f) (startup._add_lazy_timer(timeout, st, (func_op_t)f, 0))
//#define add_lazy_timer(startup, timeout, st, f, optype) (startup._add_lazy_timer(timeout, st, (func_op_t)f, sizeof(optype)))


#endif