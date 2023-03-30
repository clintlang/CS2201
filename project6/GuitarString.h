// File name: GuitarString.h
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
//
// Description: simulates the playing of guitar notes, function declarations
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Last Changed: March 27th, 2023

#ifndef GUITARSTRING_H
#define GUITARSTRING_H

#include "DblQueue.h"
#include <random>


const size_t SAMPLE_RATE = 44100;
const double DECAY_FACTOR = 0.996;

class GuitarString {
private :
    size_t time;
    double frequency;
    DblQueue queue;
    std::default_random_engine generator;


public:
    // The constructor for a string of the given frequency.
    // pre: frequency is positive.
    // post: object is initialized to represent a string at rest.
    // Throws a std::invalid_argument exception if the frequency is not positive.
    GuitarString(double frequency);

    // Pluck the string.
    // post: replaced all elements in the ring buffer with the equivalent quantity of
    // random values between -0.5 and +0.5
    void pluck();

    // Tic the clock by advancing the simulation one step.
    // post: the Karplus-Strong update has been applied to the string.
    void tic();

    // Return the current sound sample of the string.
    double sample() const;

    // Return the number of time steps executed == number of calls to tic().
    size_t getTime() const;

    // Return the frequency of the string.
    double getFrequency() const;

};

#endif
