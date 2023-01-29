// File name: DNA_Strand.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201
// Date: January 29th, 2023
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Assignment Number: 1
// Description: This will be an DNA_Strand implemented with a static 
//              array of chars.


#include "DNA_Strand.h"
#include <stdexcept>

// Constructor
// Create an empty DNA_Strand.
DNA_Strand::DNA_Strand ()
{
    // add your code here and/or on base member initialization list
}


// Constructor
// Create an initialized DNA_Strand.
// If the string ipStr is larger than MAX_DNA, then only the first MAX_DNA
// characters of ipStr are used to initialize the DNA_Strand
DNA_Strand::DNA_Strand (const std::string & ipStr)
{
    std::string junk(ipStr); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    // add your code here and/or on base member initialization list
}


//toString
//Returns string equivalent of the DNA
std::string DNA_Strand::toString() const
{
    return "junk";  // DELETE THIS AND REPLACE WITH YOUR CODE.
}


// Set an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or 
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
void DNA_Strand::set (char new_item, size_t index)
{
    std::string junk(std::to_string(index+new_item)); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
}


// Get an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or 
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
char DNA_Strand::get (size_t index) const
{
    std::string junk(std::to_string(index)); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    return '!';  // DELETE THIS AND REPLACE WITH YOUR CODE.
}


// Returns the current size of the DNA.
size_t DNA_Strand::size () const
{
   return 999999;  // DELETE THIS AND REPLACE WITH YOUR CODE.
}


// isEqual
// Compare this DNA_Strand with s for equality. Returns true if the
// size()'s of the two DNA_Strands are equal and all the elements from 0
// .. size()-1 are equal, else false.
bool DNA_Strand::isEqual (const DNA_Strand &s) const
{
    std::string junk(s.toString()); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    return false;  // DELETE THIS AND REPLACE WITH YOUR CODE.
}


// search
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(const std::string & target) const
{
    std::string junk(target); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    return -99;  // DELETE THIS AND REPLACE WITH YOUR CODE.
}


// search
// search with start position specified
// Look for target in current DNA strand and return index.
// Return -1 if not found. If pos is past end of strand, return -1.
int DNA_Strand::search(size_t pos, const std::string & target) const
{
    std::string junk(target+std::to_string(pos)); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    return -99;  // DELETE THIS AND REPLACE WITH YOUR CODE.
}


// cleave
// Removes from current DNA strand the sequence between the end of the 
// first occurrence of passed target sequence (e.g. "TTG"), through the end
// of the second occurence of the target sequence. 
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
// post: ACTTGA  (ACCTTG removed)
void DNA_Strand::cleave(const std::string & target)
{
    std::string junk(target); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
}


// cleave with start position specified
// cleave starting from an index, returns the index after the cleaved DNA
// or -1 if no cleaving was performed
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG", pos = 1
// post: ACTTGA  (ACCTTG removed) and return value = 5
int DNA_Strand::cleave(size_t pos, const std::string & target)
{
    std::string junk(target+std::to_string(pos)+std::to_string(mySize)+myDNA[0]); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    return -99;  // DELETE THIS AND REPLACE WITH YOUR CODE.
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
    std::string junk(target); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
}


// countEnzyme
// Counts the number of occurences of a single character target sequence
// in the DNA strand.
size_t DNA_Strand::countEnzyme(char target) const
{
    std::string junk(std::to_string(target)); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    return 999999;  // DELETE THIS AND REPLACE WITH YOUR CODE.
}


// inRange : helper function
// Returns true if index is within range, i.e., 0 <= index < mySize 
// else returns false.
bool DNA_Strand::inRange (size_t index) const
{
    std::string junk(std::to_string(index)); // DELETE THIS AND REPLACE WITH YOUR CODE. THIS IS ONLY HERE TEMPORARILY TO MAKE THE COMPILER HAPPY
    return false;  // DELETE THIS AND REPLACE WITH YOUR CODE.
}

