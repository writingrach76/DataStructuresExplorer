#include "SimpleLinkedList.hpp"
#include <iostream>
using namespace std;

int main()
{
    //will test linked lists here!
    SimpleLinkedList<int> mylist;
    mylist.insert(5);
    mylist.insert(7);
    mylist.insert(2);
    mylist.insert(8);
    SimpleLinkedList<int> mylist2 = mylist.reverse();
    //mylist->addEnd(9);
    mylist.deleteElmF();
    mylist2.displayList();
   // delete mylist2;
   

   /*
    mylist->deleteElm();
    mylist->deleteElm();
    mylist->insert(400);
    cout << "----" << endl;
    mylist->displayList();
    cout << mylist->inList(7) << endl;
    */
}