




#include "Arduino.h"
#include <genos.h>
#include <genos/debug/debug_print.h>
#include <genos/container/hard_stack.h>
#include <genos/container/glist.h>
#include <genos/alloc.h>
#include <genos/algorithm.h>
#include <genos/sheduler/subst_shed.h>


extern genos::hard_stack* mainstack;
genos::hard_stack* teststack;

genos::SubstShed Shed;

void format(void * obj)
{reinterpret_cast<genos::hard_stack*>(obj)->format();};


int main() {

init();
Serial.begin(9600);
debug_print("Genos main\n");

//delay(10);
// STACK INSTALLATION
mainstack = Shed.add_stack(300);
SP=mainstack->begin();
Shed.now = mainstack;
__malloc_heap_end=(char*)RAMEND;
// STACK INSTALLATION

Serial.println("Stack has been moved\n");

setup();

while(1) loop();

};