// File name: Queue_t.h
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 7
// Honor Statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Description: declares functions of a Queue class
// Last Changed: April 5th, 2023


#ifndef QUEUE_T_H
#define QUEUE_T_H

#include <cstddef>


template <typename T>
class Queue
{
    struct Node {
        T val;
        Node* next;
        Node(T val, Node* next = nullptr) : val(val), next(next) {}
    };

    Node* myHead;
    Node* myTail;

    size_t mySize;


    public:
        // Class Constructor
        Queue();

        // Copy Constructor
        // pre:  Class object, aQueue, exists
        // post: Object is initialized to be a copy of the parameter
        Queue(const Queue& rhs);

        // Class Destructor
        // Destroys a stack
        // pre:  Class object exists
        // post: Class object does not exist
        ~Queue();

        // Assignment operator
        // Assigns a stack to another
        // pre: both class objects exist
        // post: this class object gets assigned a copy of the parameter class object
        const Queue& operator= (const Queue& rhs);

        // isEmpty
        // Checks if the stack is empty
        // pre:  A stack exists.
        // post: Returns true if it IS empty, false if NOT empty.
        bool isEmpty() const;

        // enqueue
        // enqueues an item to back of the stack.
        // pre:  Queue exists and item is passed.
        // post: adds the given item to the end of the stack.
        void enqueue(const T& item);

        // dequeue
        // dequeues the front item off the stack
        // pre:  Queue exists.
        // post: Removes item on front of the stack. If the stack
        //       was already empty, throws an std::underflow_error exception.
        void dequeue();

        // front
        // Returns the front item of the stack without dequeueing it.
        // pre:  Queue exists.
        // post: Returns item at front of stack.  If the stack is empty,
        //       throws an std::underflow_error exception.
        T& front() const;

        // size
        // Returns the number of items on the stack.
        size_t size() const;

};


#include "Queue_t.cpp"
#endif