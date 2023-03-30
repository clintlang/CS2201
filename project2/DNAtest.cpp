// File name: DNAtest.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: Valentine's Day, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 2
//
// Description: Testing of DNA_Strand ADT
//
//   add MORE TESTS OF YOUR OWN!!!
//
// Last Changed: Valentine's Day, 2023

#include <iostream>
#include <stdexcept>
#include "DNA_Strand.h"

int main ()
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


    //create a DNA whose amount of characters exceeds value of DEFAULT_DNA_SIZE
    std::string ipStr2(DEFAULT_DNA_SIZE + 1, 'A');
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
    //more than DEFAULT_DNA_SIZE characters
//    if (dna5.toString() == ipStr2) {
//        std::cout << "Test 10 FAIL. Strand should not contain more than "
//                     "DEFAULT_DNA_SIZE characters. Strand contains " << dna5.size()
//                  << " characters upon test failure." << std::endl;
//    }
//    if (dna5.size() != DEFAULT_DNA_SIZE) {
//        std::cout << "Test 11 FAIL. Strand passed with a string containing more "
//                     "than DEFAULT_DNA_SIZE characters should only contain DEFAULT_DNA_SIZE "
//                     "characters. Strand contains " << dna5.size() << " "
//                                                                      "characters upon test failure."
//                  << std::endl;
//    }


    //Test that get() throws exception when passed out-of-range index
//    try {
//        std::cout << "Expect an \"out_of_range\" exception" << std::endl;
//        std::cout << "The 51st character of dna5 is: " << dna5.get(DEFAULT_DNA_SIZE)
//                  << std::endl;
//        std::cout << "Test 12 FAIL. \"out_of_range\" exception should be thrown."
//                  << std::endl;
//    }
//    catch (std::out_of_range& excpt) {
//        std::cout << "Exception for Test 12 was properly thrown and caught :: "
//                  << excpt.what() << std::endl;
//    }
//    catch (...) {
//        std::cout << "EXCEPTION ERROR --  get() threw the wrong exception."
//                  << std::endl;
//    }


//    ipStr2.resize(DEFAULT_DNA_SIZE + 10000, 'A');
//    DNA_Strand dna6(ipStr2);
//    //Test toString() and size() to make sure DNA_Strand does not accept
//    //significantly more than DEFAULT_DNA_SIZE characters
//    if (dna6.toString() == ipStr2) {
//        std::cout << "Test 13 FAIL. Strand should not contain more than "
//                     "DEFAULT_DNA_SIZE characters. Strand contains " << dna6.size()
//                  << " characters upon test failure." << std::endl;
//    }
//    if (dna6.size() != DEFAULT_DNA_SIZE) {
//        std::cout << "Test 14 FAIL. Strand passed with a string containing more "
//                     "than DEFAULT_DNA_SIZE characters should only contain DEFAULT_DNA_SIZE "
//                     "characters. Strand contains " << dna6.size() << "characters "
//                                                                      "upon test failure."
//                  << std::endl;
//    }

    try {
        std::cout << "Expect an \"out_of_range\" exception" << std::endl;
        std::cout << "The 10050th character of dna5 is: "
                  << dna5.get(DEFAULT_DNA_SIZE + 9999)
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
    DNA_Strand dna8(R"(\\\)");
    bool failed = false;
    for (size_t x = 0; x < dna8.size() && !failed; ++x) {
        if (dna8.search("\\") != 0) {
            std::cout << "Test 18 FAIL. Index of first occurrence of \"\\\" should"
                         " be 0." << std::endl;
            failed = true;
        }
        dna8.set('/', x);
        if (dna8.search("/") != (int) x) {
            std::cout << "Test 19 FAIL. Strand \"/\" should be at index " << x
                      << " but is instead at index " << dna8.search("/") << "."
                      << std::endl;
            failed = true;
        }
        if (dna8.get(x) != '/') {
            std::cout << "Test 20 FAIL. Character returned at index " << x
                      << " should be '/' but is instead " << dna8.get(x) << "."
                      << std::endl;
            failed = true;
        }
        dna8.set('\\', x);
    }

    //Stress test calling get() and set() 10000 times
    DNA_Strand dna9("AAAAAAA");
    failed = false;
    int result;
    for (size_t x = 0; x < 10000 && !failed; ++x) {
        auto mod = x % dna9.size();
        result = dna9.search("A");
        if (result != 0) {
            std::cout << "Test 21 FAIL. Index of first occurrence of \"A\" should"
                         " be 0." << std::endl;
            failed = true;
        }
        dna9.set('H', mod);
        if ((result = dna9.search("H")) != (int)mod) {
            std::cout << "Test 22 FAIL. Strand \"H\" should be at index " << x
                      << " but is instead at index " << result << "."
                      << std::endl;
            failed = true;
        }
        if ((result = dna9.get(mod)) != 'H') {
            std::cout << "Test 23 FAIL. Character returned at index " << x
                      << " should be 'H' but is instead " << (char)result << "."
                      << std::endl;
            failed = true;
        }
        dna9.set('A', mod);
    }
    if (dna9.search("O") != -1) {
        std::cout << "Test 24 FAIL. Expected -1 but received: "
                  << dna9.search("O") << std::endl;
    }


    DNA_Strand dna10;
    //testing set method with out-of-range index to assure exception is thrown
    try {
        dna10.set('A', DEFAULT_DNA_SIZE);
        std::cout << "Test 25 FAIL. \"out_of_range\" exception should be thrown."
                  << std::endl;
    }
    catch (std::out_of_range& excpt) {}
    catch (...) {
        std::cout << "EXCEPTION ERROR --  set() threw the wrong exception."
                  << std::endl;
    }


    //Similar to tests 10 and 13, but instead passed with a parameter that is not
    //longer than DEFAULT_DNA_SIZE
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
    failed = false;
    for (size_t x = 1; x < 6 && !failed; ++x) {
        if (dna11.search(x, "ABCDE") != 5) {
            std::cout << "Test 28 FAIL. Expected 5 but received: "
                      << dna11.search(x, "ABCDE") << std::endl;
            failed = true;
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
    failed = false;
    for (size_t x = 0; x < 3 && !failed; ++x) {
        DNA_Strand dna19(ipStr8);
        if (dna19.cleave(x, "T!4") != 5) {
            std::cout << "Test 39 FAIL. Expected 5 but received: "
                      << dna19.cleave(x, "T!4") << std::endl;
            failed = true;
        }
        if (dna19.toString() != "A@T!4GGT*") {
            std::cout << "Test 40 FAIL. Expected: A@T!4GGT* but "
                         "received: " << dna19.toString() << std::endl;
            failed = true;
        }
    }
    //Test with all positions in range where cleave() should return -1
    failed = false;
    for (size_t x = 3; x < ipStr8.length() && !failed; ++x) {
        DNA_Strand dna20(ipStr8);
        if (dna20.cleave(x, "T!4") != -1) {
            std::cout << "Test 41 FAIL. Expected -1 but received: "
                      << dna20.cleave(x, "T!4") << std::endl;
            failed = true;
        }
        if (dna20.toString() != "A@T!4AT!4GGT*") {
            std::cout << "Test 42 FAIL. Expected: A@T!4AT!4GGT* but "
                         "received: " << dna20.toString() << std::endl;
            failed = true;
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


    //Test methods not yet tested with default constructed strand
    std::string ipStr12;
    if (dna1.toString() != ipStr12) {
        std::cout << "Test 57 FAIL. Expected string with no characters but "
                     "received: " << dna1.toString() << std::endl;
    }
    //We previously used an index greater than DEFAULT_DNA_SIZE, now let's try all possible
    //indices less than DEFAULT_DNA_SIZE
    failed = false;
    for (size_t x = 0; x < DEFAULT_DNA_SIZE && !failed; ++x) {
        try {
            dna1.set('A', x);
            std::cout << "Test 58 FAIL. \"out_of_range\" exception should be thrown."
                      << std::endl;
            failed = true;
        }
        catch (std::out_of_range &excpt) {}
        catch (...) {
            std::cout << "EXCEPTION ERROR --  set() threw the wrong exception."
                      << std::endl;
            failed = true;
        }
    }
    //Test search()
    if (dna1.search("A") != -1) {
        std::cout << "Test 59 FAIL. Expected -1 but received: "
                  << dna1.search("A") << std::endl;
    }
    if (dna1.search("") != -1) {
        std::cout << "Test 60 FAIL. Expected -1 but received: "
                  << dna1.search("") << std::endl;
    }
    failed = false;
    for (size_t x = 0; (x < DEFAULT_DNA_SIZE * 2) && !failed; ++x) {
        if (dna1.search(x, "B") != -1) {
            std::cout << "Test 61 FAIL. Expected -1 but received: "
                      << dna1.search(x, "B") << std::endl;
            failed = true;
        }
        if (dna1.search(x, "") != -1) {
            std::cout << "Test 62 FAIL. Expected -1 but received: "
                      << dna1.search(x, "") << std::endl;
            failed = true;
        }
        //Testing cleave() with specified position
        if (dna1.cleave(x, "C") != -1) {
            std::cout << "Test 63 FAIL. Expected -1 but received: "
                      << dna1.cleave(x, "C") << std::endl;
            failed = true;
        }
        if (dna1.cleave(x, "") != -1) {
            std::cout << "Test 64 FAIL. Expected -1 but received: "
                      << dna1.cleave(x, "") << std::endl;
            failed = true;
        }
    }
    //Test cleaveAll() and cleave() without specified start position
    dna1.cleave("ABC");
    if (dna1.toString() != ipStr12) {
        std::cout << "Test 65 FAIL. Expected string with no characters but "
                     "received: " << dna1.toString() << std::endl;
    }
    dna2.cleaveAll("");
    if (dna2.toString() != "") {
        std::cout << "Test 66 FAIL. Expected string with no characters but "
                     "received: " << dna2.toString() << std::endl;
    }
    dna1.cleave("");
    if (dna1.toString() != "") {
        std::cout << "Test 67 FAIL. Expected string with no characters but "
                     "received: " << dna1.toString() << std::endl;
    }
    dna2.cleaveAll("ABC");
    if (dna2.toString() != "") {
        std::cout << "Test 68 FAIL. Expected string with no characters but "
                     "received: " << dna2.toString() << std::endl;
    }
    if (!dna1.isEqual(dna2)) {
        std::cout << "Test 69 FAIL. No cleaving should be done, so strands "
                     "both initialized with default constructor should be "
                     "equal" << std::endl;
    }
    //Test countEnzyme() method
    if (dna1.countEnzyme('Z') != 0) {
        std::cout << " Test 70 FAIL. Expected o but received: "
                  << dna1.countEnzyme('Z') << std::endl;
    }
    if (dna1.countEnzyme(' ') != 0) {
        std::cout << " Test 71 FAIL. Expected o but received: "
                  << dna1.countEnzyme(' ') << std::endl;
    }


    //Test was added after first grading of assignment
    //Final test of isEqual() with DNA_Strand of same length but
    //different contents
    DNA_Strand dna29("AAAA");
    DNA_Strand dna30("BBBB");
    if (dna29.isEqual(dna30)) {
        std::cout << "Test 72 FAIL. Strands with same length but with different "
                     "strings passed should not be equal." << std::endl;
    }
    if (dna30.isEqual(dna29)) {
        std::cout << "Test 73 FAIL. Reflective test of strands with same length "
                     "but with different strings passed should not return equal."
                  << std::endl;
    }


    //Test newly added countEnzyme() with string parameter
    DNA_Strand dna31("AAAAAAAAAAA");
    if (dna31.countEnzyme("AAA") != 3) {
        std::cout << "Test 74 FAIL. Expected 3 but received: "
                  << dna31.countEnzyme("AAA") << std::endl;
    }
    DNA_Strand dna32("AAAAAAAAAAAA");
    if (dna32.countEnzyme("AAA") != 4) {
        std::cout << "Test 75 FAIL. Expected 4 but received: "
                  << dna32.countEnzyme("AAA") << std::endl;
    }

    //Test grow()
    DNA_Strand dna33(5);
    dna33.grow(3);
    if (dna33.maxSize() != 5) {
        std::cout << "test 76 FAIL. Expected 5 but received: "
                  << dna33.maxSize() << std::endl;
    }
    dna33.grow(6);
    if (dna33.maxSize() != 6) {
        std::cout << "test 77 FAIL. Expected 6 but received: "
                  << dna33.maxSize() << std::endl;
    }

    //Test append() with both parameter types
    DNA_Strand dna34("ACTTGA");
    dna34.append("ACCTG");
    if (dna34.toString() != "ACTTGAACCTG") {
        std::cout << "Test 78 FAIL. append() did not make "
                     "desired changes." << std::endl;
    }
    DNA_Strand dna35("ACTTGA");
    DNA_Strand dna36("ACCTG");
    dna35.append(dna36);
    if (!dna35.isEqual(dna34)) {
        std::cout << "Test 79 FAIL. After append() is called, "
                     "both strands should be equal." << std::endl;
    }

    //Testing splice() methods
    DNA_Strand dna37("ACTTGCACATTGABRTTGHYU");
    dna37.splice("TTG", "splice");
    if (dna37.toString() != "ACTTGspliceABRTTGHYU") {
        std::cout << "Test 80 FAIL. splice() did not make "
                     "desired changes." << std::endl;
    }
    DNA_Strand dna38("ACTTGCACATTGABRTTGHYU");
    dna38.splice(3, "TTG", "splice");
    if (dna38.toString() != "ACTTGCACATTGspliceHYU") {
        std::cout << "Test 81 FAIL. splice() did not make "
                     "desired changes." << std::endl;
    }

    //testing constructors
    DNA_Strand dna39;
    if (dna39.maxSize() != DEFAULT_DNA_SIZE) {
        std::cout << "Test 82 FAIL. Default constructed strand "
                     "is not correct size." << std::endl;
    }
    DNA_Strand dna40(80);
    if (dna40.maxSize() != 80) {
        std::cout << "Test 82 FAIL. Size constructed strand "
                     "is not specified size." << std::endl;
    }
    DNA_Strand dna41(dna40);
    if (!dna41.isEqual(dna40)) {
        std::cout << "Test 83 FAIL. Copy constructor "
                     "should make equal strands" << std::endl;
    }
    DNA_Strand dna44("jagsvdt");
    DNA_Strand dna45(dna44);
    if (!dna44.isEqual(dna45)) {
        std::cout << "Test 84 FAIL. Copy constructor "
                     "should make equal strands" << std::endl;
    }

    //Test copy assignment operator
    DNA_Strand dna42("jagsvdt");
    DNA_Strand dna43("ghnkip");
    dna42 = dna43;
    if (!dna42.isEqual(dna43)) {
        std::cout << "Test 84 FAIL. Copy assignment operator "
                     "should make equal strands" << std::endl;
    }


    // Here's an example of how to test the destructor. You can use a similar strategy
    // to test for other memory issues.
    // Uncomment the follow block of code when you are ready to test the destructor.
    std::string big(10000, 'a');
    std::cout << "Testing the destructor. Watch the memory usage of your computer." << std::endl;
    for (size_t i=0; i<100000; ++i) {
        DNA_Strand* bigStrand(new DNA_Strand(big));  // make a big strand object
        if (i%1000==0) {
            bigStrand->set('b',0);
            std::cout << '.' << std::flush;
            //Added the flush just so I could see it in real time
        }
        delete bigStrand;     // now delete it
    }
    std::cout << std::endl;


    std::cout << "Done testing" << std::endl;

	return 0;
}
