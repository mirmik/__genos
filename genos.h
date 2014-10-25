




#ifndef GENOS
#define GENOS


#include "stdlib.h"
#include "genos/debug/debug_print.h"

#define INTCOM
#define MALLOC_ALLOCATOR
#define STREAM_OUTPUT
#define SUBST_SHED
#define PROCSTATE_OPERATE


#define BOARD_CRIUS
//#define ARDUINO_SPI
//#define CRIUS_SPI_DATAFLASH


//#define GENOS_ERRSERV 
//to activate errserver.
#include  <genos/debug/errserv.h>
// platform functions.
#include  <genos/platform.h>

#define MACHINE_NAME "machine"


extern void DoNothing();
#endif


