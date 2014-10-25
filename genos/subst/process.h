
#ifndef GENOS_PROCESS_HEADER
#define GENOS_PROCESS_HEADER

#include <inttypes.h>
#include <genos/gcontext/stack_header.h>
#include <genos/gcontext/gcontext.h>
#include <genos/subst/hard_stack.h>
#include <genos/container/list.h>
#include <genos/io/printable.h>
#include <genos.h>


namespace genos {

class process : public printable{
public:
enum{
CONSTRUCT1=0,
CONSTRUCT2,
PAUSE,
RUN,
WAIT
};

public:

	gcontext cntxt;
	hard_stack* hard;
	int pid;
	uint8_t status;
	
	process(void* st) : cntxt(st), hard(0), status(CONSTRUCT1) {};

ostream& printTo (ostream& o){
	o << "PID" << pid << "\tSTAT:" << status  << "\tSTACK:" << hex << (int)cntxt.stack.start << '\n';

	};
	};



class process_list : public printable{
public:
list<process> lst;
//process* now;

process_list(){};

public:
void init(void* start_stack) {
process* proc = lst.push_front(process(start_stack));
proc->status=process::RUN;
proc->pid=0;
//now = proc;
};

process* initproc() {return &lst.begin();};

class find_pred_pid{
public:
int pid;
find_pred_pid(int _pid) : pid(_pid) {};
bool operator()(process& proc){return (pid == proc.pid);};
};

process* find(int pid) 
{
find_pred_pid obj(pid);
list<process>::iterator it = gstd::find_if(lst.begin(),lst.end(),obj);
if (it == lst.end()) return 0;
else return &it;
};

 ostream& printTo (ostream& o)
{
	o << "N\tSTAT\tPID\tSACK\t\n" ;
	int i=0;
	for(list<process>::iterator it = lst.begin(); it != lst.end(); it++)
	{
	o << i << '\t' << it->status << '\t' << it->pid << '\t' << hex << (int)it->cntxt.stack.start << '\n';	
	i++;
	};

};


};

};


#endif