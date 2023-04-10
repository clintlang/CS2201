// File name: FifoPointAgenda.h
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 7
// Honor Statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Description:  
// Last Changed: April 5th, 2023


#ifndef FifoPointAgenda_H
#define FifoPointAgenda_H


#include "PointAgenda.h"
#include "Queue_t.h"


class FifoPointAgenda : public PointAgenda
{
    Queue<Point> queue;

public:
    // virtual Class Destructor
    virtual ~FifoPointAgenda() {}

    // isEmpty (pure virtual)
    // Checks if the agenda is empty
    virtual bool isEmpty() const {return queue.isEmpty();}

    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item) {queue.enqueue(item);}

    // remove (pure virtual)
    // removes the next Point from the agenda.
    virtual void remove() {queue.dequeue();}

    // peek (pure virtual)
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const {return queue.front();}

    // size (pure virtual)
    // Returns the number of Points in the agenda.
    virtual size_t size() const {return queue.size();}


};

#endif

