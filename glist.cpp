



#include <genos/container/glist.h>
#include "stdio.h"
#include <string.h>

	 
namespace genos {

glist::glist(size_t _element_size, allocator_prototype* _alloc) : dynamic_obj(_element_size),  elements(0), 
head(&head, &head), alloc(_alloc)  {};
	

 nodeobj* glist::nodeobj_construct(nodeobj* next, nodeobj* prev, size_t elem)
{
nodeobj* newnodeobj = (nodeobj*) alloc->allocate(sizeof(nodeobj) + elem);
new (newnodeobj) nodeobj(next,prev);
return newnodeobj;
};


nodeobj* glist::new_nodeobj_after(nodeobj* nd, size_t elem){
nodeobj* newnode = nodeobj_construct(nd->next, nd, elem);
nd->next->prev = newnode;
nd->next=newnode;
return newnode;
};


void glist::delete_nodeobj(nodeobj* nd, size_t elem){
nd->next->prev=nd->prev;
nd->prev->next=nd->next;
alloc->deallocate (nd , sizeof(nodeobj) + elem);
};


void* glist::_push_back(){
return (new_nodeobj_after(head.prev, element_size))->outop() ;
};

void* glist::_push_front(){
return (new_nodeobj_after(&head, element_size))->outop();
};


void* glist::_push_back_spaced(size_t elem){
return (new_nodeobj_after(head.prev, elem + element_size))->outop() ;
};

void* glist::_push_front_spaced(size_t elem){
return (new_nodeobj_after(&head, elem + element_size))->outop();
};


void glist::_pop_back(){
delete_nodeobj(head.prev, element_size);
};


void glist::_pop_front(){
delete_nodeobj(head.next, element_size);
};



void glist::_pop_back_spaced(size_t outop_size){
delete_nodeobj(head.prev, element_size + outop_size);
};

void glist::_pop_front_spaced(size_t outop_size){
delete_nodeobj(head.next, element_size + outop_size);
};


};