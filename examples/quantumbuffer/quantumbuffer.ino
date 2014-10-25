
#include <genos.h>
#include <genos/sheduler/LazyStartupF.h>
#include <genos/functor_drv.h>
#include <genos_obj.h>
//#include <genos/dev/eeprom_dev.h>

#include <genos/container/quantumbuffer.h>

genos::sheduler::LazyStartupF LS;

genos::quantumbuffer qb(8,sizeof(int));

void setup()
{
pinMode(13,OUTPUT);
 LS.add_timer(200, genos::REPEAT, blink);
 LS.add_timer(350, genos::REPEAT, ser_print);
 //qb.engage();
 //qb.engage();
 qb.push_front<int>(4);
 qb.push_front<int>(8);
 
 qb.push_front<int>(4);
 qb.push_front<int>(8);
 
 
 qb.push_front<int>(6);
 qb.push_front<int>(6);
strmout << qb;

}

void loop()
{
//LS.check();
}