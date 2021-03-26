#ifndef _NODE_HPP
#define _NODE_HPP
#include <iostream>
using namespace std;

/*
* This is a Node designed for a simple linked list and other single direction data
* structures
*/

template <typename Data>
class Node
{
    private: 
    Data _data; //whatever the node should hold
    
    //private int _key;
    
    public:
    Node* _next; // a link to the next node, which could be
                        //NULL if there is nothing that it is linked to

    /*
    * initializes this node 
    */
    Node(Data d, Node* link)
    {
        _data = d;
        _next = link;
    }

    ~Node()
    {
        if(_next != NULL)
            delete _next;
    }

    public:
    /*
    * Allows the data within the node to be altered
    */
    void changeData(Data data)
    {
        _data = data;
    }

    /*
    * This was initially meant to keep track of and change each
    * Node as an index, however this has been scrapped for now.
    public void changeKey(int key)
    {
        _key = key;
    }
    */

    /*
    * Allows the link of the node to be changed
    * Possibly unneeded, if link remains a public class variable
    */
     void changeLink(Node* node)
    {
        _next = node;
    }

    /*
    * Displays contents of the node
    */
     void displayNode()
    {
        cout << _data << endl;
    }

    /*
    * Returns the data in the method
    */
     Data getData()
    {
        return _data;
    }
};
#endif