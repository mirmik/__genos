

#include "Arduino.h"
#include <genos.h>


namespace genos {

void printaddr (void* obj){
	Serial.println((int)obj, HEX);
};


};