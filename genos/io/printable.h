


#ifndef PRINTABLE_H
#define PRINTABLE_H



namespace genos {



class ostream;

		
		class printable{
			public:
				virtual ostream& printTo (ostream& o)=0;
		};	
		
		
		
};

#include <genos/io/o.h>



#endif