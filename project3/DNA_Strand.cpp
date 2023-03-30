// File name: DNA_Strand.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: February 23rd, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 3
// Description: This will be an DNA_Strand implemented with a linked list.


#include "DNA_Strand.h"
#include <stdexcept>
#include <cassert>

// Constructor
// Create an empty DNA_Strand.
DNA_Strand::DNA_Strand() : mySize(0), myDNA(nullptr) {}


// Constructor
// Create an initialized DNA_Strand.
// A linked list the size of ipStr will be created and initialized
// with the characters in ipStr
DNA_Strand::DNA_Strand(const std::string &ipStr) : mySize(0),
                                                   myDNA(nullptr)
{
    for (size_t x = ipStr.length() - 1; mySize <= x; ++mySize) {
        auto tmp(new DnaNode);
        tmp->val = ipStr[x - mySize];
        tmp->next = myDNA;
        myDNA = tmp;
    }
}


// The copy constructor. 
DNA_Strand::DNA_Strand(const DNA_Strand &rhs) : mySize(rhs.mySize),
                                                myDNA(nullptr)
{
    if (rhs.myDNA) {
        myDNA = new DnaNode;
        myDNA->val = rhs.myDNA->val;
        myDNA->next = nullptr;
        auto newPtr = myDNA;
        auto origPtr = rhs.myDNA;
        while (origPtr->next) {
            origPtr = origPtr->next;
            newPtr->next = new DnaNode;
            newPtr = newPtr->next;
            newPtr->val = origPtr->val;
            newPtr->next = nullptr;
        }
    }
}


// Destructor
// Clean up the DNA_Strand (e.g., delete dynamically allocated memory).
DNA_Strand::~DNA_Strand()
{
    while (myDNA) {
        auto tmp = myDNA;
        myDNA = myDNA->next;
        delete tmp;
    }

    mySize = 0;
}


// Assignment operator performs an assignment by making a copy of
// the contents of parameter <rhs>
const DNA_Strand & DNA_Strand::operator=(const DNA_Strand &rhs)
{
    if (this != &rhs) {
        DNA_Strand tmp(rhs);
        std::swap(myDNA, tmp.myDNA);
        std::swap(mySize, tmp.mySize);
    }

    return *this;
}


//toString
//Returns string equivalent of the DNA
std::string DNA_Strand::toString() const
{
    std::string tmpStr;
    for (DnaNodePtr cur = myDNA; cur != nullptr; cur = cur->next) {
        tmpStr += cur->val;
    }

    return tmpStr;
}


// Set an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
void DNA_Strand::set(char new_item, size_t index)
{
    if (inRange(index)) {
        DnaNodePtr cur = myDNA;
        for (size_t x = 0; x < index; ++x) {
            cur = cur->next;
        }

        cur->val = new_item;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// Get an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
char DNA_Strand::get(size_t index) const
{
    if (inRange(index)) {
        DnaNodePtr cur = myDNA;
        for (size_t x = 0; x < index; ++x) {
            cur = cur->next;
        }

        return cur->val;
    } else {
        throw std::out_of_range("Index out of range");
    }
}


// Returns the size of the DNA
size_t DNA_Strand::size() const {return mySize;}


// isEqual
// Compare this DNA_Strand with rhs for equality. Returns true if the
// size()'s of the two DNA_Strands are equal and all the elements of the
// linked list are equal, else false.
bool DNA_Strand::isEqual(const DNA_Strand &rhs) const
{
    if (size() == rhs.size()) {
        for (auto cur1 = myDNA, cur2 = rhs.myDNA; cur1; cur1 = cur1->next, cur2 = cur2->next) {
            if (cur1->val != cur2->val) {
                return false;
            }
        }

        return true;
    }

    return false;
}


// search
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(const std::string &target) const {return search((size_t)0, target);}

// search
// search with start position specified
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(size_t pos, const std::string &target) const
{
    auto cur = myDNA;
    if (pos < mySize) {
        for (size_t x = 0; x < pos; cur = cur->next, ++x);
    } else {
        return -1;
    }

    auto tmp = search(cur, target);
    if (tmp) {
        size_t last = mySize - target.length();
        for (; pos <= last; ++pos) {
            if (cur == tmp) {
                return (int) pos;
            }

            cur = cur->next;
        }
    }

    return -1;
}


// search with start position specified by a DnaNodePtr
// Look for target in current DNA strand and return a pointer to it
// Return nullptr if not found.
DnaNodePtr DNA_Strand::search(DnaNodePtr startPtr, const std::string &target) const
{
    auto cur = myDNA;
    int x = 0;
    for (; cur != startPtr && (size_t)x < mySize; cur = cur->next, ++x);

    if (cur) {
        int tLen = (int)target.length(), last = int(mySize - tLen);
        for (; x <= last; cur = cur->next, ++x) {
            auto tmp = cur;
            for (int y = 0; y < tLen; tmp = tmp->next, ++y) {
                if (tmp->val != target[y]) {
                    break;
                } else if (y == tLen - 1) {
                    return cur;
                }
            }
        }
    }

    return nullptr;
}


// cleave
// Removes from current DNA strand the sequence between the end of the 
// first occurrence of passed target sequence (e.g. "TTG"), through the end
// of the second occurence of the target sequence. 
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
// post: ACTTGA  (ACCTTG removed)
void DNA_Strand::cleave(const std::string &target) {cleave((size_t)0, target);}


// cleave with start position specified.
// Start position is specified as an index.
void DNA_Strand::cleave(size_t pos, const std::string &target)
{
    if (pos < mySize) {
        auto cur = myDNA;
        for (size_t x = 0; x < pos; cur = cur->next, ++x);
        cleave(cur, target);
    }
}


// cleave with start position specified.
// Start position is specified with a DnaNodePtr.
// If no cleave is performed, returns nullptr
// Otherwise, return pointer to next node after the cleave, ie,
//   returned ptr points to the node after the cleaved sequence (could be
//   nullptr if the cleaved sequence was at the end of the strand).
DnaNodePtr DNA_Strand::cleave(DnaNodePtr startPtr, const std::string &target)
{
    auto startCleavePtr = search(startPtr, target);
    if (startCleavePtr) {
        size_t x = 0;
        for (; x < target.length() - 1; startCleavePtr = startCleavePtr->next, ++x);
        auto endCleavePtr = search(startCleavePtr->next, target);
        if (endCleavePtr) {
            for (x = 0; x < target.length(); endCleavePtr = endCleavePtr->next, ++x);
            auto cur = startCleavePtr->next;
            for (x = 0; cur != endCleavePtr; ++x) {
                auto tmp = cur;
                cur = cur->next;
                delete tmp;
            }

            startCleavePtr->next = endCleavePtr;
            mySize -= x;
            return endCleavePtr;
        }
    }

    return nullptr;
}


// cleaveAll
// Removes from current DNA strand the sequence between pairs of target 
// sequence, i.e. from the end 1 through the end of 2, from the end of 3 
// through the end of 4, etc, but NOT from the end of 2 through the end 3,
// or from the end of 4 through the end of 5.
// (Make sure that you understand the specification)
// pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
// post: ACTTGGGTTGCC (ATTG and CTTG removed)
void DNA_Strand::cleaveAll(const std::string &target)
{
    auto cur = myDNA;
    do {
        cur = cleave(cur, target);
    } while (cur);
}


// countEnzyme
// Counts the number of occurences of a single character target sequence
// in the DNA strand.
size_t DNA_Strand::countEnzyme(char target) const
{
    size_t count = 0;
    auto cur = myDNA;
    for (size_t x = 0; x < mySize; cur = cur->next, ++x) {
        if (cur->val == target) {
            ++count;
        }
    }

    return count;
}

// countEnzyme -- overloaded
// string parameter version
// Counts non-overlapping instances of the target
// Eg, the target "AAA" appears 3 non-overlapping times in the DNA "AAAAAAAAA"
// Precondition: the target is a nonempty string.
size_t DNA_Strand::countEnzyme(const std::string &target) const
{
    int searchFind;
    size_t count = 0;
    size_t x = 0;
    do {
        searchFind = search(x, target);
        if (searchFind != -1) {
            ++count;
            x = (size_t)searchFind + target.length();
        }
    } while (searchFind != -1);

    return count;
}


// inRange : helper function
// Returns true if index is within range, i.e., 0 <= index < mySize 
// else returns false.
bool DNA_Strand::inRange(size_t index) const {return index < mySize;}


// append (accepting a string parameter)
// Append the characters of the parameter to the end of the current DNA.
// Example: if myDNA contained ACTTGA and "ACCTG" was received as a parameter, 
// then afterward myDNA will contain ACTTGAACCTG
void DNA_Strand::append(const std::string &rhs)
{
    auto cur = myDNA;
    for (size_t x = 0; x < mySize - 1; cur = cur->next, ++x);

    for (auto rh : rhs) {
        cur->next = new DnaNode;
        cur = cur->next;
        cur->val = rh;
    }

    cur->next = nullptr;
    mySize += rhs.length();
}

// append (accepting a DNA_Strand parameter)
// Append the characters of the parameter to the end of the current DNA.
// Example: if myDNA contained ACTTGA and ACCTG was received as a parameter, 
// then afterward myDNA will contain ACTTGAACCTG
void DNA_Strand::append(const DNA_Strand &rhs)
{
    append(rhs.toString());
}


// splice (accepts 2 Strings representing sequences)
// finds first pair of targets in current DNA strand and replaces
// the sequence between the end of the first target through the end of the 
// second with the insertSequence. 
// If two instances of the target are not found, 
// then no changes are made.
void DNA_Strand::splice(const std::string &target, const std::string &insertSequence)
{
    splice((size_t)0, target, insertSequence);
}


// splice (also accepting a starting location specified as an index)
void DNA_Strand::splice(size_t pos, const std::string &target,
                        const std::string &insertSequence)
{
    if (pos < mySize) {
        auto cur = myDNA;
        for (size_t x = 0; x < pos; cur = cur->next, ++x);
        splice(cur, target, insertSequence);
    }
}


// splice (also accepting a starting location specified with a DnaNodePtr)
// If no splice is performed, returns nullptr
// Otherwise, return a pointer to the next node after the inserted sequence
DnaNodePtr DNA_Strand::splice(DnaNodePtr startPtr, const std::string &target,
                              const std::string &insertSequence)
{
    auto startSplicePtr = search(startPtr, target);
    if (startSplicePtr) {
        size_t x = 0;
        for (; x < target.length() - 1; startSplicePtr = startSplicePtr->next, ++x);
        auto endSplicePtr = search(startSplicePtr->next, target);
        if (endSplicePtr) {
            for (x = 0; x < target.length(); endSplicePtr = endSplicePtr->next, ++x);
            auto cur = startSplicePtr->next;
            for (x = 0; cur != endSplicePtr; ++x) {
                auto tmp = cur;
                cur = cur->next;
                delete tmp;
            }

            for (auto c : insertSequence) {
                startSplicePtr->next = new DnaNode;
                startSplicePtr = startSplicePtr->next;
                startSplicePtr->val = c;
            }

            startSplicePtr->next = endSplicePtr;
            //avoid casting negative value to size_t
            mySize += insertSequence.length();
            mySize -= x;
            return endSplicePtr;
        }
    }

    return nullptr;
}


