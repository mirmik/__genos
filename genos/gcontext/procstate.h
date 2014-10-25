

#ifndef GENOS_PROCSTATE
#define GENOS_PROCSTATE

#include <genos/io/printable.h>

namespace genos{


#include <avr/io.h>
	
  struct state_t{
	byte r0;
	byte r1;
	byte r2;
	byte r3;
	byte r4;
	byte r5;
	byte r6;
	byte r7;
	byte r8;
	byte r9;
	byte r10;
	byte r11;
	byte r12;
	byte r13;
	byte r14;
	byte r15;
	byte r16;
	byte r17;
	byte r18;
	byte r19;
	byte r20;
	byte r21;
	byte r22;
	byte r23;
	byte r24;
	byte r25;
	byte r26;
	byte r27;
	byte r28;
	byte r29;
	byte r30;
	byte r31;
	byte sreg;
	size_t sp;
	unsigned long int pc;
};
	#define REG_LEN 32
	#define PROCSTATE_LEN 35
	
	class procstate : public printable
	{
	public:
	volatile union{
	volatile state_t state; 
	};
	public:
	procstate(){memset((void*)&(state.r0),0,sizeof(state_t));};
	
	//void copy_to(void* dest){memcpy(dest, state, PROCSTATE_LEN);};
	
	
	ostream& printTo(ostream& o){
	for(int i=0;i<REG_LEN;i++)
	o << "REG" << i << ":" << hex << *((byte*)(&(state))+i) << endl;
	o << "SREG" << ":" << hex << state.sreg << endl;
	o << "SP"  << ":" << hex << state.sp << endl;
	o << "PC"  << ":" << hex << state.pc << endl;
	};
	
	};	
	
	
};

extern volatile void* procstate_operate;

extern "C"{

void save_procstate(void);
void load_procstate(void)__attribute__((noreturn));


};

#endif