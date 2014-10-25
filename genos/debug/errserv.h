
#ifndef G_ERRSERV_H
#define G_ERRSERV_H

#include <genos/platform.h>

namespace genos {



enum errno{RINGBUFFER_FULL=0 ,
			RINGBUFFER_EMPTY,
			SUBSTSHED,
			SERIAL_ERROR,
			MALLOC_ERROR};

void sysErr (errno n, void* p);

};








#endif