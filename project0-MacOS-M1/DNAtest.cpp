// File name: DNAtest.cpp
// Author:
// VUnetid:
// Email:
// Class: CS2201
// Date:
// Honor statement:
// Assignment Number:
//
// Description: Testing of DNA_Strand ADT
//
//
// Last Changed:

#include <iostream>
#include <stdexcept>
#include "DNA_Strand.h"


int main()
{
    // testing functions of the DNA_Strand class

    DNA_Strand dna1, dna2;  // create 2 default-constructed strands

    if (dna1.size() != 0) {
        std::cout << "Test 1 FAIL. Expected zero but received: " << dna1.size() << std::endl;
    }

    if (!dna1.isEqual(dna2)) {
        std::cout << "Test 2 FAIL. Two empty strands were not equal." << std::endl;
    }

    if (!dna2.isEqual(dna1)) {
        std::cout << "Test 3 FAIL. The reflective test of two empty strands also failed."
                  << std::endl;
    }


    // create a non-empty DNA
    std::string ipStr = "ABCCTG";
    DNA_Strand dna3(ipStr);   // create a alt-constructed strand

    //toString should return the contents as a string
    if (dna3.toString() != ipStr) {
        std::cout << "Test 4 FAIL. Expected: " << ipStr
                  << " but received: " << dna3.toString() << std::endl;
    }

    if (dna3.size() != ipStr.length()) {
        std::cout << "Test 5 FAIL. Expected: " << ipStr.length()
                  << " but received: " << dna3.size() << std::endl;
    }


    DNA_Strand dna4(ipStr); //alt-constructed DNA_Strand object with same parameter
                            //as dna3

    if (!dna3.isEqual(dna4)) {
        std::cout << "Test 6 FAIL. Two strands passed with the same string "
                     "were not equal." << std::endl;
    }

    if (!dna4.isEqual(dna3)) {
        std::cout << "Test 7 FAIL. The reflective test of two strands passed "
                     "with the same string also failed." << std::endl;
    }

    //test different string lengths that exceed MAX_DNA
    bool failed = false;
    for (size_t y = 1, x = 1; y <= 10 && !failed; ++y, x = x * 2) {
        //create a DNA whose amount of characters exceeds value of MAX_DNA
        std::string ipStr2;
        for (size_t z = 0; z < MAX_DNA + x; ++z) {
            ipStr2.push_back('A');
        }
        DNA_Strand dna5(ipStr2);

        //toString should return the contents as a string, but without ipStr2's
        //last 2 characters
        if (dna5.toString() == ipStr2) {
            std::cout << "Test 8." << y << " FAIL. Strand should not contain more than "
                         "MAX_DNA characters. Strand contains " << dna5.size()
                      << " characters upon test failure." << std::endl;
        }

        if (dna5.size() != MAX_DNA) {
            std::cout << "Test 9." << y << " FAIL. Strand passed with a string containing more "
                         "than MAX_DNA characters should only contain MAX_DNA "
                         "characters. Strand contains " << dna5.size() << " "
                         "characters upon test failure."
                      << std::endl;
            failed = true;
        }
    }

    DNA_Strand dna6("AAAAAAA");
    for (size_t x = 0; x < dna6.size(); ++x) {
        if (dna6.search("A") != 0) {
            
        }
        dna6.set('H', x);
        if (dna6.search("H") != (int) x) {
            std::cout << "Test 11 FAIL. Strand at index " << x << " should be 'H'."
            << std::endl;
        }
        dna6.set('A', x);
    }


    // here is how you can test to make sure exceptions are correctly thrown
    try {
        std::cout << "Expect an \"out_of_range\" exception" << std::endl;
        // The following statement should throw an exception
        std::cout << "The 20th character of dna3 is: " << dna3.get(19)
                  << std::endl;
        std::cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE"
                  << std::endl;
    }
    catch (std::out_of_range& excpt) {
        std::cout << "Exception was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  get() threw the wrong exception."
                  << std::endl;
    }


// uncomment the following lines if you are running the program in a
// DOS or terminal window and you want the window to stay open when
// the testing is done.
//    std::cout << "Done testing" << std::endl;
//    std::cout << "Press enter to end pgm" << std::endl;
//    char tt;
//    tt = cin.get();


    return 0;
}

