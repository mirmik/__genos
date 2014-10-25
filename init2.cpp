








#include <genos.h>

#ifdef BOARD_CRIUS
#include <genos/board/CRIUS.h>
#endif

//using namespace genos;

void init2(){

#ifdef ARDUINO
pinMode(13,1);
#endif

#ifdef BOARD_CRIUS
CRIUS.leds_init();
#endif

};
