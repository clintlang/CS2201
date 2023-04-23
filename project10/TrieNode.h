// File name: TrieNode.h
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: April 24th, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 10
// Description: This declares the structure of a node of our trie.

#ifndef TRIENODE_H
#define TRIENODE_H

#include <string>


const size_t NUM_LETTERS = 26;

class TrieNode
{
    TrieNode* nodes[NUM_LETTERS];

    bool isEnd;

    size_t count;

public:
    // Class Constructor. Takes a character for the node, and a bool
    // indicating whether it represents the end of a word. Note, there is no
    // default ctor
    TrieNode(const std::string& str);

    // Copy Constructor
    TrieNode(const TrieNode& rhs);

    // Destructor
    ~TrieNode();

    // Copy Assignment Operator
    const TrieNode& operator= (const TrieNode& rhs);

    // Insert str starting with the given TrieNode. Create new TrieNodes
    // as needed and be sure to set the boolean flag on the last node to true
    void insert(const std::string& str);

    // Returns true if str is in the sub-Trie starting at the given TrieNode,
    // else returns false
    bool isWord(const std::string& str) const;

    // Returns true if pre is a prefix of a word in the sub-Trie starting at
    // the given TrieNode, else returns false
    bool isPrefix(const std::string& pre) const;

    // Prints all words starting at the given TrieNode. The parameter
    // string str stores the letters of all previous TrieNode objects up to
    // the node currently being processed
    void print(const std::string& str) const;

    // Returns a count all the nodes in the sub-Trie that end a word
    size_t wordCount() const;
};

#endif
