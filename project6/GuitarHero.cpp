// File name: GuitarHero.cpp
// Author: 
// userid: 
// Email: 
// Class: CS2201 @ Vanderbilt U.
// Assignment Number:
// Description:  
// Honor statement:
// Last Changed: 

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "GuitarString.h"


const double CONCERT_A = 440.0;
const int NUM_STRINGS = 37;
const double STEP = (double)1/((double)SAMPLE_RATE);   //SAMPLE_RATE in GuitarString.h
const int END_OF_SONG = -1;


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile);

// close input and output files
// post: files have been closed
void closeFiles (std::ifstream &infile, std::ofstream &outfile);

// create the guitar string objects
// post: array of GuitarString objects have been created and initialized
void createStrings(GuitarString* strings[], int size);

// destroy the guitar string objects
// post: array of GuitarString objects have been deallocated
void destroyStrings(GuitarString* strings[], int size);


// If you want to create your own helper functons (highly recommended), declare them
// here and then define them after the main() function.




int main() {

    // create the array of guitar strings (3 octaves)
    GuitarString* strings[NUM_STRINGS];
    createStrings(strings, NUM_STRINGS);

    //open data file
    std::ifstream infile;
    std::ofstream outfile;
    openFiles(infile, outfile);

    //prime the output file
    outfile.setf(std::ios::fixed, std::ios::floatfield);
    outfile.precision(10);
    std::string firstLine = "; Sample Rate " + std::to_string(SAMPLE_RATE);
    std::string secondLine = "; Channels 1";
    outfile << firstLine << std::endl;
    outfile << secondLine << std::endl;


    std::cout << "Reading the input file and generating a .dat file for sox" << std::endl;

    // TODO
    // your task is to read & process all the data in the input stream "infile",
    // and create & write the correct data to the output stream "outfile".
    // That work should be done here before the files are closed.
    // Define and use helper functions as needed for good style.



    // close the files
    closeFiles (infile, outfile);

    //Clean up all the strings
    destroyStrings(strings, NUM_STRINGS);

    std::cout << "Done." << std::endl;
    return 0;
}


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile) {

    // open input data file
    std::string inFileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> inFileName;
    infile.open(inFileName.c_str());
    if (infile.fail()) {
        std::cout << "Error opening input data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }
    // open output data file
    std::string outFileName;
    std::cout << "Enter the name of the output file: ";
    std::cin >> outFileName;
    outfile.open(outFileName.c_str());
    if (outfile.fail()) {
        std::cout << "Error opening output data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }

}

// close input and output files
// post: files have been closed
void closeFiles (std::ifstream &infile, std::ofstream &outfile)  {
    infile.close();
    outfile.close();
}

// create the guitar string objects
// post: array of GuitarString objects have been created and initialized
void createStrings(GuitarString* strings[], int size) {
    for (int i = 0; i < size; i++) {
        double factor = pow(2, (i - 24) / 12.0);
        strings[i] = new GuitarString(CONCERT_A * factor);
        //std::cout << "String " << i << " has frequency=" 
        //          << strings[i]->getFrequency() << std::endl;
    }
}

// destroy the guitar string objects
// post: array of GuitarString objects have been deallocated
void destroyStrings(GuitarString* strings[], int size) {
    //Clean up all the strings
    for (int i = 0; i < size; i++) {
        if(strings[i] != nullptr) {
            delete strings[i];
            strings[i] = nullptr;
        }
    }
}
