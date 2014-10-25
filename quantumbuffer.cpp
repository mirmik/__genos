






#include <genos/container/quantumbuffer.h>


namespace genos {




		void quantumbuffer::push_back(byte c){
		
		if (head == 0) 
			{add_quant_back();
			head_buffer=static_cast<byte*>(quants.head.prev->outop());};		
			
			*(head_buffer+head) = c;
			//void* temp = (head_buffer + head);
			head = (head + 1) % quant_size;
			//return temp;			
		size++;
		size>maxsize ? maxsize=size : maxsize=maxsize ;
		};


		byte quantumbuffer::pop_front(){
		size--;
		if (tail == 0) 		
			{
			if (tail_buffer!=0) remove_quant_front();
			tail_buffer=static_cast<byte*>(quants.head.next->outop());};	
			byte temp = *(tail_buffer + tail);
			tail = (tail + 1) % quant_size;
		
		if (size==0) restart();

			return temp;			
		};



};

