
#include "genos.h"
#include "genos/container/quantumbuffer.h"
#include "genos/container/ringbuffer.h"
#include "genos/io/o.h"
#include "genos/container/gstring.h"



class sss : public genos::ostream
{
size_t write(byte c) {Serial.write((char)c);};
} Ser;


genos::ostream* std2out = (genos::ostream*) &Ser; 

genos::ringbuffer rb(9);
byte a;

char str[100];

void setup() {
  
  genos::gstring gs("Mirmik");
  // put your setup code here, to run once:
rb.push_back('M');
rb.push_back('i');
rb.push_back('r');
rb.push_back('m');
rb.push_back('i');
rb.push_back('k');

int len=rb.available();
//rb.print(k);
rb.to_string(str);
Serial.println(str);

rb.push_back('M');
rb.push_back('i');
rb.push_back('r');
rb.push_back('m');
rb.push_back('i');
rb.push_back('k');

rb.to_string(str);
Serial.println(str);


*std2out << 2;

*std2out << gs << genos::endl;
*std2out << gs << genos::endl;
*std2out << gs << genos::endl;
//  rb.write(str,2);

}

void loop() {
  // put your main code here, to run repeatedly:

}