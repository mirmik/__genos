



#include <genos/container/gmonolist.h>
#include "stdio.h"
#include <string.h>

	 
namespace genos {

gmonolist::gmonolist(allocator* _alloc) : elements(0), head(&head), alloc(_alloc)  {};
	

 node_monolist* gmonolist::node_list_allocate(size_t elem)
{
node_monolist* newnode_list = (node_monolist*) alloc->allocate(sizeof(node_monolist) + elem);
return newnode_list;
};
/*

node_monolist* gmonolist::new_node_list_after(node_monolist* nd, size_t elem){
node_monolist* newnode = node_list_construct(nd->next, nd, elem);
nd->next->prev = newnode;
nd->next=newnode;
return newnode;
};
*/
/*
void gmonolist::delete_node_list(node_monolist* nd){
nd->next->prev=nd->prev;
nd->prev->next=nd->next;
alloc->deallocate (nd);
};*/


void* gmonolist::_push_back(size_t elem){
node_monolist* newnode = node_list_allocate(elem);
__push_back(newnode);
return newnode->outop() ;
};


void gmonolist::__push_back(node_monolist* newnode){
new (newnode) node_monolist(head.next);
head.next =  newnode;
elements++;
};

/*
void* gmonolist::_push_front(size_t elem){
return (new_node_list_after(&head, elem))->outop();
};*/

void gmonolist::__pop_back(){
head.next=head.next->next;
elements--;
};

void gmonolist::pop_back(){
node_monolist* temp = head.next;
__pop_back();
alloc->deallocate (temp);
};

/*
void gmonolist::pop_front(){
delete_node_list(head.next);
};*/

};