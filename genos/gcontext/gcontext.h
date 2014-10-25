

#ifndef GCONTEXT
#define GCONTEXT

#include <genos/gcontext/stack_header.h>
#include <genos/gcontext/procstate.h>


namespace genos {

class gcontext{
public:
stack_header stack;
procstate state;   

public:
gcontext(void* stack_roof) : stack(stack_roof) {};
//gcontext() {};
};

void gcontext_init();
void change_gcontext(gcontext&,gcontext&);

};

#endif