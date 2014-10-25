



#ifndef GENOS_FUNCTION_H
#define GENOS_FUNCTION_H


#include <genos_obj.h>
#include <genos/io/o.h>

namespace genos {

class printChar{
		public:
		void operator()(char c) {*o << c;};
		printChar(ostream* _o) : o(_o) {};
		protected:
			ostream* o;
		};	
	
		
		
template<typename T>
class printObj{
		public:
		void operator()(T& obj) 
		{*o << "ADDR: " << reinterpret_cast<size_t>(&obj) << " " << "VAL:" << obj;};
		printObj(ostream* _o) : o(_o) {};
		protected:
			ostream* o;
		};	
		
			
template<typename T>
class printAddr{
		public:
		void operator()(T& obj) 
		{*o << "ADDR: " << reinterpret_cast<size_t>(&obj) << "\n";};
		printAddr(ostream* _o) : o(_o) {};
		protected:
			ostream* o;
		};	
		
		
		
	};
		
		
#endif