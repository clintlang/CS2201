// File name: DNA_Strand.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: February 1st, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 1
// Description: This will be an DNA_Strand implemented with a static 
//              array of chars.


#include "DNA_Strand.h"
#include <stdexcept>

// Constructor
// Create an empty DNA_Strand.
DNA_Strand::DNA_Strand () : mySize(0) {}


// Constructor
// Create an initialized DNA_Strand.
// If the string ipStr is larger than MAX_DNA, then only the first MAX_DNA
// characters of ipStr are used to initialize the DNA_Strand
DNA_Strand::DNA_Strand (const std::string & ipStr)
{
    for (mySize = 0; mySize < ipStr.length() && mySize < MAX_DNA; ++mySize) {
        myDNA[mySize] = ipStr[mySize];
    }
}


//toString
//Returns string equivalent of the DNA
std::string DNA_Strand::toString() const
{
    std::string strandString;
    for (size_t x = 0; x < mySize; ++x) {
        strandString += myDNA[x];
    }

    return strandString;
}


// Set an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or 
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
void DNA_Strand::set (char new_item, size_t index)
{
    if (inRange(index)) {
        myDNA[index] = new_item;
    } else {
        throw std::out_of_range("Index out of range");
    }
}


// Get an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or 
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
char DNA_Strand::get (size_t index) const
{
    if (inRange(index)) {
        return myDNA[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}


// Returns the current size of the DNA.
size_t DNA_Strand::size () const
{
   return mySize;
}


// isEqual
// Compare this DNA_Strand with s for equality. Returns true if the
// size()'s of the two DNA_Strands are equal and all the elements from 0
// .. size()-1 are equal, else false.
bool DNA_Strand::isEqual (const DNA_Strand &s) const
{
    if (size() == s.size()) {
        for (size_t x = 0; x < size(); ++x) {
            if (get(x) != s.get(x)) {
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
int DNA_Strand::search(const std::string & target) const
{
    size_t last = mySize - (size_t)target.length();
    for (size_t x = 0; x <= last; ++last) {
        for (size_t y = 0; y < target.length(); ++y) {
            if (myDNA[x + y] != target[y]) {
                break;
            } else if (y == target.length() - 1) {
                return (int)x;
            }
        }
    }

    return -1;
}


// search
// search with start position specified
// Look for target in current DNA strand and return index.
// Return -1 if not found. If pos is past end of strand, return -1.
int DNA_Strand::search(size_t pos, const std::string & target) const
{
    size_t last = mySize - (size_t)target.length();
    for (size_t x = pos; x <= last; ++last) {
        for (size_t y = 0; y < target.length(); ++y) {
            if (myDNA[x + y] != target[y]) {
                break;
            } else if (y == target.length() - 1) {
                return (int)x;
            }
        }
    }

    return -1;
}


// cleave
// Removes from current DNA strand the sequence between the end of the 
// first occurrence of passed target sequence (e.g. "TTG"), through the end
// of the second occurrence of the target sequence.
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
// post: ACTTGA  (ACCTTG removed)
void DNA_Strand::cleave(const std::string & target)
{
    auto tarLen = (size_t)target.length();
    if (int firstTar = search(target) != -1) {
        size_t startCleave = firstTar + tarLen;
        if (search(startCleave, target) != -1) {
            size_t endCleave = (size_t)search(startCleave, target) + tarLen;
            size_t cleaveLen = endCleave - startCleave;
            for (size_t x = 0; x < cleaveLen; ++x) {
                myDNA[x + startCleave] = myDNA[x + endCleave];
                --mySize;
            }
        }
    }
}


// cleave with start position specified
// cleave starting from an index, returns the index after the cleaved DNA
// or -1 if no cleaving was performed
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG", pos = 1
// post: ACTTGA  (ACCTTG removed) and return value = 5
int DNA_Strand::cleave(size_t pos, const std::string & target)
{
    auto tarLen = (size_t)target.length();
    if (int firstTar = search(pos, target) != -1) {
        size_t startCleave = firstTar + tarLen;
        if (search(startCleave, target) != -1) {
            size_t endCleave = (size_t)search(startCleave, target) + tarLen;
            size_t cleaveLen = endCleave - startCleave;
            for (size_t x = 0; x < cleaveLen; ++x) {
                myDNA[x + startCleave] = myDNA[x + endCleave];
                --mySize;
            }

            return search(pos, target) + tarLen;
        }

        return -1;
    }

    return -1;
}


// cleaveAll
// Removes from current DNA strand the sequence between pairs of target 
// sequence, i.e. from the end 1 through the end of 2, from the end of 3 
// through the end of 4, etc, but NOT from the end of 2 through the end 3,
// or from the end of 4 through the end of 5.
// (Make sure that you understand the specification)
// pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
// post: ACTTGGGTTGCC (ATTG and CTTG removed)
void DNA_Strand::cleaveAll(const std::string & target)
{
    bool doneCleave = false;
    while (!doneCleave) {
        auto tarLen = (size_t) target.length();
        if (int firstTar = search(target) != -1) {
            size_t startCleave = firstTar + tarLen;
            if (search(startCleave, target) != -1) {
                size_t endCleave = (size_t) search(startCleave, target) + tarLen;
                size_t cleaveLen = endCleave - startCleave;
                for (size_t x = 0; x < cleaveLen; ++x) {
                    myDNA[x + startCleave] = myDNA[x + endCleave];
                    --mySize;
                }
            } else {
                doneCleave = true;
            }
        }
    }
}


// countEnzyme
// Counts the number of occurrences of a single character target sequence
// in the DNA strand.
size_t DNA_Strand::countEnzyme(char target) const
{
    size_t count = 0;
    for (size_t x = 0; x < mySize; ++x) {
        if (myDNA[x] == target) {
            ++count;
        }
    }

    return count;
}


// inRange : helper function
// Returns true if index is within range, i.e., 0 <= index < mySize 
// else returns false.
bool DNA_Strand::inRange (size_t index) const
{
    return index < mySize;
}

