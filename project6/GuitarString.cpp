// File name: GuitarString.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
//
// Description: simulates the playing of guitar notes, function definitions
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Last Changed: March 27th, 2023

#include "GuitarString.h"
#include <cmath>
#include <chrono>
#include <random>


// The constructor for a string of the given frequency
GuitarString::GuitarString(double frequency) : time(0), frequency(frequency),
    generator((unsigned) std::chrono::system_clock::now().time_since_epoch().count())
{
    if (frequency <= 0)
        throw std::invalid_argument("non-positive frequency");

    for (long n = lround(SAMPLE_RATE / frequency); n > 0; --n)
        queue.enqueue(0);
}


// Pluck the string
void GuitarString::pluck()
{
    auto size = queue.size();

    while (!queue.isEmpty())
        queue.dequeue();

    std::uniform_real_distribution<double> distribution(-0.5, 0.5);

    while (size--)
        queue.enqueue(distribution(generator));
}


// Tic the clock by advancing the simulation one step
void GuitarString::tic()
{
    auto top = sample();
    queue.dequeue();
    queue.enqueue((top + sample()) / 2 * DECAY_FACTOR);
    ++time;
}


// Return the current sound sample of the string
double GuitarString::sample() const {return queue.front();}


// Return the number of time steps executed == number of calls to tic()
size_t GuitarString::getTime() const {return time;}


// Return the frequency of the string
double GuitarString::getFrequency() const {return frequency;}