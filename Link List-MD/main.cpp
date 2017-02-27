#include <iostream>
#include "node.h"
#include "list_functions.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout<<endl<<endl<<endl<<endl;

    node<int>* head_ptr;
    _init_head(head_ptr);

      for (int i = 0; i< 3; i++){
      _insert_head(head_ptr,i*10);
   }
      _insert_before(head_ptr,head_ptr->next,555);




    _print_list(head_ptr);
    cout <<endl<<endl<<endl<< "------------------------------" << endl;

}
