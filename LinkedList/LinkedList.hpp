#ifndef _LinkedList_HPP
#define _LinkedList_HPP

#include "Node.hpp"
/*
* This is an implementation of a simple linked list, which
* can only be navigated starting from the head and through
* each node to the end. 
*/
template <typename Data>
class LinkedList 
{
    private:
    Node<Data>* _head; //the beginning of the list
    int _size; //number of elements in the list

    public:
    /*
    * Initialize the list as null so that an empty list can exist
    * and initialize size as 0 for this
    */
    LinkedList()
    {
        _head = NULL;
        _size = 0;
    }

    public:
    /*
    * inserts a node at the beginning of the list
    */
    void insert(Data d)
    {
        Node<Data>* node = new Node<Data>(d, NULL);
        if(_head == NULL) //empty list therefore this is head
        {
            _head = node;
        }
        else if(_head->_next == NULL) //only one element in list, therefore
        {                           // this one will be the second
            Node<Data>* temp = _head;
            _head = node;
            _head->_next = temp;
        }
        else //more than 2 elements so adding to the beginning 
        {
            Node<Data>* temp = _head;
            _head = node;
            _head->_next = temp;

            /*
            Node<Data>* temp = _head->_next;
            _head->_next = node;
            _head->_next->_next = temp;
            */
        }
        _size++;
    }

    /*
    * This will delete an element from the beginning of the list
    */
    void deleteElm()
    {
        if(_head != NULL) //List is not empty and an element can be removed
        {
            if(_head->_next == NULL) //only one element in the list
            {
                _head = NULL;
            }
            else //more than one element in the list
            {
                Node<Data>* temp = _head->_next;
                _head = temp;
            }
            _size--;
        }
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

    /*
    * Reverses the list
    */
    LinkedList* reverse()
    {
        LinkedList* list = new LinkedList();
        helpReverse(_head, list);
        return list;
    }

    void helpReverse(Node<Data>* temp, LinkedList* list)
    {
        if(temp->_next == NULL)
            list->insert(temp->getData());
        else
            list->insert(helpReverse(temp->_next, list).getData());
    }

};
#endif