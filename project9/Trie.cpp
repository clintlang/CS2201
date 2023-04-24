// File name: Trie.h
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: April 17th, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 9
// Description: This defines the structure of our trie.

#include "Trie.h"
#include <string>
#include <cstddef>
#include <fstream>


// Default Constructor
Trie::Trie() : myRoot(""), count(0) {}


// Insert the parameter word into the Trie
void Trie::insert(const std::string& word)
{
    if (!word.empty() && myRoot.insert(word))
        ++count;
}


// Insert all words in the specified file into the Trie. Throws a
// std::invalid_argument exception if the specified file cannot be
// opened
void Trie::loadFromFile(const std::string& filename)
{
    std::ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail())
        throw std::invalid_argument("Error opening input data file");

    std::string word;
    while (infile >> word)
        insert(word);
}


// Returns true if word is in the Trie, else returns false
bool Trie::isWord(const std::string& word) const
{
    if (!word.empty())
        return myRoot.isWord(word);

    return false;
}


// Returns true if pre is a prefix of a word in the Trie, else returns false
bool Trie::isPrefix(const std::string& pre) const
{
    if (!pre.empty())
        return myRoot.isPrefix(pre);

    return true;
}


// Print all words in the Trie, one per line. Print in alphabetical order
void Trie::print() const
{
    myRoot.print("");
}


// Returns a count all the words in the Trie
size_t Trie::wordCount() const {return count;}