// File name: GuitarHero.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
//
// Description: program reads in a .txt file and uses it to make a .dat file that sounds like
//              a guitar
//
// Honor statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Last Changed: March 27th, 2023

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

// make sure the previous time stamp is less than or equal to the current one
void assertOrder(double lhn, double prevLhn);

// makes sure the note is in range
void assertRange(int rhn);


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
    double lhn;
    int rhn;
    double prevLhn = 0.0;
    while (infile.good()) {
        infile >> lhn;
        assertOrder(lhn, prevLhn);
        auto nextNote = (size_t)(lhn * SAMPLE_RATE);

        infile >> rhn;
        assertRange(rhn);

        while (strings[0]->getTime() != nextNote) {
            double sum = 0.0;
            for (auto string : strings) {
                sum += string->sample();
                string->tic();
            }

            outfile << "  " << (double)strings[0]->getTime() * STEP << '\t' << sum << std::endl;

            if (strings[0]->getTime() % SAMPLE_RATE == 0)
                std::cout << "." << std::flush;
        }

        if (rhn == END_OF_SONG)
            break;
        strings[rhn]->pluck();
        prevLhn = lhn;
    }

    std::cout << "\n\n     ; \n"
                 "     ;;\n"
                 "     ;';.\n"
                 "     ;  ;;\n"
                 "     ;   ;;\n"
                 "     ;    ;;\n"
                 "     ;    ;;\n"
                 "     ;   ;'\n"
                 "     ;  ' \n"
                 ",;;;,; \n"
                 ";;;;;;\n"
                 "`;;;;'\n" << std::endl;


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
        std::cout << "String " << i << " has frequency="
                  << strings[i]->getFrequency() << std::endl;
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

// make sure the previous time stamp is less than or equal to the current one
void assertOrder(double lhn, double prevLhn)
{
    if (prevLhn > lhn)
        throw std::out_of_range("Improper time order from input file");
}

// makes sure the note is in range
void assertRange(int rhn)
{
    if (rhn > 36 || rhn < -1)
        throw std::out_of_range("Improper time order from input file");
}
