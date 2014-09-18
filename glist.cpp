



#include <genos/container/glist.h>
#include "stdio.h"
#include <string.h>

	 
namespace genos {

glist::glist(allocator* _alloc) : elements(0), head(&head, &head), alloc(_alloc)  {};
	

 node_list* glist::node_list_construct(node_list* next, node_list* prev, size_t elem)
{
node_list* newnode_list = (node_list*) alloc->allocate(sizeof(node_list) + elem);
new (newnode_list) node_list(next,prev);
return newnode_list;
};


node_list* glist::new_node_list_after(node_list* nd, size_t elem){
node_list* newnode = node_list_construct(nd->next, nd, elem);
nd->next->prev = newnode;
nd->next=newnode;
return newnode;
};


void glist::delete_node_list(node_list* nd){
nd->next->prev=nd->prev;
nd->prev->next=nd->next;
alloc->deallocate (nd);
};


void* glist::_push_back(size_t elem){
return (new_node_list_after(head.prev, elem))->outop() ;
};

void* glist::_push_front(size_t elem){
return (new_node_list_after(&head, elem))->outop();
};


void glist::pop_back(){
delete_node_list(head.prev);
};


void glist::pop_front(){
delete_node_list(head.next);
};

};