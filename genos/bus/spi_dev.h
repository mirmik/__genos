

#ifndef GENOS_SPI_DEV_H
#define GENOS_SPI_DEV_H

namespace genos {

class spi_dev{
public:
virtual void select();
virtual void deselect();
virtual void init();
};







};
#endif