
/**
 * Created By Mark Dagraca
 * 2/26/2017
 */
#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H
#include "node.h"

/**
 * initalizes Headpointer to NULL
 * @param head_ptr take in a pointer to a node
 */
template <class T>
void _init_head(node<T>* &head_ptr);
/**
 * Insert head places item at the very first node of a link list
 * @param head_ptr-The current first node
 * @param item - The item that you want to be placed in the linklist
 * @return a pointer to the newley created node
 */
template <class T>
node<T>* _insert_head(node<T>* &head_ptr, T item);
/**
 * Print out the link list in console all the way to the tail
 * @param head the very first node you want printed out
 */
template <class T>
void _print_list(node<T>* head);
/**
 * Inserts after the giving node
 * @param head_ptr The very first pointer in the link list
 * @param after_ptr the node that you wish to place the new node after
 * @param item - The item that you want to be placed in the linklist
 * @return a pointer to the newley created node
 */
template <class T>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* &after_ptr, T item);
/**
 * Inserts before the giving node
 * @param head_ptr The very first pointer in the link list
 * @param after_ptr the node that you wish to place the new node before
 * @param item - The item that you want to be placed in the linklist
 * @return a pointer to the newley created node
 */
template <class T>
node<T>* _insert_before(node<T>* &head_ptr, node<T>* &before_ptr, T item);
template <class T>
/**
 * Search/Get
 * @param the starting point at which you wish to search
 * @param item that you wish to retrieve
 * @return the first pointer that matches the given item from the starting point
 */
node<T>* search(node<T>* &head_ptr,T item);
/**
 * Delete node.
 * @param head_ptr The very begging of the link list
 * @param item node which you want deleted
 */
template <class T>
void _delete(node<T>* &head_ptr,node<T>* &item);
/**
 * Delete entire link list
 * @param head_ptr the head of the link list wanted clear
 */
template <class T>
void clear(node<T>* &head_ptr);

#include <iostream>
#include "list_functions.h"
using namespace std;

template <class T>
void _init_head(node<T>* &head_ptr){
        head_ptr = NULL;
}
template <class T>
node<T>* _insert_head(node<T>* &head_ptr, T item){//tested
        //1. make the node
        node<T>* temp = new node<T>(item);
        //2. next of new node = head_ptr
        temp->next = head_ptr;
        //3. prev of what head_ptr points to = this new node
        if (head_ptr)
                head_ptr->prev = temp;
        //4. prev of the new node = NULL (done by ctor)
        temp->prev = NULL;
        //5. head_ptr point to new node
        head_ptr = temp;

        return temp;
}
template <class T>
void _print_list(node<T>* head_ptr){
        cout<<"H->";
        while (head_ptr != NULL) {
                cout<<head_ptr->item<<"->";
                head_ptr = head_ptr->next;
        }
        cout<<"|||"<<endl;
}
template <class T, class I>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* &after_ptr, I item)//tested
{

        if(after_ptr==NULL)
        {
                return _insert_head(after_ptr,item);
        }
        else
        {
                node<T>* temp=new node<T>(item);
                temp->next=after_ptr->next;
                temp->prev=after_ptr;
                after_ptr->next=temp;
                if(temp->next!=NULL)
                {
                        temp->next->prev=temp;
                }
                return temp;

        }



}

template <class T>
node<T>* _insert_before(node<T>* &head_ptr, node<T>* &before_ptr, T item)//tested
{
        node<T>* temp = new node<T>(item);
        if(before_ptr==head_ptr)
        {
//        return _insert_head(head_ptr,item);
        }
        else
        {

                temp->next=before_ptr;
                temp->prev=before_ptr->prev;
                before_ptr->prev->next=temp;
                temp->prev->next=temp;

        }
        return temp;
}
template <class T>
node<T>* search(node<T>* &head_ptr,T item)
{
        node<T>* temp=head_ptr;
        while(temp->item!=item&&temp!=NULL)
        {
                temp=temp->next;
        }
        return temp;
}
template <class T>
void _delete(node<T>* &head_ptr,node<T>* &item)
{

        if(item!=NULL)
        {

                if(item->prev!=NULL)
                {
                        item->prev->next=item->next;
                }
                else
                {
                        head_ptr=item->next;
                        if(head_ptr!=NULL)
                        {
                                head_ptr->prev=NULL;
                        }
                        return;
                }
                if(item->next!=NULL)
                {
                        item->next->prev=item->prev;
                }



        }


}
template <class T>
void clear(node<T> *&head_ptr)
{
        while(head_ptr!=NULL)
        {
                node<T>* temp=head_ptr->next;
                _delete(head_ptr,head_ptr);
        }
}

#endif // LIST_FUNCTIONS_H
ss
