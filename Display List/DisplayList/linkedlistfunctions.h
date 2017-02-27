#ifndef LINKEDLISTFUNCTIONS_H
#define LINKEDLISTFUNCTIONS_H

#include <iostream>
#include <assert.h>

using namespace std;

template <class ITEM_TYPE>
struct node{
    ITEM_TYPE item;
    node<ITEM_TYPE>* next;
    node();
    node(ITEM_TYPE input);
};

template <class ITEM_TYPE>
node<ITEM_TYPE>* search(node<ITEM_TYPE>* headptr, const ITEM_TYPE &findMe);
/* Preconditions:
 * Postconditions:
 */

template <class ITEM_TYPE>
node<ITEM_TYPE> *InsertHead(node<ITEM_TYPE>* &headptr, const ITEM_TYPE &addMe);
/* Preconditions:
 * Postconditions:
 */

template <class ITEM_TYPE>
ostream &PrintList(ostream &out, node<ITEM_TYPE> *headptr);
/* Preconditions: headpointer is initialized
 * Postconditions: prints out the entire list
 * Will keep printing ptr->item til it hits a NULL ptr
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>* ptr, const ITEM_TYPE &addMe);
/* Preconditions: assumes ptr is initialized
 * Postconditions: will point ptr to a new node, and that new node to the original ptr->next
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* copylist(node<ITEM_TYPE>* headptr);
/* Preconditions: assumes headptr is pointing to a list with at least 1 node
 * Postconditions: copies every node in the original list returns the headpointer to the new list
 */

template <class ITEM_TYPE>
ITEM_TYPE DeleteHead(node<ITEM_TYPE>* &headptr);
/* Preconditions: assumes headptr is initialized
 * Postconditions: deletes the headptr node and sets headptr to original headptr->next
 */

template <class ITEM_TYPE>
void DeleteAll(node<ITEM_TYPE> *&headptr);
/* Preconditions: assumes headptr is initialized
 * Postconditions; deletes the entire list by deleteing the headptr until headptr is null
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* Previous(node<ITEM_TYPE> *beforeMe, node<ITEM_TYPE>* headptr);
/* Preconditions: assumes headptr is pointing to the start of the list
 * Postconditions: returns null if not found, returns the ptr to the node before beforeMe if found goes through nodes looking for beforeMe in ptr->next
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>* beforeMe, node<ITEM_TYPE>* &headptr, const ITEM_TYPE &addMe);
/* Preconditions: assumes headptr is pointing to the start of the list
 * Postconditions: inserts head if the first item, inserts addMe before beforeMe
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* Remove(node<ITEM_TYPE>* &headptr, node<ITEM_TYPE>* thenode);
/* Preconditions: assumes node is in the list that headptr starts
 * Postconditions: changes the node->next pointing to thenode to thenode->next, returns the ptr to thenode
 */

template <class ITEM_TYPE>
ITEM_TYPE Delete(node<ITEM_TYPE>* headptr, node<ITEM_TYPE>* thenode);
/* Preconditions: assumes node is in the list that headptr starts
 * Postconditions: removes then deletes a node
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* At(node<ITEM_TYPE>* headptr, int index);
/* Preconditions: assumes headptr has at least index amounts of items in the list
 * Postconditions: looks for the n'th entry in the list that headptr pts to
 */

template <class ITEM_TYPE>
int index(node<ITEM_TYPE>* headptr, ITEM_TYPE item);
/* Preconditions: assumes headptr is initialized and starting a list
 * Postconditions: searches for item in the list, and returns the integer index
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE> *headptr, const ITEM_TYPE &item);
/* Preconditions: assumes headptr is init and the list is sorted
 * Postconditions: returns the node ptr to the node right before or equal to the item
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &headptr, const ITEM_TYPE &item);
/* Preconditions: assumes headptr is init and the list is sorted
 * Postconditions: returns the node ptr to the node that was entered sorted
 */

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertUniqueSorted(node<ITEM_TYPE> *&headptr, const ITEM_TYPE &item);
/* Preconditions: assumes headptr is init and the list is sorted
 * Postconditions: returns the node ptr to the node that was entered sorted, will not input a node if that item is already in the list
 */



template <class ITEM_TYPE>
node<ITEM_TYPE>::node(){
    item = ITEM_TYPE();
    next = nullptr;
}


template <class ITEM_TYPE>
node<ITEM_TYPE>::node(ITEM_TYPE input){
    item = input;
    next = nullptr;
}


template <class ITEM_TYPE>
node<ITEM_TYPE>* search(node<ITEM_TYPE>* headptr, const ITEM_TYPE &findMe){
    node<ITEM_TYPE>* w = headptr;
    while(w && w->item != findMe)
        w = w->next;
    return w;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertHead(node<ITEM_TYPE>* &headptr, const ITEM_TYPE &addMe){
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(addMe);
    temp ->next = headptr;
    headptr = temp;
    return temp;
}

template <class ITEM_TYPE>
ostream& PrintList(ostream &out, node<ITEM_TYPE>* headPtr){
    if(!headPtr)
        return out;
    node<ITEM_TYPE>* w = headPtr;
    while(w){
        out<<w->item<<"->";
        w = w->next;
    }
    out<<"|||";
return out;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE> *ptr, const ITEM_TYPE &addMe){
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(addMe);
    temp ->next = ptr ->next;
    ptr ->next = temp;
    return temp;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* copylist(node<ITEM_TYPE>* headptr)
{
    node<ITEM_TYPE>* w = headptr;
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(w->item);
    node<ITEM_TYPE>* w2 = temp;
    w = w->next;
    while(w){
        InsertAfter(w2,w->item);
        w = w->next;
        w2 = w2->next;

    }
    return temp;
}


template <class ITEM_TYPE>
ITEM_TYPE DeleteHead(node<ITEM_TYPE> *&headptr)
{
    ITEM_TYPE temp = headptr->item;
    node<ITEM_TYPE>* p = headptr->next;
    delete headptr;
    headptr = p;
    return temp;
}


template <class ITEM_TYPE>
void DeleteAll(node<ITEM_TYPE> *&headptr)
{
    while(headptr)
        DeleteHead(headptr);
    headptr = NULL;
}


template <class ITEM_TYPE>
node<ITEM_TYPE> *Previous(node<ITEM_TYPE> *beforeMe, node<ITEM_TYPE> *headptr)
{
    node<ITEM_TYPE>* ptr = headptr;
    if(ptr == beforeMe)
        ptr = NULL;
    else{
        while(ptr->next != beforeMe && ptr)
            ptr = ptr->next;
        assert(ptr);
    }
    return ptr;
}

template <class ITEM_TYPE>
node<ITEM_TYPE> *InsertBefore(node<ITEM_TYPE>* beforeMe,node<ITEM_TYPE>* &headptr, const ITEM_TYPE &addMe)
{
    node<ITEM_TYPE>* temp = Previous(beforeMe,headptr);
    if(temp == NULL){
        InsertHead(headptr, addMe);
        return headptr;
    }
    else
    {
        InsertAfter(temp ,addMe);
        return temp->next;
    }
}


template <class ITEM_TYPE>
node<ITEM_TYPE> *Remove(node<ITEM_TYPE> *&headptr, node<ITEM_TYPE> *thenode)
{
    if(headptr == thenode)
        headptr = thenode->next;
    else
        Previous(thenode, headptr)->next = thenode->next;
    return thenode;
}


template <class ITEM_TYPE>
ITEM_TYPE Delete(node<ITEM_TYPE> *headptr, node<ITEM_TYPE> *thenode)
{
    ITEM_TYPE temp;
    temp = thenode->item;
    delete[] Remove(headptr, thenode);
    return temp;
}


template <class ITEM_TYPE>
node<ITEM_TYPE> *At(node<ITEM_TYPE> *headptr, int index)
{
    node<ITEM_TYPE>* ptr = headptr;
    for(int i = 0; i < index; i++)
        ptr = ptr->next;
    return ptr;
}


template <class ITEM_TYPE>
int index(node<ITEM_TYPE> *headptr, ITEM_TYPE item)
{
    node<ITEM_TYPE>* ptr = headptr;
    int i = 0;
    while(ptr && ptr->item != item){
        i++;
        ptr = ptr->next;
    }
    if(!ptr)
        return -1;
    else
        return i;
}


template <class ITEM_TYPE>
node<ITEM_TYPE> *WhereThisGoes(node<ITEM_TYPE> *headptr, const ITEM_TYPE &item)
{
    node<ITEM_TYPE>* ptr = headptr;
    if (!ptr || ptr->item > item)
        return NULL;
    else{
        while(ptr->next && ptr->next->item <= item)
        {
           ptr = ptr->next;
        }
        return ptr;
    }
}


template <class ITEM_TYPE>
node<ITEM_TYPE> *InsertSorted(node<ITEM_TYPE> *&headptr, const ITEM_TYPE &item)
{
    node<ITEM_TYPE>* ptr = WhereThisGoes(headptr, item);
    if(ptr)
        return InsertAfter(ptr, item);
    else{
        InsertHead(ptr, item);
        return ptr;
    }
}


template <class ITEM_TYPE>
node<ITEM_TYPE> *InsertUniqueSorted(node<ITEM_TYPE>* &headptr, const ITEM_TYPE &item)
{
    node<ITEM_TYPE>* ptr = WhereThisGoes(headptr, item);
    if (!ptr)
        return InsertHead(headptr, item);
    else if (ptr->item == item)
        return NULL;
    else
        return InsertAfter(ptr, item);
}




#endif // LINKEDLISTFUNCTIONS_H
