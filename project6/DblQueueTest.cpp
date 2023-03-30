// File name: DblQueueTest.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
//
// Description: tests functions of class DblQueue
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Last Changed: March 27th, 2023

#include "DblQueue.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    // Test underflow_error
    DblQueue dbq1;
    try {
        std::cout << "Expect an \"underflow_error\" exception" << std::endl;
        std::cout << "The front of dbq1 is: " << dbq1.front() << std::endl;
        std::cout << "Test 1 FAIL. \"underflow_error\" exception should be thrown."
                  << std::endl;
    }
    catch (std::underflow_error& excpt) {
        std::cout << "Exception for Test 1 was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  top() threw the wrong exception." << std::endl;
    }
    try {
        std::cout << "Expect an \"underflow_error\" exception" << std::endl;
        dbq1.dequeue();
        std::cout << "Test 2 FAIL. \"underflow_error\" exception should be thrown."
                  << std::endl;
    }
    catch (std::underflow_error& excpt) {
        std::cout << "Exception for Test 2 was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  dequeue() threw the wrong exception." << std::endl;
    }


    // See if each loop prints the same (test of copy assignment operator)
    for (int x = 0; x < 10; ++x) {
        ItemType y = 2.1 * x;
        dbq1.enqueue(y);
    }
    DblQueue dbq2 = dbq1;
    for (int x = 0; x < 10; ++x) {
        std::cout << dbq2.front() << " ";
        dbq2.dequeue();
    }
    std::cout << std::endl;
    for (int x = 0; x < 10; ++x) {
        std::cout << dbq1.front() << " ";
        dbq1.dequeue();
    }
    std::cout << std::endl;


    // See if each loop prints the same (test of copy constructor)
    for (int x = 0; x < 10; ++x) {
        ItemType y = 2.2 * x;
        dbq1.enqueue(y);
    }
    // Might as well test size() here too
    if (dbq1.size() != 10) std::cout << "size() FAIL" << std::endl;
    DblQueue dbq3(dbq1);
    for (int x = 0; x < 10; ++x) {
        std::cout << dbq3.front() << " ";
        dbq3.dequeue();
    }
    std::cout << std::endl;
    for (int x = 0; x < 10; ++x) {
        std::cout << dbq1.front() << " ";
        dbq1.dequeue();
    }
    std::cout << std::endl;


    // isEmpty() test
    if (!dbq1.isEmpty()) std::cout << "isEmpty() FAIL" << std::endl;


    return 0;
}
