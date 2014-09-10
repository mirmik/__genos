

#include <genos.h>
#include <genos/container/gstring.h>







genos::gstring gs = "Mirmik";

void setup ()
{
Serial.begin(9600);
gs+"f"+"jj";
genos::gstring gs2(gs);
gs2+'d'+'a';

Serial.println(gs.c_str());
Serial.println(gs2.c_str());

};




void loop ()
{};