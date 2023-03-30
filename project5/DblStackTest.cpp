// Name: Clinton Lang
// Email: clinton.t.lang@vanderbilt.edu
// VUnetid: langct
// Class: CS 2201
// Date: March 20th, 2023
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Description: This program tests the DblStack class.

#include <iostream>
#include <string>
#include <cstdlib>
#include "DblStack.h"

int main()
{
    // Test underflow_error
    DblStack dbs1;
    try {
        std::cout << "Expect an \"underflow_error\" exception" << std::endl;
        std::cout << "The top of dbs1 is: " << dbs1.top() << std::endl;
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
        dbs1.pop();
        std::cout << "Test 2 FAIL. \"underflow_error\" exception should be thrown."
                  << std::endl;
    }
    catch (std::underflow_error& excpt) {
        std::cout << "Exception for Test 2 was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  top() threw the wrong exception." << std::endl;
    }


    // See if each loop prints the same (test of copy assignment operator)
    for (int x = 0; x < 10; ++x) {
        ItemType y = 2.1 * x;
        dbs1.push(y);
    }
    DblStack dbs2 = dbs1;
    for (int x = 0; x < 10; ++x) {
        std::cout << dbs2.top() << " ";
        dbs2.pop();
    }
    std::cout << std::endl;
    for (int x = 0; x < 10; ++x) {
        std::cout << dbs1.top() << " ";
        dbs1.pop();
    }
    std::cout << std::endl;


    // See if each loop prints the same (test of copy constructor)
    for (int x = 0; x < 10; ++x) {
        ItemType y = 2.2 * x;
        dbs1.push(y);
    }
    // Might as well test size() here too
    if (dbs1.size() != 10) std::cout << "size() FAIL" << std::endl;
    DblStack dbs3(dbs1);
    for (int x = 0; x < 10; ++x) {
        std::cout << dbs3.top() << " ";
        dbs3.pop();
    }
    std::cout << std::endl;
    for (int x = 0; x < 10; ++x) {
        std::cout << dbs1.top() << " ";
        dbs1.pop();
    }
    std::cout << std::endl;


    // isEmpty() test
    if (!dbs1.isEmpty()) std::cout << "isEmpty() FAIL" << std::endl;


    return 0;
}