// File name: TrieNode.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: April 17th, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 9
// Description: This defines the structure of a node of our trie.

#include "TrieNode.h"
#include <string>
#include <iostream>


// Class Constructor. Takes a character for the node, and a bool
// indicating whether it represents the end of a word. Note, there is no
// default ctor
TrieNode::TrieNode(const std::string& str) : nodes(), isEnd(false)
{
    insert(str);
}


// Copy Constructor
TrieNode::TrieNode(const TrieNode& rhs) : nodes(), isEnd(rhs.isEnd)
{
    for (size_t x = 0; x < NUM_LETTERS; ++x) {
        if (rhs.nodes[x])
            nodes[x] = new TrieNode(*rhs.nodes[x]);
    }
}


// Destructor
TrieNode::~TrieNode()
{
    for (auto& node : nodes)
        delete node;
}


// Copy Assignment Operator
const TrieNode& TrieNode::operator= (const TrieNode& rhs)
{
    if (&rhs != this) {
        TrieNode tmp(rhs);
        for (size_t x = 0; x < NUM_LETTERS; ++x) {
            std::swap(nodes[x], tmp.nodes[x]);
        }

        std::swap(this->isEnd, tmp.isEnd);
    }

    return *this;
}


// Insert str starting with the given TrieNode. Create new TrieNodes
// as needed and be sure to set the boolean flag on the last node to true
bool TrieNode::insert(const std::string& str)
{
    bool res = true;

    if (str.empty()) {
        if (isEnd)
            res = false;
        else
            isEnd = true;
    } else {
        auto idx = str[0] - 'a';
        if (!nodes[idx])
            nodes[idx] = new TrieNode(str.substr(1));
        else
            res = nodes[idx]->insert(str.substr(1));
    }

    return res;
}


// Returns true if str is in the sub-Trie starting at the given TrieNode,
// else returns false
bool TrieNode::isWord(const std::string& str) const
{
    if (str.empty())
        return isEnd;

    auto idx = str[0] - 'a';
    return nodes[idx] && nodes[idx]->isWord(str.substr(1));
}


// Returns true if pre is a prefix of a word in the sub-Trie starting at
// the given TrieNode, else returns false
bool TrieNode::isPrefix(const std::string& pre) const
{
    if (pre.empty())
        return true;

    auto idx = pre[0] - 'a';
    return nodes[idx] && nodes[idx]->isPrefix(pre.substr(1));
}


// Prints all words starting at the given TrieNode. The parameter
// string str stores the letters of all previous TrieNode objects up to
// the node currently being processed
void TrieNode::print(const std::string& str) const
{
    if (isEnd && !str.empty())
        std::cout << str << std::endl;

    for (size_t x = 0; x < NUM_LETTERS; ++x) {
        if (nodes[x])
            nodes[x]->print(str + char(x + 'a'));
    }
}
