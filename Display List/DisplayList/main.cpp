#include <iostream>
#include "linkedlistfunctions.h"
#include "displaylist.h"

using namespace std;

int main()
{
    node<int>* headptr = new node<int>(-10);
    for(int i = 0; i <= 2; i++){
        InsertHead(headptr,i);
    }
    PrintList(cout,headptr)<<endl;
    DisplayList mylist(headptr);
    mylist.run();
    return 0;


}
