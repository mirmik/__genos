
#include <genos.h>
#include <genos/sheduler/LazyStartupF.h>
#include <genos/functor_drv.h>

genos::sheduler::LazyStartupF LS;


void setup()
{
pinMode(13,OUTPUT);
 LS.add_timer(200, genos::REPEAT, blink);
 LS.add_timer(350, genos::REPEAT, ser_print);
}

void loop()
{
LS.check();
}