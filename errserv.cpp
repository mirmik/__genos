
#include "genos/debug/errserv.h"
#include "genos/debug/debug_print.h"

namespace genos {


//#ifdef GENOS_ERRSERV 
void sysErr (errno n, void* p) {
 //stdout << "REGISTREDERR¹ " << n << " objaddr " << genos::hex << p;
 debug_print("REGISTREDERR¹");
 dpr_inthex((int)n);
 dpr_tab();
 delay(10);
 halt();
 };
//#else
//void sysErr (errno n, void* p){};
//#endif
};

