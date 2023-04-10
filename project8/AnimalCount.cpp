// File name: AnimalCount.cpp
// Author: 
// Userid: 
// Email: 
// Class: 
// Assignment Number:
// Description:
// Last Changed:


#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

//DO NOT CHANGE THESE
typedef std::set<std::string> FamilySet;
typedef std::map<std::string, FamilySet> FamilyNameMap;


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles (std::ifstream &infile, std::ofstream &outfile);

// close input and output files
// post: files have been closed
void closeFiles (std::ifstream &infile, std::ofstream &outfile);


// Process mammal data from the inFile stream and produce report
// to the outFile stream.
// The report will list the largest mammal family and the members that
// make up that family.
void determineLargestMammalFamily(std::ifstream &infile, std::ofstream &outfile);



int main() {
    //open data file
    std::ifstream infile;
    std::ofstream outfile;
    openFiles(infile, outfile);

    //read in data file and produce the required report
    determineLargestMammalFamily(infile, outfile);

    // close the files
    closeFiles (infile, outfile);

    return 0;
}


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles (std::ifstream &infile, std::ofstream &outfile)
{

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
    std::string outFileName("FamilyReport.txt");
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


// Process mammal data from the inFile stream and produce report
// to the outFile stream.
// The report will list the largest mammal family and the members that
// make up that family.
void determineLargestMammalFamily(std::ifstream &infile, std::ofstream &outfile)
{
    //TODO
    //Write your code here and in helper functions.
}

