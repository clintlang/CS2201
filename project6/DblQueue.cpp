// File name: DblQueue.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
//
// Description: defines functions for a queue of ItemType
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Last Changed: March 27th, 2023

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <string>
#include "DblQueue.h"


// Constructor
// Create an empty DblQueue
DblQueue::DblQueue() : myHead(nullptr), myTail(nullptr), mySize(0) {}


// Copy Constructor
DblQueue::DblQueue(const DblQueue& rhs) : myHead(nullptr), myTail(nullptr), mySize(rhs.mySize)
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
// Destroys a queue
DblQueue::~DblQueue()
{
    while (myHead) {
        auto tmp = myHead;
        myHead = myHead->next;
        delete tmp;
    }

    mySize = 0;
}


// Assignment operator
// Assigns a queue to another
const DblQueue& DblQueue::operator= (const DblQueue& rhs)
{
    if (this != &rhs) {
        DblQueue tmp(rhs);
        std::swap(myHead, tmp.myHead);
        std::swap(myTail, tmp.myTail);
        std::swap(mySize, tmp.mySize);
    }

    return *this;
}


// isEmpty
// Checks if the queue is empty
bool DblQueue::isEmpty() const {return !myHead;}


// enqueue
// enqueues an item to back of the queue
void DblQueue::enqueue(const ItemType& item)
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
// dequeues the front item off the queue
void DblQueue::dequeue()
{
    if (!myHead)
        throw std::underflow_error("Queue is empty");

    auto tmp = myHead;
    myHead = myHead->next;
    delete tmp;
    --mySize;
}


// front
// Returns the front item of the queue without dequeueing it
ItemType DblQueue::front() const
{
    if (!myHead)
        throw std::underflow_error("Queue is empty");

    return myHead->val;
}


// size
// Returns the number of items on the queue.
size_t DblQueue::size() const {return mySize;}