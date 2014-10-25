



#include <genos/debug/dump.h>

namespace genos {

void dump_to_ostream(ostream& o, void* address, size_t size){

  /* Преобразуем указатель в массив байт */
  uint8_t* dump = (uint8_t*) address; 
  /* Преобразуем указатель просто в число */  
  uint32_t addr_tmp = (size_t) address;
  /* Вспомогательные переменные */
  uint32_t i = 0;
  uint32_t mark = 0;
 
  for (i = 0; i < size; i++)
  {
    //set_text_color(LIGHT_GRAY);
   
    if (mark == 0)
    {
    o.print(addr_tmp,HEX);
   // char sss[20];
   // num2base_str(sss,addr_tmp,16);
   // dpr_str(sss);
    
    o.print(": ");
    }
   
    if (dump[i] != 0)
   ;//   set_text_color(LIGHT_GREEN);
    else
     // set_text_color(LIGHT_GRAY);
   ;
    o.printByte(dump[i]);
   
    //set_text_color(LIGHT_GRAY);
   
    if ( mark == 7 )
    {
      o.print("|");
      mark++;
    }
    else if ( mark == 15 )
    {
      o.write('\n');
      mark = 0;
     
      addr_tmp += 0x10;
    }
    else
    {
      o.print(" ");
      mark++;
    }
  } 
  if (mark%16 != 0) o.write('\n');




};

};