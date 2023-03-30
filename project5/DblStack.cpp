// File name: DblStack.cpp
// Name: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 5
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Description:  Maintains a stack of ItemType.  Implements functions to
//               push, pop, retrieve top, and retrieve size of the stack.
//
// Last Changed: March 14th, 2023

#include <cstddef>
#include <stdexcept>
#include <string>
#include "DblStack.h"


// Constructor
// Create an empty DblStack
DblStack::DblStack() : mySize(0), myHead(nullptr) {}


// Copy constructor
DblStack::DblStack(const DblStack& rhs) : mySize(rhs.mySize), myHead(nullptr)
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


// Destructor
DblStack::~DblStack()
{
    while (myHead) {
        auto tmp = myHead;
        myHead = myHead->next;
        delete tmp;
    }

    mySize = 0;
}


// Copy Assignment Operator
const DblStack& DblStack::operator= (const DblStack& rhs)
{
    if (this != &rhs) {
        DblStack tmp(rhs);
        std::swap(myHead, tmp.myHead);
        std::swap(mySize, tmp.mySize);
    }

    return *this;
}


// Checks if stack is empty, returns true or false
bool DblStack::isEmpty() const {return !myHead;}


// Pushes an item on top of the stack
void DblStack::push(const ItemType& item)
{
    myHead = new Node(item, myHead);
    ++mySize;
}


// Pops the top item off the stack
void DblStack::pop()
{
    if (!myHead)
        throw std::underflow_error("Stack is empty");

    auto tmp = myHead;
    myHead = myHead->next;
    delete tmp;
    --mySize;
}


// Returns the top item of the stack without popping it
ItemType DblStack::top() const
{
    if (!myHead)
        throw std::underflow_error("Stack is empty");

    return myHead->val;
}


// Returns the number of items on the stack
size_t DblStack::size() const {return mySize;}