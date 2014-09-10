
#include <genos.h>
#include <genos/console/strexecute.h>


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
Serial.print("argv[0]:\t"); Serial.println(argv[0]);
Serial.print("argv[1]:\t"); Serial.println(atoi(argv[1]));
Serial.print("argv[2]:\t"); Serial.println(atof(argv[2]));
}

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