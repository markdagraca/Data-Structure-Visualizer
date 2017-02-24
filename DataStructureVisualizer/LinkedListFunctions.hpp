//
//  LinkedListFunctions.hpp
//  DataStructureVisualizer
//
//  Created by Philipp Faraee on 2/23/17.
//  Copyright © 2017 Philipp Faraee. All rights reserved.
//

#ifndef LinkedListFunctions_h
#define LinkedListFunctions_h
#include "Node.h"

template <class T>
void initHead(Node<T>* &head);

template <class T>
Node<T>* insertHead(Node<T>* &head, T data);

template <class T>
void print(Node<T>* head);

template <class T>
Node<T>* insertBefore(Node<T>* &head, Node<T>* root, T data);

template <class T>
Node<T>* insertAfter(Node<T>* root, T data);

/// Implementation
template <class T>
void initHead(Node<T>* &head) {
    head = NULL;
}

template <class T>
Node<T>* insertHead(Node<T>* &head, T data) {
    Node<T>* temp = new Node<T>(data);
    temp->_next = head;
    temp->_previous = NULL;
    
    if (head) head->_previous = temp;
    head = temp;
    
    return temp;
}

template <class T>
Node<T>* insertBefore(Node<T>* &head, Node<T>* root, T data) {
    if (!root->_previous) return insertHead(head, data);
    
    Node<T>* temp = new Node<T>(data);
    root->_previous->_next = temp; // sets node before the root to point at temp
    temp->_next = root; // temp now pointing to root;
    root->_previous = temp; // root now pointing back at temp;
    
    return temp;
}

template <class T>
Node<T>* insertAfter(Node<T>* root, T data) {
    // TODO: rewrite with third argument giving a reference to the tail of the list
    Node<T>* temp = new Node<T>(data);
    temp->_next = root->_next;
    temp->_previous = root;
    root->_next = temp;
    
    return temp;
}

template <class T>
void print(Node<T>* head) {
    std::cout << "h";
    
    while(head) {
        std::cout << head->_data << "->";
        head = head->_next;
    }
    
    std::cout << "|||" << std::endl;
}

#endif /* LinkedListFunctions_h */
