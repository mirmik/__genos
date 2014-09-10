
#ifndef G_ERRSERV_H
#define G_ERRSERV_H

#include <genos/platform.h>

namespace genos {



enum errno{RINGBUFFER_FULL=0 ,
			RINGBUFFER_EMPTY,
			SUBSTSHED};

void sysErr (errno n, void* p);

};








#endif