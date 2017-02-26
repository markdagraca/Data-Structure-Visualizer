//
//  main.cpp
//  DataStructureVisualizer
//
//  Created by Philipp Faraee on 2/23/17.
//  Copyright © 2017 Philipp Faraee. All rights reserved.
//

#include <iostream>
#include "LinkedListFunctions.hpp"
#include "Node.h"

int main(int argc, const char * argv[]) {
    Node<int>* head;
    initHead(head);
    
    Node<int>* searchVal1 = NULL;
    Node<int>* searchVal2 = NULL;
    
    for(int i = 0; i < 10; i++ ) {
        if(i == 5) {
            searchVal1 = insertHead(head, i * 8); //SIMULATES A SEARCH
            continue;
        } else if (i == 3) {
            searchVal2 = insertHead(head, i * 8);
            continue;
        }
        
        insertHead(head, i * 8);
    }
    
    insertBefore(head, searchVal1, 3);
    insertAfter(searchVal2, 5);
    
    print(head);
    
    return 0;
}
