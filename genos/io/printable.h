


#ifndef PRINTABLE_H
#define PRINTABLE_H

//#include <genos/io/o.h>


namespace genos {
class ostream;

		class printable{
			public:
				virtual ostream& printTo (ostream& o)=0;
		};
};











#endif