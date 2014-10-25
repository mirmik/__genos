

#include <genos.h>
#include <genos_obj.h>
#include <genos_obj_subst.h>
#include <genos_obj_exec.h>

#ifdef MALLOC_ALLOCATOR
#include <genos/allocator/allocator_malloc.h>
genos::allocator_malloc malloc_allocator;
#endif

#ifdef INTCOM
#include <genos/console/strexecute.h>
genos::strexecute strExec;
#endif

#ifdef SUBST_SHED
//genos::hard_stack* mainstack;
genos::subst_shed subst;
#endif 


#ifdef STREAM_OUTPUT
#include <genos/io/o.h>
#include <genos/io/i.h>
#include <genos/io/nullstrm.h>
genos::ostream strmout(&nullstrm);
genos::ostream strmdebug(&nullstrm);
genos::nullstrm_cls nullstrm;
#endif


#ifdef PROCSTATE_OPERATE
#include <genos/gcontext/procstate.h>
volatile void* procstate_operate;
#endif


#ifdef SUBST_SHED
#include <genos/subst/process.h>
genos::process_list proclist;
int genos::subst_shed::pid_gen;
#endif
/*
#ifdef ARDUINO_SPI
genos::SPI_driver_cls SPI_driver;
#endif
*/


unsigned long GENOS_SUBST_SYSTEM_TICK=3;

void DoNothing(){};