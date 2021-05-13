#ifndef _Queue_HPP
#define _Queue_HPP

#include "SimpleLinkedList.hpp"
template <typename Data>
/*
* An implementation of a Queue using the SimpleLinkedList class that I created.
* Queue's only have the capability to add to the back and remove from the front, 
* making a simple linked list ideal for this implementation
*/
class Queue {

    private:
    SimpleLinkedList<Data> _queue; //holds the queue
    int _size; //size of the queue

    public:
    Queue()
    {
        _queue = new SimpleLinkedList<Data>();
        _size = 0;
    }

    ~Queue()
    {
        if(_queue != NULL)
        {
            delete _queue;
        }
    }

    /*
    * Adds an element to the back of the queue
    */
    void push(Data d)
    {
        _queue.addEnd(d);
        _size++;
    }

    /*
    * Removes an element from the front of the queue and returns that element
    */
    Node pop()
    {
        size--;
        return _queue.deleteElmF();
    }

    /*
    * Returns the size of the queue
    */
    int getSize()
    {
        return _size;
    }

};
#endif