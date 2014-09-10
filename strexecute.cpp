



#include <genos/console/strexecute.h>


int interpreter(int argc, const char* const* argv){

for (genos::glist::iterator it = strExec.list.begin() ; it != strExec.list.end() ; it++)

if (!strcmp(argv[0],get_objptr<genos::strexecute_record>(it)->name))
{
//tempstrm=(Stream*)stdio;
//stdio=strm;
((void (*)(int, const char* const*))(get_objptr<genos::strexecute_record>(it)->func))(argc,argv);
//stdio=tempstrm; 
return 0;
}
//pr("Command \"\033[35m");
//pr("Command \"");
//pr(argv[0]);
//prln("\033[0m\" not found. Use \"\033[33mlist\033[0m\" instruction.");
//prln("\" not found.");

return 0;
};
		

#define DROP_SPACE(c); for (;(*c!=0) && (*c==' '); c++);
#define DROP_OP(c); for (;(*c!=0) && (*c!=' '); c++);

void split (char* temp, argvc_t &a)
{	a.argc=0;
	while((*temp) !=0) {
	DROP_SPACE(temp);
	if (*temp != 0) {
		a.argv[a.argc]=temp;
		a.argc++;}
	DROP_OP(temp);
	if (*temp!=0) {*temp='\0';temp++;
		}
	}
}


void strexecute(char* c)
{
		argvc_t a;
		char* argv [10];
		a.argv=argv;
		split(c,a);
		interpreter(a.argc,a.argv);
};