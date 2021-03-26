#ifndef _DoubleNode_HPP
#define _DoubleNode_HPP
#include <iostream>
/*
* This is a node class designed for a doubly linked list 
* and other data structures that are doubly linked
*/
template <typename Data>
class DoubleNode 
{
    private:
        Data _data;

    public:
         Node* _next;
         Node* _previous;

    DoubleNode(Data d, Node* next, Node* previous)
    {
        _data = d;
        _next = next;
        _previous = previous;
    }

    ~DoubleNode()
    {
        if(_next != NULL)
        {
            delete _next;
        }
        if(_previous != NULL)
        {
            delete _previous;
        }
    }

    public:
    
    /*
    */
    void changeData(Data data)
    {
        _data = data;
    }

    /*
    * Displays contents of the node
    */
     void displayNode()
    {
        cout << _data << endl;
    }

    /*
    * returns the data in the method
    */
     Data getData()
    {
        return _data;
    }

};
#endif