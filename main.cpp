



//#include <genos/platform/Arduino.h>
//#include <Arduino.h>
#include <genos.h>
//#include <genos/debug/debug_print.h>
//#include <genos/container/hard_stack.h>
//#include <genos/container/glist.h>
//#include <genos/alloc.h>
//#include <genos/stl_impl/algorithm>

#include <genos_obj.h>
#include <genos_obj_subst.h>

#include <genos/platform_drv.h>
//#include <genos/io/o.h>


extern void init2();
int main() {

init();
init2();

Serial.begin(115200);
//Serial.tx.engage(&malloc_allocator,4);
//Serial.rx.engage(&malloc_allocator,4);

strmout.connect(&Serial);
strmdebug.connect(&Serial);

strmout << genos::endl << "System is loaded. wait 1 sec:" << genos::endl;
delay(1000);


__malloc_heap_end=(char*)RAMEND;

proclist.init((void*)RAMEND);
subst.init();

setup();

while(1) loop();

};