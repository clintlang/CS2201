// Name:
// Email:
// VUnetid:
// Class:
// Date:
// Honor statement: 
// Description:
// Reverse a sound data file by reading in all the data samples,
// pushing them onto stacks, and then creating a new sound data
// file while popping values off the stacks.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DblStack.h"


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile);


int main() {

    // open input & output data files
    std::ifstream infile;
    std::ofstream outfile;
    openFiles(infile, outfile);

    std::cout << "Reading the input file..." << std::endl;

    // read in the data on the first line of the file
    std::string firstLine, secondLine;

    getline(infile, firstLine);    // read in the first line
    getline(infile, secondLine);   // read in the second line


    // TODO
    // Your job is to read the rest of the input file and
    // process the data. Hint: USE THE EXTRACTION OPERATOR!!
    // Read values in pairs.




    std::cout << "There were " << "??" << " samples in the file." << std::endl;
    std::cout << "Creating output file... wait for Done message." << std::endl;


    //
    // Now we are ready to output the data values to output file.
    // But first, we need to output the header lines
    //
    outfile.setf(std::ios::fixed, std::ios::floatfield);
    outfile.precision(10);
    outfile << firstLine << std::endl;
    outfile << secondLine << std::endl;


    // TODO
    // Your job is to write the rest of the output file.
    // Each line should start with two blanks, then the time-step
    // value, then a single tab character '\t', then the sound data value.




    // close the files
    infile.close();
    outfile.close();

    std::cout << "Done." << std::endl;

//   std::cout << "press enter to exit";
//   std::cin.get();
//   std::cin.get();

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
