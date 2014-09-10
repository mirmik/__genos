
#include <genos.h>
#include <genos/container/allocator_pull.h>
#include <genos/container/allocator_pull_manager.h>
#include <genos/algorithm.h>
#include <genos/debug/debug_print.h>
#include <genos/container/hard_stack.h>
#include <genos/sheduler/subst_shed.h>
#include <genos/sheduler/LazyStartup.h>

genos::allocator_pull AP16(16);

extern genos::SubstShed Shed;
genos::sheduler::LazyStartup LS;
extern genos::hard_stack* mainstack;
extern genos::hard_stack* teststack;

void ttt2(void *){
Serial.println("f"); delay(1);
Shed.change(teststack);};

void ttt() {
  int i=0;
Serial.println(i++);
digitalWrite(13,1);
Shed.change(mainstack);};


void setup() {
  pinMode(13,1);
  delay(10);
 //mainstack = Shed.add_stack(300);
 
  // put your setup code here, to run once:
  teststack = Shed.create(100,ttt);
Shed.change(teststack);
LS.add_timer(200, genos::REPEAT, ttt2);
 
  Serial.println(mainstack->roof());
  Serial.println(teststack->roof());
  Serial.println(mainstack->size());
  Serial.println(mainstack->isActive());
  Serial.println(teststack->isActive());
  Serial.println((int)malloc(28),HEX);
Serial.println((int)RAMEND,HEX);
/*  AP16.print();
  void* t = AP16.allocate(16);
 // AP16.print();
 AP16.allocate(16);
  // AP16.print();
  AP16.allocate(16);
 // AP16.allocate(16);
  //AP16.print();
  
  AP16.allocate(16);
 // AP16.allocate(16);
  AP16.print();
 void* t2 =   AP16.allocate(16);
AP16.allocate(16);
  AP16.print();
  AP16.deallocate(t,0);
 AP16.deallocate(t2,0);
 // AP16.deallocate(t,0);
 // AP16.deallocate(t,0);
 // AP16.deallocate(t,0);
   AP16.print();*/
 //  delay(2000);
 Serial.flush();
//debug_print_dump(mainstack->outop(),mainstack->stack_size);
//debug_print_dump(teststack->outop(),teststack->stack_size);

};

void loop() {
  // put your main code here, to run repeatedly:
LS.check();
}