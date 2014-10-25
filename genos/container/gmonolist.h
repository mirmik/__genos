#ifndef GENOS_MONOLIST
#define GENOS_MONOLIST

#include <genos/container/dynamic_obj.h>
#include <genos/alloc.h>
#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>

namespace genos {


class node_monolist {
	public:
	node_monolist* next; 

	node_monolist () : next(0) {};
	node_monolist (node_monolist* _next) : next(_next) {};
	void* outop() {return(static_cast<void*>(this + 1));}
};

class gmonolist
{
		protected:
		size_t elements;
		node_monolist head;
		allocator* alloc;
		
		public:		
		
		gmonolist(allocator* _alloc = &malloc_allocator);
		
		void* _push_back(size_t elem);
		//void* _push_front(size_t elem);
		
		void pop_back();
		//void pop_front();

		size_t size() {return elements;};
		
	template<typename valtype> inline valtype* push_back(valtype V) 
	{return new (static_cast<valtype*> (_push_back(sizeof(V)))) valtype(V);};
	
	//template<typename valtype> inline valtype* push_front(valtype V) 
	//{return new (static_cast<valtype*> (_push_front(sizeof(V)))) valtype(V);};
	
	template<typename valtype> inline valtype* push_back_spaced(size_t space,valtype V) 
	{return new (static_cast<valtype*> (_push_back(sizeof(V) + space))) valtype(V);};
	
	//template<typename valtype> inline valtype* push_front_spaced(size_t space,valtype V) 
	//{return new (static_cast<valtype*> (_push_front(sizeof(V) + space))) valtype(V);};

	inline void push_back_placed(void* p) 
	{__push_back(static_cast<node_monolist*>(p));};
		
	class iterator {//: public abstract_iterator{
	public:
	node_monolist* current;
	public:
	iterator(node_monolist* _node) : current(_node) {};		

	iterator operator++(int) { iterator i = *this; current=current->next; return i; }
	iterator operator++() { current=current->next; return *this; }
	bool operator!= (const iterator& b) {return current != b.current;};
	void* operator*() {return (current->outop());};
	//void* operator->() {return (current->outop());}  //???
	};
		
		
		iterator begin() {return iterator(head.next);};
		iterator end() {return iterator(&head);};
		
		
	//local:
	node_monolist* new_node_list_after(node_monolist* nd, size_t elem);
	//void delete_node_list(node_monolist* nd);
	node_monolist* node_list_allocate(size_t elem);
	void __push_back(node_monolist*);
	void __pop_back();
		};

};





#endif