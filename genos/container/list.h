

#ifndef GENOS_LIST
#define GENOS_LIST

#include <genos/container/dynamic_obj.h>
#include <genos/alloc.h>
#include <genos/allocator/allocator.h>
#include <genos/allocator/allocator_malloc.h>
#include <genos/io/printable.h>
#include <genos/function.h>
#include <genos/stl_impl/algorithm>
#include <genos/container/glist.h>
#include <genos/stl_impl/iterator_base>

namespace genos {

template <typename valtype>
class list : public printable{
public:
	genos::glist lst;

	list() : lst(&malloc_allocator) {};

	valtype* push_front(valtype V) 
	{return new (static_cast<valtype*> (lst._push_back(sizeof(V)))) valtype(V);};

	valtype* push_back(valtype V) 
	{return new (static_cast<valtype*> (lst._push_front(sizeof(V)))) valtype(V);};
	
	valtype* push_back_spaced(size_t space,valtype V) 
	{return new (static_cast<valtype*> (lst._push_back(sizeof(V) + space))) valtype(V);};
	
	valtype* push_front_spaced(size_t space,valtype V) 
	{return new (static_cast<valtype*> (lst._push_front(sizeof(V) + space))) valtype(V);};	

	valtype* construct() 
	{return new (static_cast<valtype*> (lst.node_list_allocate(sizeof(valtype))->outop())) valtype;};
	
	valtype* construct(valtype V) 
	{return new (static_cast<valtype*> (lst.node_list_allocate(sizeof(valtype))->outop())) valtype(V);};
	
	void pop_front()
	{lst.pop_front();};

 	void pop_back() 
	{lst.pop_back();};	
	
	class iterator {//: public abstract_iterator{
		public:
		
		typedef valtype value_type;
		typedef valtype* pointer;
		typedef valtype& reference;
		typedef int difference_type;
		typedef gstd::random_access_iterator_tag iterator_category;
		
		node_list* current;
		public:
		iterator(node_list* _node) : current(_node) {};	
		iterator() {};		

		iterator operator++(int) { iterator i = *this; current=current->next; return i; }
		iterator operator++() { current=current->next; return *this; }
		iterator operator--(int) { iterator i = *this; current=current->prev; return i; }
		iterator operator--() { current=current->prev; return *this; }
		
		bool operator!= (const iterator& b) {return current != b.current;};
		bool operator== (const iterator& b) {return current == b.current;};
	
		valtype& operator*() {return *static_cast<valtype*>(current->outop());};
		valtype* operator&() {return static_cast<valtype*>(current->outop());};
		valtype* operator->() {return static_cast<valtype*>(current->outop());}  
		difference_type operator-(iterator a) {return gstd::distance(a,*this);}  
		iterator operator-(int a) {iterator i = *this; while(--a) i--; return i;}  
		void* ptr() {return (current->outop());};
	};
		
	
	class reverse_iterator {//: public abstract_iterator{
		public:
		
		typedef valtype value_type;
		typedef valtype* pointer;
		typedef valtype& reference;
		typedef int difference_type;
		typedef gstd::random_access_iterator_tag iterator_category;
		
		node_list* current;
		public:
		reverse_iterator(node_list* _node) : current(_node) {};	
		reverse_iterator() {};		

		reverse_iterator operator++(int) { reverse_iterator i = *this; current=current->prev; return i; }
		reverse_iterator operator++() { current=current->prev; return *this; }
		reverse_iterator operator--(int) { reverse_iterator i = *this; current=current->next; return i; }
		reverse_iterator operator--() { current=current->next; return *this; }
		
		bool operator!= (const reverse_iterator& b) {return current != b.current;};
		bool operator== (const reverse_iterator& b) {return current == b.current;};
	
		valtype& operator*() {return *static_cast<valtype*>(current->outop());};
		valtype* operator&() {return static_cast<valtype*>(current->outop());};
		valtype* operator->() {return static_cast<valtype*>(current->outop());}  
		difference_type operator-(reverse_iterator a) {return gstd::distance(a,*this);}  
		
		void* ptr() {return (current->outop());};
	};
		
	iterator begin() {return iterator(lst.head.next);};
	iterator end() {return iterator(&lst.head);};
	
	iterator rbegin() {return iterator(lst.head.prev);};
	iterator rend() {return iterator(&lst.head);};
	
	ostream& printTo(ostream& o)
	{
	printAddr<valtype> f(&o);
	gstd::for_each(begin(),end(),f);
	};
	
	};

};


#endif