// File name: DNA_Strand.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: Valentine's Day, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 2
// Description: This will be an DNA_Strand implemented with a 
// dynamic array of chars.


#include "DNA_Strand.h"
#include <stdexcept>

// Constructor
// Create an empty DNA_Strand with an array of the default size.
DNA_Strand::DNA_Strand () : maxDNA(DEFAULT_DNA_SIZE),
                            mySize(0),
                            myDNA(new char[maxDNA]) {}


// Constructor
// Dynamically create an empty DNA_Strand of a given array size.
DNA_Strand::DNA_Strand (size_t size) : maxDNA(size),
                                       mySize(0),
                                       myDNA(new char[maxDNA]) {}


// Constructor
// Create an initialized DNA_Strand.
// A dynamic array the size of ipStr will be created, and then initialized
// with the characters in ipStr
DNA_Strand::DNA_Strand (const std::string & ipStr) : maxDNA(ipStr.length()),
                                                     mySize(0),
                                                     myDNA(new char[maxDNA])
{
    for (; mySize < maxDNA; ++mySize) {
        myDNA[mySize] = ipStr[mySize];
    }
}


// The copy constructor. 
DNA_Strand::DNA_Strand (const DNA_Strand & s) : maxDNA(s.maxDNA),
                                                mySize(0),
                                                myDNA(new char[maxDNA])
{
    for (; mySize < s.mySize; ++mySize) {
        myDNA[mySize] = s.myDNA[mySize];
    }
}


// Destructor
// Clean up the DNA_Strand (e.g., delete dynamically allocated memory).
DNA_Strand::~DNA_Strand ()
{
    delete [] myDNA;
    myDNA = nullptr;
}


// Assignment operator performs an assignment by making a copy of
// the contents of parameter <rhs>
const DNA_Strand& DNA_Strand::operator= (const DNA_Strand & rhs)
{
    if (this != &rhs) {
        if (maxDNA != rhs.maxDNA) {
            delete[] myDNA;
            maxDNA = rhs.maxDNA;
            myDNA = new char[maxDNA];
        }
        mySize = 0;
        for (; mySize < rhs.mySize; ++mySize) {
            myDNA[mySize] = rhs.myDNA[mySize];
        }
    }

    return *this;
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
size_t DNA_Strand::size () const {return mySize;}


// Returns the size of the array, which is also the max size of a strand we 
// can represent
size_t DNA_Strand::maxSize () const {return maxDNA;}


// isEqual
// Compare this DNA_Strand with s for equality. Returns true if the
// size()'s of the two DNA_Strands are equal and all the elements from 0
// .. size()-1 are equal, else false.
bool DNA_Strand::isEqual (const DNA_Strand &s) const
{
    size_t sSize = s.size();
    if (size() == sSize) {
        for (size_t x = 0; x < sSize; ++x) {
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
int DNA_Strand::search(const std::string & target)const
{
    return search(0, target);
}

// search
// search with start position specified
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(size_t pos, const std::string & target)const
{
    int tLen = (int)target.length(), last = (int)mySize - tLen;
    for (int x = (int)pos; x <= last; ++x) {
        for (int y = 0; y < tLen; ++y) {
            if (myDNA[x + y] != target[y]) {
                break;
            } else if (y == tLen - 1) {
                return x;
            }
        }
    }

    return -1;
}


// cleave
// Removes from current DNA strand the sequence between the end of the 
// first occurrence of passed target sequence (e.g. "TTG"), through the end
// of the second occurence of the target sequence. 
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
// post: ACTTGA  (ACCTTG removed)
void DNA_Strand::cleave(const std::string & target)
{
    cleave(0, target);
}


// cleave with start position specified
// cleave starting from an index, returns the index after the cleaved DNA
// or -1 if no cleaving was performed
int DNA_Strand::cleave(size_t pos, const std::string & target)
{
    int index = search(pos, target);
    if (index != -1) {
        size_t startCleave = index + target.length();
        index = search(startCleave, target);
        if (index != -1) {
            size_t endCleave = index + target.length();
            size_t cleaveLen = endCleave - startCleave;
            index = (int) startCleave;
            for (; endCleave < mySize; ++endCleave) {
                myDNA[index++] = myDNA[endCleave];
            }

            mySize -= cleaveLen;
            return (int)startCleave;
        }
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
    int pos = 0;
    do {
        pos = cleave((size_t)pos, target);
    } while (pos != -1);
}


// countEnzyme
// Counts the number of occurences of a single character target sequence
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


// countEnzyme -- overloaded
// string parameter version
// Counts non-overlapping instances of the target
// Eg, the target "AAA" appears 3 non-overlapping times in the 
//   DNA "AAAAAAAAAAA"
size_t DNA_Strand::countEnzyme(const std::string & target) const
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


// grow
// This method will allow us to increase the size of the dynamically allocated
// array by allocating a new array of the desired size, copying the data from
// the old array to the new array, and then releasing the old array.
// If the newSize is less than or equal to the current size, then no actions 
// are taken.
void DNA_Strand::grow (size_t newSize)
{
    if (maxDNA < newSize) {
        auto temp = new char[newSize];
        for (size_t x = 0; x < mySize; ++x) {
            temp[x] = myDNA[x];
        }

        delete [] myDNA;
        myDNA = temp;
        maxDNA = newSize;
    }
}


// append (accepting a string parameter)
// Append the characters of the parameter to the end of the current DNA, 
// growing the array if necessary. 
// Example: if myDNA contained ACTTGA and "ACCTG" was received as a parameter, 
// then afterward myDNA will contain ACTTGAACCTG
void DNA_Strand::append(const std::string & rhs)
{
    size_t newSize = mySize + rhs.length();
    if (maxDNA < newSize) {
        grow(newSize);
    }

    for (size_t x = 0; x < rhs.length(); ++x) {
        myDNA[mySize + x] = rhs[x];
    }

    mySize = newSize;
}


// append (accepting a DNA_Strand parameter)
// Append the characters of the parameter to the end of the current DNA, 
// growing the array if necessary. 
// Example: if myDNA contained ACTTGA and ACCTG was received as a parameter, 
// then afterward myDNA will contain ACTTGAACCTG
void DNA_Strand::append(const DNA_Strand & rhs)
{
    append(rhs.toString());
}


// splice (accepts 2 Strings representing sequences)
// finds first pair of targets in current DNA strand and replaces
// the sequence between the end of the first target through the end of the 
// second with the insertSequence, growing the array if necessary. 
// If two instances of the target are not found, then no changes are made.
// Example: if myDNA contained AGTTGA, then splice("G","CCCCC") would change
// the strand to be AGCCCCCA.
// See project spec for note on efficiency.
void DNA_Strand::splice(const std::string & target, const std::string & insertSequence)
{
    splice(0, target, insertSequence);
}

   
// splice
// instead of starting from the beginning of the strand, this version
// starts from a given index, and returns the position *after* the splice,
// returns -1 if no changes are made.
// Example: if myDNA contained AGTTGA, then splice(1,"G","CCCCC") would change
// the strand to be AGCCCCCA and return index 7.
int DNA_Strand::splice(size_t pos, const std::string & target, const std::string & insertSequence)
{
    int index = search(pos, target);
    if (index != -1) {
        size_t startSplice = index + target.length();
        index = search(startSplice, target);
        if (index != -1) {
            size_t endSplice = index + target.length();
            int spliceLen = (int)insertSequence.length() - (int)(endSplice - startSplice);
            if (spliceLen > 0) {
                grow(mySize + spliceLen);
            }

            index = (int) startSplice + (int)insertSequence.length();
            for (; endSplice < mySize; ++endSplice) {
                myDNA[index++] = myDNA[endSplice];
            }

            for (index = 0; index < (int)insertSequence.length(); ++index) {
                myDNA[startSplice++] = insertSequence[index];
            }

            mySize += spliceLen;
            return (int)startSplice;
        }
    }

    return -1;
}


// inRange : helper function
// Returns true if index is within range, i.e., 0 <= index < mySize 
// else returns false.
bool DNA_Strand::inRange (size_t index) const {return index < mySize;}


