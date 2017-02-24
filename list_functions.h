#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H
#include "node.h"


void _init_head(node* &head_ptr);
node* _insert_head(node* &head_ptr, int item);
void _print_list(node* head);
node* _insert_after(node* &head_ptr,node* &after_ptr, int item);
node* _insert_before(node* &head_ptr,node* &before_ptr, int item);
node* search(node* head_ptr,int item);
void _delete(node* &item);
void clear(node* &head_ptr);


#endif // LIST_FUNCTIONS_H
