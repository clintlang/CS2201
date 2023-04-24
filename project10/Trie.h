// File name: Trie.h
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: April 17th, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 9
// Description: This declares the structure of our trie.

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <cstddef>
#include "TrieNode.h"

class Trie
{
    TrieNode myRoot;

    size_t count;

public:
    // Default Constructor
    Trie();

    // Insert the parameter word into the Trie
    void insert(const std::string& word);

    // Insert all words in the specified file into the Trie. Throws a
    // std::invalid_argument exception if the specified file cannot be
    // opened
    void loadFromFile(const std::string& filename);

    // Returns true if word is in the Trie, else returns false
    bool isWord(const std::string& word) const;

    // Returns true if pre is a prefix of a word in the Trie, else returns false
    bool isPrefix(const std::string& pre) const;

    // Print all words in the Trie, one per line. Print in alphabetical order
    void print() const;

    // Returns a count all the words in the Trie
    size_t wordCount() const;
};


#endif
