#ifndef GENOS_GLIST
#define GENOS_GLIST

#include <genos/container/dynamic_obj.h>
#include <genos/alloc.h>
#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>
#include <genos/io/printable.h>

namespace genos {


class node_list {
	public:
	node_list* next; 
	node_list* prev;

	node_list () : next(0), prev(0) {};
	node_list (node_list* _next, node_list* _prev) : next(_next), prev(_prev) {};
	void* outop() {return(static_cast<void*>(this + 1));}
};

class glist : public printable
{
		public:
		size_t elements;
		node_list head;
		allocator* alloc;
		
		public:		
		
		glist(allocator* _alloc = &malloc_allocator);
		
		void* _push_back(size_t elem);
		void* _push_front(size_t elem);
		
		void __push_front(node_list* newnode);
		void __push_back(node_list* newnode);
		
		void pop_back();
		void pop_front();

		void __pop_back();
		void __pop_front();
		
		size_t size() {return elements;};
		
	
	template<typename valtype> inline valtype* push_back(valtype V) 
	{return new (static_cast<valtype*> (_push_back(sizeof(V)))) valtype(V);};
	
	template<typename valtype> inline valtype* push_front(valtype V) 
	{return new (static_cast<valtype*> (_push_front(sizeof(V)))) valtype(V);};
	
	template<typename valtype> inline valtype* push_back_spaced(size_t space,valtype V) 
	{return new (static_cast<valtype*> (_push_back(sizeof(V) + space))) valtype(V);};
	
	template<typename valtype> inline valtype* push_front_spaced(size_t space,valtype V) 
	{return new (static_cast<valtype*> (_push_front(sizeof(V) + space))) valtype(V);};

	template<typename valtype> inline valtype* construct() 
	{return new (static_cast<valtype*> (node_list_allocate(sizeof(valtype))->outop())) valtype;};
	
	template<typename valtype> inline valtype* construct(valtype V) 
	{return new (static_cast<valtype*> (node_list_allocate(sizeof(valtype))->outop())) valtype(V);};
	
	void del_all(){while(size()) pop_back();};
		
	class iterator {//: public abstract_iterator{
	public:
	node_list* current;
	public:
	iterator(node_list* _node) : current(_node) {};		

	iterator operator++(int) { iterator i = *this; current=current->next; return i; }
	iterator operator++() { current=current->next; return *this; }
	iterator operator--(int) { iterator i = *this; current=current->prev; return i; }
	iterator operator--() { current=current->prev; return *this; }
	bool operator!= (const iterator& b) {return current != b.current;};
	
	//void* operator*() {return (current->outop());};
	//void* operator->() {return (current->outop());}  //???
	void* ptr() {return (current->outop());};
	};
		
	class reverse_iterator{
	public:
	node_list* current;
	public:
	reverse_iterator(node_list* _node) : current(_node) {};		

	reverse_iterator operator++(int) { reverse_iterator i = *this; current=current->prev; return i; }
	reverse_iterator operator++() { current=current->prev; return *this; }
	bool operator!= (const reverse_iterator& b) {return current != b.current;};
	//void* operator*() {return (current->outop());};
	//void* operator->() {return (current->outop());}  //???
	void* ptr() {return (current->outop());};
	operator iterator() {return iterator(current);};
	};
		
		iterator begin() {return iterator(head.next);};
		iterator end() {return iterator(&head);};
		
		reverse_iterator rbegin() {return reverse_iterator(head.prev);};
		reverse_iterator rend() {return reverse_iterator(&head);};
		
		
	//local:
	void paste_after(node_list* newnode, node_list* nd);
	void delete_node_list(node_list* nd);
	node_list* node_list_allocate(size_t elem);

	
	
void relist_back(iterator it, glist& lst);
void relist_front(iterator it, glist& lst);

ostream& printTo (ostream& o)
{
int i=0;
o << "ELEMENTS: " << elements << endl;
	for (iterator it = begin(); it!= end(); it++) 
	{
		i++;
		o << i << ": ADDR:";
		o.println((int)it.ptr(),HEX);
	};

}; 
	};

	node_list* glist_container(void* p);
		
};





#endif