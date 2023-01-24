// File name: DNAtest.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: January 24th, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 0
//
// Description: Testing of DNA_Strand ADT
//
//
// Last Changed: January 24th, 2023

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
        std::cout << "Test 6 FAIL. Two strands passed with "
                     "the same string were not equal." << std::endl;
    }

    if (!dna4.isEqual(dna3)) {
        std::cout << "Test 7 FAIL. The reflective test of "
                     "two strands passed with the same string also failed."
                  << std::endl;
    }


    //create a DNA whose amount of characters exceeds value of MAX_DNA
    std::string ipStr2(MAX_DNA + 1, 'A');
    DNA_Strand dna5(ipStr2);

    //Test that strands with parameters of different values are not equal
    if (dna5.isEqual(dna4)) {
        std::cout << "Test 8 FAIL. Two strands passed with different strings"
                  << " were equal." << std::endl;
    }
    if (dna4.isEqual(dna5)) {
        std::cout << "Test 9 FAIL. The reflective test of "
                     "two strands passed with different strings also failed."
                  << std::endl;
    }

    //Test toString() and size() to make sure DNA_Strand does not accept
    //more than MAX_DNA characters
    if (dna5.toString() == ipStr2) {
        std::cout << "Test 10 FAIL. Strand should not contain more than "
                     "MAX_DNA characters. Strand contains " << dna5.size()
                  << " characters upon test failure." << std::endl;
    }
    if (dna5.size() != MAX_DNA) {
        std::cout << "Test 11 FAIL. Strand passed with a string containing more "
                     "than MAX_DNA characters should only contain MAX_DNA "
                     "characters. Strand contains " << dna5.size() << " "
                     "characters upon test failure."
                  << std::endl;
    }


    //Test that get() throws exception when passed out-of-range index
    try {
        std::cout << "Expect an \"out_of_range\" exception" << std::endl;
        std::cout << "The 51st character of dna5 is: " << dna5.get(MAX_DNA)
                  << std::endl;
        std::cout << "Test 12 FAIL. \"out_of_range\" exception should be thrown."
                  << std::endl;
    }
    catch (std::out_of_range& excpt) {
        std::cout << "Exception for Test 12 was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  get() threw the wrong exception."
                  << std::endl;
    }


    ipStr2.resize(MAX_DNA + 10000, 'A');
    DNA_Strand dna6(ipStr2);
    //Test toString() and size() to make sure DNA_Strand does not accept
    //significantly more than MAX_DNA characters
    if (dna6.toString() == ipStr2) {
        std::cout << "Test 13 FAIL. Strand should not contain more than "
                     "MAX_DNA characters. Strand contains " << dna6.size()
                  << " characters upon test failure." << std::endl;
    }
    if (dna6.size() != MAX_DNA) {
        std::cout << "Test 14 FAIL. Strand passed with a string containing more "
                     "than MAX_DNA characters should only contain MAX_DNA "
                     "characters. Strand contains " << dna6.size() << "characters "
                     "upon test failure."
                  << std::endl;
    }

    try {
        std::cout << "Expect an \"out_of_range\" exception" << std::endl;
        std::cout << "The 10050th character of dna5 is: "
                  << dna5.get(MAX_DNA + 9999)
                  << std::endl;
        std::cout << "Test 15 FAIL. \"out_of_range\" exception should be thrown."
                  << std::endl;
    }
    catch (std::out_of_range& excpt) {
        std::cout << "Exception for Test 15 was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  get() threw the wrong exception."
                  << std::endl;
    }


    //Test toString() and size() for handling special characters
    ipStr2 = "&*)%^!$#@_+++++@$%!^&@(!3";
    DNA_Strand dna7(ipStr2);

    //toString should return the contents as a string
    if (dna7.toString() != ipStr2) {
        std::cout << "Test 16 FAIL. Expected: " << ipStr2
                  << " but received: " << dna7.toString() << std::endl;
    }

    if (dna7.size() != ipStr2.length()) {
        std::cout << "Test 17 FAIL. Expected: " << ipStr2.length()
                  << " but received: " << dna7.size() << std::endl;
    }


    //Test search() method
    DNA_Strand dna8("\\\\\\");
    bool failed = false;
    int failTrack = 0;
    for (size_t x = 0; x < dna8.size() && !failed; ++x) {
        if (dna8.search("\\") != 0) {
            std::cout << "Test 18 FAIL. Index of first occurrence of \"\\\" should"
                         " be 0." << std::endl;
            ++failTrack;
        }
        dna8.set('/', x);
        if (dna8.search("/") != (int) x) {
            std::cout << "Test 19 FAIL. Strand \"/\" should be at index " << x
                      << " but is instead at index " << dna8.search("/") << "."
                      << std::endl;
            ++failTrack;
        }
        if (dna8.get(x) != '/') {
            std::cout << "Test 20 FAIL. Character returned at index " << x
                      << " should be '/' but is instead " << dna8.get(x) << "."
                      << std::endl;
            ++failTrack;
        }
        if (failTrack != 0) {
            failed = true;
        }
        dna8.set('\\', x);
    }

    DNA_Strand dna9("AAAAAAA");
    bool failed2 = false;
    int failTrack2 = 0;
    for (size_t x = 0; x < dna9.size() && !failed2; ++x) {
        if (dna9.search("A") != 0) {
            std::cout << "Test 21 FAIL. Index of first occurrence of \"A\" should"
                         " be 0." << std::endl;
            ++failTrack2;
        }
        dna9.set('H', x);
        if (dna9.search("H") != (int) x) {
            std::cout << "Test 22 FAIL. Strand \"H\" should be at index " << x
                      << " but is instead at index " << dna9.search("H") << "."
                      << std::endl;
            ++failTrack2;
        }
        if (dna9.get(x) != 'H') {
            std::cout << "Test 23 FAIL. Character returned at index " << x
                      << " should be 'H' but is instead " << dna9.get(x) << "."
                      << std::endl;
            ++failTrack2;
        }
        if (failTrack2 != 0) {
            failed2 = true;
        }
        dna9.set('A', x);
    }
    if (dna9.search("O") != -1) {
        std::cout << "Test 24 FAIL. Expected -1 but received: "
                  << dna9.search("O") << std::endl;
    }


    DNA_Strand dna10;
    //testing set method with out-of-range index to assure exception is thrown
    try {
        dna10.set('A', MAX_DNA);
        std::cout << "Test 25 FAIL. \"out_of_range\" exception should be thrown."
                  << std::endl;
    }
    catch (std::out_of_range& excpt) {}
    catch (...) {
        std::cout << "EXCEPTION ERROR --  set() threw the wrong exception."
                  << std::endl;
    }


    //Similar to tests 10 and 13, but instead passed with a parameter that is not
    //longer than MAX_DNA
    std::string ipStr3 = "ABCDEABCDEFG";
    DNA_Strand dna11(ipStr3);
    try {
        std::cout << "Expect an \"out_of_range\" exception" << std::endl;
        std::cout << "The 13th character of dna11 is: "
                  << dna11.get(ipStr3.length()) << std::endl;
        std::cout << "Test 26 FAIL. \"out_of_range\" exception should be thrown."
                  << std::endl;
    }
    catch (std::out_of_range& excpt) {
        std::cout << "Exception for Test 26 was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  get() threw the wrong exception."
                  << std::endl;
    }

    //Test to detect first occurrence
    if (dna11.search("ABCDE") != 0) {
        std::cout << "Test 27 FAIL. Expected 0 but received: "
                  << dna11.search("ABCDE") << std::endl;
    }
    //Test to detect second occurrence at all indices where it should be
    //detectable
    bool failed3 = false;
    for (size_t x = 1; x < 6 && !failed3; ++x) {
        if (dna11.search(x, "ABCDE") != 5) {
            std::cout << "Test 28 FAIL. Expected 5 but received: "
                      << dna11.search(x, "ABCDE") << std::endl;
            failed3 = true;
        }
    }
    //Test to see that search() will not detect occurrence if occurrence begins
    //before specified index
    if (dna11.search(6, "ABCDE") != -1) {
        std::cout << "Test 29 FAIL. Expected -1 but received: "
                  << dna11.search(6, "ABCDE") << std::endl;
    }


    //Testing of cleave() method
    std::string ipStr4 = "ACTTGGGTTGCTTGCC";
    DNA_Strand dna12("ACTTGATTGGGTTGCTTGCC");
    DNA_Strand dna13(ipStr4);
    //Test with lowercase version of recurring string
    dna13.cleave("ttg");
    if (dna13.toString() != ipStr4) {
        std::cout << "Test 30 FAIL. Expected: " << ipStr4
                  << " but received: " << dna13.toString() << std::endl;
    }
    dna12.cleave("TTG");
    if (!dna12.isEqual(dna13)) {
        std::cout << "Test 31 FAIL. Cleaved dna12 is not equal to dna13 (a "
                     "sample strand that should mirror cleaved dna12)."
                  << std::endl;
    }
    if (dna12.toString() != ipStr4) {
        std::cout << "Test 32 FAIL. Expected: " << ipStr4
                  << " but received: " << dna12.toString() << std::endl;
    }

    std::string ipStr5 = "ABGABGDHTEU";
    DNA_Strand dna14(ipStr5);
    //Pass a string not found in ipStr5
    dna14.cleave("Z");
    if (dna14.toString() != ipStr5) {
        std::cout << "Test 33 FAIL. Expected: " << ipStr5
                  << " but received: " << dna14.toString() << std::endl;
    }
    //Pass a string that only occurs once in ipStr5
    dna14.cleave("BGD");
    if (dna14.toString() != ipStr5) {
        std::cout << "Test 34 FAIL. Expected: " << ipStr5
                  << " but received: " << dna14.toString() << std::endl;
    }
    //Pass a string that occurs twice, but consecutively
    dna14.cleave("ABG");
    if (dna14.toString() != "ABGDHTEU") {
        std::cout << "Test 35 FAIL. Expected: ABGDHTEU"
                  << " but received: " << dna14.toString() << std::endl;
    }
    //Test with only one occurrence, with same length as strand
    std::string ipStr6 = "TTG";
    DNA_Strand dna15(ipStr6), dna16(ipStr6);
    dna15.cleave("TTG");
    if (!dna15.isEqual(dna16)) {
        std::cout << "Test 36 FAIL. No cleaving should have been performed."
                  << std::endl;
    }
    //Special character tests
    std::string ipStr7 = "!@#)(*";
    DNA_Strand dna17("!@#$%*&^*!@#)(*");
    dna17.cleave("!@#");
    if (dna17.toString() != ipStr7) {
        std::cout << "Test 37 FAIL. Expected: " << ipStr7
                  << " but received: " << dna17.toString() << std::endl;
    }
    DNA_Strand dna18(ipStr7);
    if (!dna17.isEqual(dna18)) {
        std::cout << "Test 38 FAIL. Cleaved dna17 is not equal to dna18 (a "
                     "sample strand that should mirror cleaved dna17)."
                  << std::endl;
    }


    //Testing of cleave() method with specified start position
    std::string ipStr8 = "A@T!4AT!4GGT*";
    //Test with all positions where cleave() should return 5
    bool failed4 = false;
    int failTrack3 = 0;
    for (size_t x = 0; x < 3 && !failed4; ++x) {
        DNA_Strand dna19(ipStr8);
        if (dna19.cleave(x, "T!4") != 5) {
            std::cout << "Test 39 FAIL. Expected 5 but received: "
                      << dna19.cleave(x, "T!4") << std::endl;
            ++failTrack3;
        }
        if (dna19.toString() != "A@T!4GGT*") {
            std::cout << "Test 40 FAIL. Expected: A@T!4GGT* but "
                         "received: " << dna19.toString() << std::endl;
            ++failTrack3;
        }
        if (failTrack3 != 0) {
            failed4 = true;
        }
    }
    //Test with all positions in range where cleave() should return -1
    bool failed5 = false;
    int failTrack4 = 0;
    for (size_t x = 3; x < ipStr8.length() && !failed5; ++x) {
        DNA_Strand dna20(ipStr8);
        if (dna20.cleave(x, "T!4") != -1) {
            std::cout << "Test 41 FAIL. Expected -1 but received: "
                      << dna20.cleave(x, "T!4") << std::endl;
            ++failTrack4;
        }
        if (dna20.toString() != "A@T!4AT!4GGT*") {
            std::cout << "Test 42 FAIL. Expected: A@T!4AT!4GGT* but "
                         "received: " << dna20.toString() << std::endl;
            ++failTrack4;
        }
        if (failTrack4 != 0) {
            failed5 = true;
        }
    }
    //Test with out-of-range position, where cleave() should also return -1
    DNA_Strand dna21(ipStr8);
    if (dna21.cleave((size_t) ipStr8.length(), "T!4") != -1) {
        std::cout << "Test 43 FAIL. Expected -1 but received: "
                  << dna21.cleave((size_t) ipStr8.length(), "T!4")
                  << std::endl;
    }


    //Test cleaveAll() method
    std::string ipStr9 = "bC3@GA3@GGG3@GC3@G0C";
    std::string ipStr10 = "bC3@GGG3@G0C";
    DNA_Strand dna22(ipStr9);
    DNA_Strand dna23(ipStr10);
    //Test to assure method is case-sensitive
    dna23.cleaveAll("3@g");
    if (dna23.toString() != ipStr10) {
        std::cout << "Test 44 FAIL. Expected: " << ipStr10
                  << " but received: " << dna23.toString() << std::endl;
    }
    //Test that performed full cleavage alters strand to expected value
    dna22.cleaveAll("3@G");
    if (!dna22.isEqual(dna23)) {
        std::cout << "Test 45 FAIL. Fully cleaved dna12 is not equal to dna13 "
                     "(a sample strand that should mirror cleaved dna12)."
                  << std::endl;
    }
    if (dna22.toString() != ipStr10) {
        std::cout << "Test 46 FAIL. Expected: " << ipStr10
                  << " but received: " << dna22.toString() << std::endl;
    }
    dna23.cleaveAll("3@G");
    if (dna23.toString() != "bC3@G0C") {
        std::cout << "Test 47 FAIL. Expected: bC3@G0C"
                  << " but received: " << dna23.toString() << std::endl;
    }
    //Pass a string not found in ipStr9
    DNA_Strand dna24(ipStr9);
    dna24.cleaveAll("Z");
    if (dna24.toString() != ipStr9) {
        std::cout << "Test 48 FAIL. Expected: " << ipStr9
                  << " but received: " << dna24.toString() << std::endl;
    }
    //Pass a string that only occurs once in ipStr9
    dna24.cleaveAll("GGG3");
    if (dna24.toString() != ipStr9) {
        std::cout << "Test 49 FAIL. Expected: " << ipStr9
                  << " but received: " << dna24.toString() << std::endl;
    }
    //Pass a string that occurs twice, but consecutively
    DNA_Strand dna25("6&8eR8eR0_");
    dna25.cleave("8eR");
    if (dna25.toString() != "6&8eR0_") {
        std::cout << "Test 50 FAIL. Expected: 6&8eR0_"
                  << " but received: " << dna25.toString() << std::endl;
    }
    //Test with only one occurrence, with same length as strand
    std::string ipStr11 = "4$j";
    DNA_Strand dna26(ipStr11), dna27(ipStr11);
    dna26.cleaveAll("4$j");
    if (!dna26.isEqual(dna27)) {
        std::cout << "Test 51 FAIL. No cleaving should have been performed."
                  << std::endl;
    }


    //Test countEnzyme() method
    DNA_Strand dna28("GgGgGgGg8((___");
    if (dna28.countEnzyme('G') != 4) {
        std::cout << "Test 52 FAIL. Expected 4 but received: "
                  << dna28.countEnzyme('G') << std::endl;
    }
    if (dna28.countEnzyme('g') != 4) {
        std::cout << "Test 53 FAIL. Expected 4 but received: "
                  << dna28.countEnzyme('g') << std::endl;
    }
    if (dna28.countEnzyme('(') != 2) {
        std::cout << "Test 54 FAIL. Expected 2 but received: "
                  << dna28.countEnzyme('(') << std::endl;
    }
    if (dna28.countEnzyme('_') != 3) {
        std::cout << "Test 55 FAIL. Expected 3 but received: "
                  << dna28.countEnzyme('_') << std::endl;
    }
    if (dna28.countEnzyme('A') != 0) {
        std::cout << "Test 56 FAIL. Expected 0 but received: "
                  << dna28.countEnzyme('A') << std::endl;
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

