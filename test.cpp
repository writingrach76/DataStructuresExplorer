#include "LinkedList.hpp"
#include <iostream>
using namespace std;

int main()
{
    //will test linked lists here!
    LinkedList<int>* mylist = new LinkedList<int>();
    mylist->insert(5);
    mylist->insert(7);
    mylist->insert(2);
    mylist->insert(8);
    LinkedList<int>* mylist2 = mylist->reverse();
    mylist2->displayList();
   
   /*
    mylist->deleteElm();
    mylist->deleteElm();
    mylist->insert(400);
    cout << "----" << endl;
    mylist->displayList();
    cout << mylist->inList(7) << endl;
    */
}