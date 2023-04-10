// Ignore the message from CLion telling you this file does not belong to any project target

// File name: Queue_t.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 7
// Description: defines functions of a Queue class
// Last Changed: April 5th, 2023


#include <algorithm>
#include <cstddef>
#include <stdexcept>


// Constructor
// Create an empty DblQueue
template <typename T>
Queue<T>::Queue() : myHead(nullptr), myTail(nullptr), mySize(0) {}


// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
template <typename T>
Queue<T>::Queue(const Queue<T>& rhs) : myHead(nullptr), myTail(nullptr), mySize(rhs.mySize)
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

    myTail = newPtr;
}


// Class Destructor
// Destroys a stack
// pre:  Class object exists
// post: Class object does not exist
template <typename T>
Queue<T>::~Queue()
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
const Queue<T>& Queue<T>::operator= (const Queue<T>& rhs)
{
    if (this != &rhs) {
        Queue<T> tmp(rhs);
        std::swap(myHead, tmp.myHead);
        std::swap(myTail, tmp.myTail);
        std::swap(mySize, tmp.mySize);
    }

    return *this;
}


// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename T>
bool Queue<T>::isEmpty() const {return !myHead;}


// enqueue
// enqueues an item to back of the stack.
// pre:  Queue exists and item is passed.
// post: adds the given item to the end of the stack.
template <typename T>
void Queue<T>::enqueue(const T& item)
{
    if (!myHead) {
        myHead = new Node(item);
        myTail = myHead;
    } else {
        auto tmp = myTail;
        myTail = new Node(item);
        tmp->next = myTail;
    }

    ++mySize;
}


// dequeue
// dequeues the front item off the stack
// pre:  Queue exists.
// post: Removes item on front of the stack. If the stack
//       was already empty, throws an std::underflow_error exception.
template <typename T>
void Queue<T>::dequeue()
{
    if (!myHead)
        throw std::underflow_error("Queue is empty");

    auto tmp = myHead;
    myHead = myHead->next;
    delete tmp;
    --mySize;
}


// front
// Returns the front item of the stack without dequeueing it.
// pre:  Queue exists.
// post: Returns item at front of stack.  If the stack is empty,
//       throws an std::underflow_error exception.
template <typename T>
T& Queue<T>::front() const
{
    if (!myHead)
        throw std::underflow_error("Queue is empty");

    return myHead->val;
}


// size
// Returns the number of items on the stack.
template <typename T>
size_t Queue<T>::size() const {return mySize;}