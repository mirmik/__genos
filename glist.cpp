



#include <genos/container/glist.h>
#include "stdio.h"
#include <string.h>

	 
namespace genos {

glist::glist(allocator* _alloc) : elements(0), head(&head, &head), alloc(_alloc)  {};
	

 node_list* glist::node_list_allocate(size_t elem)
{
node_list* newnode_list = (node_list*) alloc->allocate(sizeof(node_list) + elem);
return newnode_list;
};

/*
 node_list* glist::node_list_construct(node_list* next, node_list* prev, size_t elem)
{
node_list* newnode_list = (node_list*) alloc->allocate(sizeof(node_list) + elem);
new (newnode_list) node_list(next,prev);
return newnode_list;
};*/


void glist::paste_after(node_list* newnode, node_list* nd){
new (newnode) node_list(nd->next, nd);
nd->next->prev = newnode;
nd->next=newnode;
elements++;
};


void glist::delete_node_list(node_list* nd){
elements--;
nd->next->prev=nd->prev;
nd->prev->next=nd->next;
};

void glist::__push_back(node_list* newnode){
paste_after(newnode, head.prev);
};

void glist::__push_front(node_list* newnode){
paste_after(newnode, &head);
};

void* glist::_push_back(size_t elem){
node_list* newnode = node_list_allocate(elem);
__push_back(newnode);
return newnode->outop();
};

void* glist::_push_front(size_t elem){
node_list* newnode = node_list_allocate(elem);
__push_front(newnode);
return newnode->outop();
};


void glist::__pop_back(){
delete_node_list(head.prev);
};


void glist::__pop_front(){
delete_node_list(head.next);
};


void glist::pop_back(){
node_list* temp = head.prev;
delete_node_list(head.prev);
alloc->deallocate(temp);
};


void glist::pop_front(){
node_list* temp = head.next;
delete_node_list(head.next);
alloc->deallocate(temp);
};

void glist::relist_back(iterator it, glist& lst){
delete_node_list(it.current);
lst.__push_back(it.current);
};


void glist::relist_front(iterator it, glist& lst){
delete_node_list(it.current);
lst.__push_front(it.current);
};

};

genos::node_list* genos::glist_container(void* p) 
{return static_cast<genos::node_list*>(p - sizeof(genos::node_list));};