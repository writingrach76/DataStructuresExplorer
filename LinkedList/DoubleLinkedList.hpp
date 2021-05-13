#ifndef _DoubleLinkedList_HPP
#define _DoubleLinkedList_HPP

#include "DoubleNode.hpp";
template <typename Data>
class DoubleLinkedList
{
    private:
        DoubleNode<Data>* _head;
        DoubleNode<Data>* _tail;
        int _size;

    public:
    DoubleLinkedList()
    {
        _head = NULL;
        _tail = NULL;
        _size = 0;
    }

    ~DoubleLinkedList()
    {
        if(_head != NULL)
            delete _head;
        if(_tail != NULL)
            delete _tail;
    }

    public:
    /*
    * This inserts an element into the beginning of the list
    */
    Node<Data>* insert(Data d)
    {
        Node<Data>* node = new Node<Data>(d, NULL, NULL);
        if(_head == NULL) //empty list therefore this is head
        {
            _head = node;
            _tail = node; //since list is only 1 element _head == _tail
        }
        else if(_head == _tail) //only one element in list, therefore
        {                           // this one will be the second
            Node<Data>* temp = _head;
            _head = node;
            _head->_next = temp;
            _head->_next->_previous = _head;
            //no need to change _tail since we're adding to the front
        }
        else //more than 2 elements so adding to the beginning 
        {
            Node<Data>* temp = _head;
            _head = node;
            _head->_next = temp;
            _head->_next->_previous = _head;
            //again, no need to change _tail
        }
        _size++;
        return node;
    }

     DoubleNode<Data>* addEnd(Data d)
     {
         DoubleNode<Data> node = new DoubleNode(d, NULL, NULL);
         if(_tail == NULL) // then _head == NULL list is empty
         {
             _head = node;
             _tail = node;
         }
         else if(_head == _tail) // one element in the list
         {
             node._previous = _head;
             _head.next = node;
             _tail = node;
         }
         else //list has more than two elements in it
         {
             node._previous = _tail;
             _tail = node;
         }
        _size++;
        return node;
     }

     DoubleNode<Data> deleteElmF()
     {
         DoubleNode<Data> deleted = NULL;
         if(_head == NULL)
         {
             deleted = NULL; //list is empty
         }
         else if(_head == _tail) //list has 1 element in it
         {
             _head = NULL;
             _tail = NULL;
         }
         else //list has more than 2 elements in it
         {
             deleted = _head;
             _head = _head.previous;
         }
         size--;
         return deleted;
     }

    /*
    * Deleting an element from the end of the list
    */
     void deleteElmE() 
     {
         if(_head == NULL) // list is empty
         {
             return NULL;
         }
         else if(_head == _tail) //list has one element in it
         {
             _head = NULL;
             _tail = NULL;
         }
         else //list has two or more elements in it
         {
             _tail = _tail.previous;
         }
         size--;
     }

    /*
    * A method that reverses and returns the double linked list
    */
    DoubleLinkedList reverse()
    {
        DoubleLinkedList toReturn = new DoubleLinkedList();
        toReturn._tail = 
    }

     /*
    * This will return the number of Nodes currently in the list
    */
    int getSize()
    {
        return _size;
    }

    /*
    * Searches the list for an element and returns true if it is found
    */
    bool inList(Data d)
    {
        if(_head == NULL) //if list is empty, immediately return false
            return false;
        bool toReturn = false;
        Node<Data>* temp = _head;

        while(temp != NULL)
        {
            if(temp->getData() == d)
            {
                toReturn = true;
            }
            temp = temp->_next;
        }
        return toReturn;
    }

    /*
    * This will search the list and return the index of the first occurance of the element in the list
    */
    int search(Data d)
    {
        int toReturn = -1; // will return -1 if list is empty or d is not found in the list
        int index = 0;
        Node<Data>* temp = _head;
        while(temp != NULL)
        {
            if(temp->getData() == d)
            {
                toReturn = index;
                break;
            }
            index++;
        }

        return toReturn;
    }

    /*
    * Will print the current list in order starting with the head, to the console
    */
    void displayList()
    {
        Node<Data>* temp = _head;
        for(int i = 0; i < _size; i++)
        {
            temp->displayNode();
            temp = temp->_next;
        }
    }
};
#endif