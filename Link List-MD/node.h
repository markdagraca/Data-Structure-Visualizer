#ifndef NODE_H
#define NODE_H

template <class T>
struct node
{

        node();
        node(T i);
        T item;
        node* next;
        node* prev;
};
template <class T>
node<T>::node()
{
        next = NULL;
        prev = NULL;
        item = 0;
}
template<class T>
node<T>::node(T i)
{
        next = NULL;
        prev = NULL;
        item = i;
}

#endif // NODE_H
