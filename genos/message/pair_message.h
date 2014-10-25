
#ifndef GENOS_PAIR_MESSAGE_H
#define GENOS_PAIR_MESSAGE_H


#include <genos.h>
#include <genos/stl_impl/utility.h>

namespace genos {

enum pair_message_code{
CHAR=0,
KEYCOM
};

enum KEYCOM_CODE{
LEFT=0,
RIGHT,
UP,
DOWN,
DEL,
BACKSPACE,
ENTER
};


typedef gstd::pair<size_t, size_t> pair_message;


};

#endif