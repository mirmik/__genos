





#ifndef NULLSTRM
#define NULLSTRM

#include <genos.h>
#include <genos/io/o.h>

namespace genos {
class nullstrm_cls : public b_ostream {
size_t write(byte c){};
size_t write(const byte *buffer, size_t size){};
};

};
extern genos::nullstrm_cls nullstrm;


#endif