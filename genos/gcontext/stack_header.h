

#ifndef GENOS_STACK_HEADER
#define GENOS_STACK_HEADER

#include <genos/container/flagbyte.h>
#include <genos_obj.h>
#include <genos/io/printable.h>
#include <genos/debug/dump.h>
#include "genos/subst/SubstMacro.h"

namespace genos {


class stack_header : public printable{
	public:
	stack_header(void* st) : start(st), sp(st) {}; 
	//stack_header() {}; 
	
	void init(void* st) {start=st; sp=st;};
	void newbegin(void* st) { sp=((size_t)st - (size_t)start) + sp; start=st;};
	
	void* start;
	void* sp;

	void* begin(){return start;};
	void* last() {return sp+1;};
	
	size_t size() {return (size_t)start - (size_t)sp;};
	
	
	void copy_to_stack(stack_header& st, size_t len) {
	st.sp = st.start - len;
	memcpy((void*)st.sp + 1, (void*)sp + 1, len);
	};
	
	
	void copy_to_stack(stack_header& st) {
	int len = size();
	st.sp = st.start - len;
	memcpy((void*)st.sp + 1, (void*)sp + 1, len);
	};
	
	
	void save_to_buffer(void* array) {
	int len = size();
	memcpy(array, (void*)sp + 1, len);
	};
	
	void load_from_buffer(void* array) {
	int len = size();
	memcpy((void*)sp + 1, array, len);
	};
		
	ostream& printTo(ostream& o)
	{dump_to_ostream(o,last(), size());
	return o;};
	
};
};

#define save_stack_pointer(st) (st).sp = getSP();
#define load_stack_pointer(st) setSP((st).sp);

#endif