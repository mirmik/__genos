
#ifndef GENOS_SYMB_DEV
#define GENOS_SYMB_DEV

#include <genos/message/pair_message.h>
namespace genos {

class symb_dev : public b_ostream{

virtual void command(pair_message) = 0; 

};

};

#endif