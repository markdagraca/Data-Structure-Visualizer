//
//  Node.h
//  DataStructureVisualizer
//
//  Created by Philipp Faraee on 2/23/17.
//  Copyright © 2017 Philipp Faraee. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <iostream>

template <class T>
struct Node {
    Node() {
        _previous = NULL;
        _next = NULL;
        _data = NULL;
    }
    
    Node(T data) {
        _data = data;
    }
    
    T _data;
    Node* _next;
    Node* _previous;
};


#endif /* Node_h */
