// File name: LifoPointAgenda.h
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 7
// Honor Statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Description:
// Last Changed: April 5th, 2023


#ifndef LifoPointAgenda_H
#define LifoPointAgenda_H

#include "PointAgenda.h"
#include "Stack_t.h"


class LifoPointAgenda : public PointAgenda
{
    Stack<Point> stack;

public:
    // virtual Class Destructor
    virtual ~LifoPointAgenda() {}

    // isEmpty (pure virtual)
    // Checks if the agenda is empty
    virtual bool isEmpty() const {return stack.isEmpty();}

    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item) {stack.push(item);}

    // remove (pure virtual)
    // removes the next Point from the agenda.
    virtual void remove() {stack.pop();}

    // peek (pure virtual)
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const {return stack.top();}

    // size (pure virtual)
    // Returns the number of Points in the agenda.
    virtual size_t size() const {return stack.size();}


};

#endif


