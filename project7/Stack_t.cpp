// Ignore the message from CLion telling you this file does not belong to any project target

// File name: Stack_t.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 7
// Description: defines functions of a Stack class
// Last Changed: April 5th, 2023


#include <cstddef>
#include <stdexcept>
#include <string>


// Class Constructor
// post: stack is created & initialized to be empty
template <typename T>
Stack<T>::Stack() : mySize(0), myHead(nullptr) {}


// Copy Constructor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack
template <typename T>
Stack<T>::Stack(const Stack<T>& rhs) : mySize(rhs.mySize), myHead(nullptr)
{
    if (!rhs.myHead)
        return;

    myHead = new Node(rhs.myHead->val);
    auto newPtr = myHead;
    auto origPtr = rhs.myHead;
    while (origPtr->next) {
        origPtr = origPtr->next;
        newPtr->next = new Node(origPtr->val);
        newPtr = newPtr->next;
    }
}


// Class Deconstructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
template <typename T>
Stack<T>::~Stack()
{
    while (myHead) {
        auto tmp = myHead;
        myHead = myHead->next;
        delete tmp;
    }

    mySize = 0;
}


// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename T>
const Stack<T>& Stack<T>::operator= (const Stack<T>& rhs)
{
    if (this != &rhs) {
        Stack<T> tmp(rhs);
        std::swap(myHead, tmp.myHead);
        std::swap(mySize, tmp.mySize);
    }

    return *this;
}


// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename T>
bool Stack<T>::isEmpty() const {return !myHead;}


// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.
template <typename T>
void Stack<T>::push(const T& item)
{
    myHead = new Node(item, myHead);
    ++mySize;
}


// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename T>
void Stack<T>::pop()
{
    if (!myHead)
        throw std::underflow_error("Stack is empty");

    auto tmp = myHead;
    myHead = myHead->next;
    delete tmp;
    --mySize;
}


// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename T>
T& Stack<T>::top() const
{
    if (!myHead)
        throw std::underflow_error("Stack is empty");

    return myHead->val;
}


// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
template <typename T>
size_t Stack<T>::size() const {return mySize;}