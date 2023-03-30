// File name: GuitarStringTest.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
//
// Description: tests the GuitarString class
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Last Changed: March 27th, 2023

#include "GuitarString.h"
#include <iostream>

int main()
{
    GuitarString str(6);
    str.pluck();

    double num = str.sample();
    str.tic();
    double num1 = str.sample();

    if (num == num1)
        std::cout << "test 1 FAIL" << std::endl;

    size_t time = 0;
    for (int x = 0; x < 100; ++x) {
        str.tic();
        if (str.getTime() < time)
            std::cout << "test 2 FAIL" << std::endl;
        time = str.getTime();
    }

    return 0;
}
