// File name: project9.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: April 17th, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 9
// Description: This tests our trie.

#include <iostream>
#include "Trie.h"

int main() {
    // Testing default constructed trie with loadFromFile() called on it
    std::cout << "\nTesting default constructed trie with "
                 "loadFromFile() called on it" << std::endl;
    Trie words;
    words.loadFromFile("words.txt");
    words.print();

    if (!words.isPrefix("breading"))
        std::cout << "FAIL #1" << std::endl;
    if (words.isPrefix("breadinglyg"))
        std::cout << "FAIL #2" << std::endl;
    if (!words.isPrefix(""))
        std::cout << "FAIL #3" << std::endl;
    if (words.isPrefix("v"))
        std::cout << "FAIL #4" << std::endl;
    if (!words.isPrefix("brea"))
        std::cout << "FAIL #5" << std::endl;
    if (words.isPrefix("rea"))
        std::cout << "FAIL #6" << std::endl;

    if (words.isWord("brea"))
        std::cout << "FAIL #7" << std::endl;
    if (!words.isWord("bread"))
        std::cout << "FAIL #8" << std::endl;
    if (words.isWord(""))
        std::cout << "FAIL #9" << std::endl;

    if (words.wordCount() != 10)
        std::cout << "FAIL #10, count is: " << words.wordCount() << std::endl;


    // Test "invalid_argument" exception for loadFromFile
    try {
        std::cout << "\nExpect an \"invalid_argument\" exception" << std::endl;
        words.loadFromFile("bruh");
        std::cout << "FAIL #11. \"invalid_argument\" exception should be thrown."
                  << std::endl;
    }
    catch (std::invalid_argument& invalid_argument) {
        std::cout << "Exception for Test #11 was properly thrown and caught:)"
                  << std::endl;
    }
    catch (...) {
        std::cout << "FAIL #12. EXCEPTION ERROR -- loadFromFile() threw the wrong exception."
                  << std::endl;
    }


    // Testing copy constructor
    std::cout << "\nTesting copy constructor. "
                 "Output should resemble exactly the first output" << std::endl;
    Trie words1(words);
    words1.print();


    // Testing copy assignment operator
    std::cout << "\nTesting copy assignment operator. "
                 "Output should resemble exactly the first output" << std::endl;
    Trie words2;
    words2 = words1;
    words2.print();


    // Testing insert(). Output should resemble exactly the first output,
    // but with the word "bronze" printed in between "bromine" and "brown"
    std::cout << "\nTesting insert(). Output should resemble exactly the first "
                 "output, but with the word \"bronze\" printed in between \"bromine\" "
                 "and \"brown\"" << std::endl;
    words.insert("bronze");
    words.print();


    // Testing that duplicates do not get added or increase count
    std::cout << "\nTesting that duplicates do not get "
                 "added or increase count" << std::endl;
    words.insert("brown");
    words.print();
    if (words.wordCount() != 11)
        std::cout << "FAIL #13, count is: " << words.wordCount() << std::endl;


    std::cout << "\nDone testing!" << std::endl;

    return 0;
}
