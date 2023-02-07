// File name: DNA_Strand.h
// Author: 
// VUnetid: 
// Email: 
// Class: CS2201
// Date: 
// Honor statement:
// Assignment Number: 
// Description: This will be an DNA_Strand implemented with a 
//              dynamic array of chars.



#ifndef DNA_STRAND_H
#define DNA_STRAND_H

#include <string>

//Default size of dynamic DNA Array
const size_t DEFAULT_DNA_SIZE = 50;

class DNA_Strand {

private:

    // Returns true if index is within range of the current DNA_Strand
    // else returns false.
    bool inRange(size_t index) const;

    // Size of the dynamically allocated array
    size_t maxDNA;

    // Current size of the DNA_Strand; i.e., how many elements of the array are
    // currently being used (since this is a partially-filled array)
    size_t mySize;

    // DNA_Strand's storage buffer. May only be partially filled.
    char *myDNA;


public:

    // Create an empty DNA_Strand with an array of the default size.
    DNA_Strand();  // deafult ctor


    // Dynamically create an empty DNA_Strand of a given array size.
    DNA_Strand(size_t size);   // alt ctor


    // Create an initialized DNA_Strand.
    // A dynamic array the size of ipStr will be created, and then initialized
    // with the characters in ipStr
    DNA_Strand(const std::string &ipStr);  // ctor that takes a string


    // The copy constructor.
    DNA_Strand(const DNA_Strand &s);


    // Destructor
    // Clean up the DNA_Strand (e.g., delete dynamically allocated memory).
    ~DNA_Strand();


    // Assignment operator performs an assignment by making a copy of
    // the contents of parameter <rhs>
    const DNA_Strand & operator=(const DNA_Strand &rhs);


    //toString
    //Returns string equivalent of the DNA
    std::string toString() const;


    // Set an item in the DNA_Strand at location index. Throws
    // <std::out_of_range> if index is out of range, i.e., larger than or
    // equal to the current size of the DNA_Strand.
    // Uses zero-based indexing.
    void set(char new_item, size_t index);

    // Get an item in the DNA_Strand at location index. Throws
    // <std::out_of_range> if index is out of range, i.e., larger than or
    // equal to the current size of the DNA_Strand.
    // Uses zero-based indexing.
    char get(size_t index) const;


    // Returns the current size of the DNA.
    size_t size() const;


    // Returns the size of the array, which is also the max size of a strand we
    // can represent
    size_t maxSize() const;


    // Compare this DNA_Strand with s for equality. Returns true if the
    // size()'s of the two DNA_Strands are equal and all the elements from 0
    // .. size()-1 are equal, else false.
    bool isEqual(const DNA_Strand &s) const;


    // search
    // Look for target in current DNA strand and return index.
    // Return -1 if not found.
    int search(const std::string &target) const;


    // search with start position specified
    // Look for target in current DNA strand and return index.
    // Return -1 if not found. If pos is past end of strand, return -1.
    int search(size_t pos, const std::string &target) const;


    // cleave
    // Removes from current DNA strand the sequence between the end of the
    // first occurrence of passed target sequence (e.g. "TTG"), through the end
    // of the second occurence of the target sequence.
    // pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
    // post: ACTTGA  (ACCTTG removed)
    void cleave(const std::string &target);


    // cleave with start position specified
    // cleave starting from an index, returns the index after the cleaved DNA
    // or -1 if no cleaving was performed
    // pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG", pos = 1
    // post: ACTTGA  (ACCTTG removed) and return value = 5
    int cleave(size_t pos, const std::string &target);


    // cleaveAll
    // Removes from current DNA strand the sequence between pairs of target
    // sequence, i.e. from the end 1 through the end of 2, from the end of 3
    // through the end of 4, etc, but NOT from the end of 2 through the end 3,
    // or from the end of 4 through the end of 5.
    // (Make sure that you understand the specification)
    // pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
    // post: ACTTGGGTTGCC (ATTG and CTTG removed)
    void cleaveAll(const std::string &target);


    // countEnzyme
    // Counts the number of occurences of a single character target sequence
    // in the DNA strand.
    size_t countEnzyme(char target) const;


    // countEnzyme -- overloaded
    // string parameter version
    // Counts non-overlapping instances of the target
    // Eg, the target "AAA" appears 3 non-overlapping times in the
    //   DNA "AAAAAAAAAAA"
    size_t countEnzyme(const std::string &target) const;


    // grow
    // This method will allow us to increase the size of the dynamically
    // allocated array by allocating a new array of the desired size, copying
    // the data from the old array to the new array, and then releasing the old
    // array. If the newSize is less than or equal to the current size, then no
    // actions are taken.
    void grow(size_t newSize);


    // append (accepting a string parameter)
    // Append the characters of the parameter to the end of the current DNA,
    // growing the array if necessary.
    // Example: if myDNA contained ACTTGA and "ACCTG" was received as a
    // parameter, then afterward myDNA will contain ACTTGAACCTG
    void append(const std::string &rhs);


    // append (accepting a DNA_Strand parameter)
    // Append the characters of the parameter to the end of the current DNA,
    // growing the array if necessary.
    // Example: if myDNA contained ACTTGA and ACCTG was received as a parameter,
    // then afterward myDNA will contain ACTTGAACCTG
    void append(const DNA_Strand &rhs);


    // splice (accepts 2 Strings representing sequences)
    // finds first pair of targets in current DNA strand and replaces
    // the sequence between the end of the first target through the end of the
    // second with the insertSequence, growing the array if necessary.
    // If two instances of the target are not found, then no changes are made.
    // Example: if myDNA contained AGTTGA, then splice("G","CCCCC") would change
    // the strand to be AGCCCCCA.
    // See project spec for note on efficiency.
    void splice(const std::string &target, const std::string &insertSequence);


    // splice
    // instead of starting from the beginning of the strand, this version
    // starts from a given index, and returns the position *after* the splice,
    // returns -1 if no changes are made.
    // Example: if myDNA contained AGTTGA, then splice(1,"G","CCCCC") would
    // change the strand to be AGCCCCCA and return index 7.
    int splice(size_t pos, const std::string &target, const std::string &insertSequence);


};


#endif /* ifndef */
