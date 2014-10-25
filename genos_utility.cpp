


#include <genos/genos_utility/gutility.h>
#include <genos_obj.h>
#include <genos_obj_exec.h>
#include <genos_obj_exec.h>
#include <genos/subst/subst_shed.h>

namespace genos {

#ifdef STREAM_OUTPUT

void about(int,char**){
strmout << "GenOS" << endl;
};


void ptest(int a,char** b){
while (a--) strmout << *(b++) << endl;
};


#ifdef INTCOM
void list_exec(int a,char** b){
strmout << strExec;
};
#endif

#ifdef SUBST_SHED
void list_proc(int a,char** b){
strmout << proclist;
};
#endif


#ifdef INTCOM
void registry_standart_utility()
{
strExec.add_command("about",about);
strExec.add_command("ptest",ptest);
strExec.add_command("list",list_exec);
strExec.add_command("ps",list_proc);
};
#endif

#endif

};