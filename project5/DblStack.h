// File name: DblStack.h
// Name: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 5
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Description:  Maintains a stack of ItemType.  Contains function
//               prototypes to push, pop, retrieve top, and retrieve size of the
//               stack.
//
// Last Changed: March 14th, 2023

#ifndef DBLSTACK_H
#define DBLSTACK_H


typedef double ItemType; // stack currently holds doubles


class DblStack
{
  private:

    struct Node {
        ItemType val;
        Node* next;
        Node(ItemType val, Node* next = nullptr) : val(val), next(next) {}
    };

    size_t mySize;

    Node* myHead;

 
  public:
    // Class Constructor
    // post: stack is created & initialized to be empty
    DblStack();

    // Copy Constructor
    // pre: parameter object, rhs, exists
    // post: stack is created to be a copy of the parameter stack
    DblStack(const DblStack& rhs);

    // Class Deconstructor
    // pre: the stack exists
    // post: the stack is destroyed and any dynamic memory is returned to the system
    ~DblStack();

    // Assignment operator
    // Assigns a stack to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const DblStack& operator= (const DblStack& rhs);

    // isEmpty
    // Checks if the stack is empty
    // pre:  A stack exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // push
    // Pushes an item on top of the stack.
    // pre:  Stack exists and item is passed.
    // post: the item is placed on top of the stack, and size is incremented.
    void push(const ItemType& item);

    // pop
    // Pops the top item off the stack.
    // pre:  Stack exists.
    // post: Removes item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    void pop();

    // top
    // Returns the top item of the stack without popping it.
    // pre:  Stack exists.
    // post: Returns item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    ItemType top() const;

    // size
    // Returns the number of items on the stack.
    // post: Returns size from the private section of class.
    size_t size() const;

};


#endif

