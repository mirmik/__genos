
#include <genos.h>
#include <genos/sheduler/LazyStartup.h>


genos::sheduler::LazyStartup LS;

void blink(void* op)
{
int* a = static_cast<int*>(op);
*a = (*a + 1) % 2;
digitalWrite(13,*a);
}

void ser_print(void*)
{
Serial.println(millis());
}

void setup()
{
pinMode(13,OUTPUT);
 LS.add_timer(200, genos::REPEAT, blink, int(0));
 LS.add_timer(350, genos::REPEAT, ser_print);
}

void loop()
{
LS.check();
}