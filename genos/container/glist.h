#ifndef GENOS_LIST
#define GENOS_LIST

#include <genos/container/dynamic_obj.h>
#include <genos/alloc.h>
#include <genos/container/allocator_prototype.h>
#include <genos/container/allocator_malloc.h>

namespace genos {


class nodeobj {
public:
nodeobj* next; 
nodeobj* prev;

nodeobj () : next(0), prev(0) {};
nodeobj (nodeobj* _next, nodeobj* _prev) : next(_next), prev(_prev) {};
 void* outop() {return(static_cast<void*>(this + 1));}
};

class glist : public dynamic_obj{
		protected:
		size_t elements;
		nodeobj head;
		allocator_prototype* alloc;
		
		public:
	//	glist(size_t _element_size) : dynamic_obj(_element_size),  elements(0), 
	//	head(&head, &head), alloc(&malloc_allocator)  {};
		
		
		glist(size_t _element_size, allocator_prototype* _alloc = &malloc_allocator);
		//void resize(size_t n, void* x);
		
		void* _push_back();
		void* _push_front();
		
		void* _push_back_spaced(size_t space);
		void* _push_front_spaced(size_t space);

		void _pop_back();
		void _pop_front();

		void _pop_back_spaced(size_t space);
		void _pop_front_spaced(size_t space);

		size_t size() {return elements;};
		
	//template<typename valtype> inline valtype* push_back(valtype& V) 
	//{return new (static_cast<valtype*> (_push_back())) valtype(V);};
	template<typename valtype> inline valtype* push_back(valtype V) 
	{return new (static_cast<valtype*> (_push_back())) valtype(V);};
	//template<typename valtype> inline valtype* push_front(valtype& V) 
	//{return new (static_cast<valtype*> (_push_front())) valtype(V);};
	template<typename valtype> inline valtype* push_front(valtype V) 
	{return new (static_cast<valtype*> (_push_front())) valtype(V);};
	
	//template<typename valtype> inline valtype* push_back_spaced(size_t space, valtype& V) 
	//{return new (static_cast<valtype*> (_push_back_spaced(space))) valtype(V);};
	template<typename valtype> inline valtype* push_back_spaced(size_t space,valtype V) 
	{return new (static_cast<valtype*> (_push_back_spaced(space))) valtype(V);};
	//template<typename valtype> inline valtype* push_front_spaced(size_t space,valtype& V) 
	//{return new (static_cast<valtype*> (_push_front_spaced(space))) valtype(V);};
	template<typename valtype> inline valtype* push_front_spaced(size_t space,valtype V) 
	{return new (static_cast<valtype*> (_push_front_spaced(space))) valtype(V);};

		
	class iterator : public abstract_iterator{
	public:
	nodeobj* current;
	public:
	iterator(nodeobj* _node) : current(_node) {};		

	iterator operator++(int) { iterator i = *this; current=current->next; return i; }
	iterator operator++() { current=current->next; return *this; }
	iterator operator--(int) { iterator i = *this; current=current->prev; return i; }
	iterator operator--() { current=current->prev; return *this; }
	bool operator!= (const iterator& b) {return current != b.current;};
	void* operator*() {return (current->outop());};
	//void* operator->() {return (current->outop());}  //???
	};
		
	class reverse_iterator{
	public:
	nodeobj* current;
	public:
	reverse_iterator(nodeobj* _node) : current(_node) {};		

	reverse_iterator operator++(int) { reverse_iterator i = *this; current=current->prev; return i; }
	reverse_iterator operator++() { current=current->prev; return *this; }
	bool operator!= (const reverse_iterator& b) {return current != b.current;};
	void* operator*() {return (current->outop());};
	//void* operator->() {return (current->outop());}  //???
	};
		
		iterator begin() {return iterator(head.next);};
		iterator end() {return iterator(&head);};
		
		reverse_iterator rbegin() {return reverse_iterator(head.prev);};
		reverse_iterator rend() {return reverse_iterator(&head);};
		
	nodeobj* new_nodeobj_after(nodeobj* nd, size_t elem);
		void delete_nodeobj(nodeobj* nd, size_t elem);
	 nodeobj* nodeobj_construct(nodeobj* next, nodeobj* prev, size_t elem);
		};

};





#endif