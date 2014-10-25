

#ifndef FUNCTOR_DRV
#define FUNCTOR_DRV

//#include <genos.h>
#include <genos/platform.h>
#include <genos_obj.h>

class voidFunctor {
public:
virtual void operator()()=0;
};

#ifdef ARDUINO
class blink_cls : public voidFunctor{
  int a;
  public:
  blink_cls() : a(0) {};
  public:
  void operator()(){
    a = (a + 1) % 2;
    digitalWrite(13,a);
};
};

extern blink_cls blink;
#endif



#ifdef BOARD_CRIUS
#include <genos/board/CRIUS.h>
class ledrun_cls : public voidFunctor{
  int a;
  public:
  ledrun_cls() : a(0) {};
  public:
  void operator()(){
    a = (a + 1) % 3;
	
	switch (a)
		{
		case 0: digitalWrite(LED_RED,1); digitalWrite(LED_GREEN,0); digitalWrite(LED_YELLOW,0);  break;
		case 1: digitalWrite(LED_RED,0); digitalWrite(LED_GREEN,0); digitalWrite(LED_YELLOW,1);  break;
		case 2: digitalWrite(LED_RED,0); digitalWrite(LED_GREEN,1); digitalWrite(LED_YELLOW,0);  break;
		};	
	};
};

extern ledrun_cls ledrun;


class blink_green_cls : public voidFunctor{
  int a;
  public:
  blink_green_cls() : a(0) {};
  public:
  void operator()(){
    a= a+1;
	a = a % 2;
    digitalWrite(LED_GREEN,a);
};
};

extern blink_green_cls blink_green;


class blink_yellow_cls : public voidFunctor{
  int a;
  public:
  blink_yellow_cls() : a(0) {};
  public:
  void operator()(){
    a= a+1;
	a = a % 2;
    digitalWrite(LED_YELLOW,a);
};
};

extern blink_yellow_cls blink_yellow;
#endif









#endif