#ifndef _Stack_HPP
#define _Stack_HPP
template <typename Data>
/*
* implementation of a stack using the simple linked list class that I created
*/
class Stack
{
    private:
    int _size; //size of the stack
    SimpleLinkedList<Data> _stack;

    public:
    Stack()
    {
        _stack = new SimpleLinkedList<Data>();
        _size = 0;
    }
    ~Stack()
    {
        if(_stack != NULL)
        {
            delete _stack;
        }
    }

    /*
    * pushes an element onto the front of the stack
    */
    void push(Data d)
    {
        _stack.insert(d);
        _size++;
    }

    /*
    * pops an element off of the front of the stack
    */
    Node<Data> pop()
    {
        return _stack.deleteElmF();
    }

    /*
    * returns the size of the stack
    */
   int size()
   {
       return _size;
   }

};
#endif