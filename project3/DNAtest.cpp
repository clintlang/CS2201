// File name: 
// Author: 
// Userid: 
// Email: 
// Class: 
// 
// Description: Testing of DNA_Strand ADT
//
//   add MORE TESTS OF YOUR OWN!!!
//
// Last Changed: 

#include <iostream>
#include "DNA_Strand.h"


int main() {

    DNA_Strand dna1;

    if (dna1.size() != 0)
        std::cout << "Test 1 FAIL" << std::endl;
    if (dna1.toString() != "")
        std::cout << "Test 2 FAIL" << std::endl;

    DNA_Strand dna2("actggtca");
    if (dna2.size() != 8)
        std::cout << "Test 3 FAIL" << std::endl;
    if (dna2.toString() != "actggtca")
        std::cout << "Test 4 FAIL" << std::endl;


    // add your own tests here.
    // be sure to test all methods thoroughly.
    // have you thought about "edge conditions"?


    // Here's an example of how to test the destructor. You can use a similar strategy
    // to test for other memory issues.
    // Uncomment the follow block of code when you are ready to test the destructor.
//    std::string big("aaaaaaaaaa");
//    for (size_t j=0; j<15; ++j) {
//        big = big+big;  // double big on each iteration... exponential growth
//    }
//
//    std::cout << "Testing the destructor. Watch the memory usage of your computer." << std::endl;
//    for (size_t i=0; i<2000; ++i) {
//        DNA_Strand* bigStrand(new DNA_Strand(big));  // make a big strand object
//        if (i%10==0) {
//            bigStrand->set('b',0);
//            std::cout << '.' << std::flush;
//        }
//        delete bigStrand;     // now delete it
//    }
//    std::cout << std::endl;


    std::cout << "Done testing" << std::endl;
//    std::cout << "Press enter to end pgm" << std::endl;
//    char tt;
//    tt = std::cin.get();


    return 0;
}
