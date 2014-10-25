
#include <genos.h>
#include <genos/console/strexecute.h>
#include <genos/container/ringbuffer.h>
#include <genos/platform_drv.h>
//#include "HardwareSerial.h"



void task1(int, char**)
{
Serial.println("task1 was executed\n");
}

void task2(int argc, char** argv)
{
int i=0;
Serial.println("task2 was executed with many string parametr");
while (argc != i) {Serial.print(i); Serial.print('\t'); Serial.println(argv[i++]);};
}

void task3(int argc, char** argv)
{
int i=0;
Serial.println("\ntask3 was executed with numeric parametr");
Serial << "argv[0]:\t" << argv[0] << genos::endl;
Serial << "argv[1]:\t" << atoi(argv[1]) << genos::endl;
Serial << "argv[2]:\t" << atof(argv[2]) << genos::endl;
}
;
void setup() {
  Serial.begin(9600);
  strExec.add_command("task1",task1);
  strExec.add_command("task2",task2);
  strExec.add_command("task3",task3);
  
  strexecute("task1");
  strexecute("task2 Alice Bob Chupokabra SpiderMan");  
  strexecute("task3 992 0.18");  
}

void loop() {
}