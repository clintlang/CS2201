// File name: lab04.cpp
// Author: Clinton Lang
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 4
// Honor Statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
//
// Description: program consists of various recursive functions
//
// Last Changed: March 6th, 2023
//
// Recursive programming lab


#include <iostream>
#include <string>
#include <cstdlib>
#include <utility>
#include <cmath>
#include "lab04.h"


int sumArray(int anArray[], size_t size)
{

}


bool member(int target, const int set[], size_t size)
{
    if (size == 0) {
        return false;
    }

    if (set[size - 1] == target) {
        return true;
    }

    return member(target, set, size - 1);
}


bool isPalindrome(const std::string &str)
{
    if (str.length() == 0) {
        return true;
    }

    if (tolower(str[0]) == tolower(str[str.length() - 1])) {
        return isPalindrome(str.substr(1, str.length() - 2));
    }

    return false;
}


double harmonicSum(size_t n)
{
    if (n == 0) {
        return 0;
    }

    return ((1.0 / (double)n) + harmonicSum(n - 1));
}


std::string addStar(const std::string &str)
{
    if (str.length() == 0 || str.length() == 1) {
        return str;
    }

    std::string newStr(str);
    newStr.insert(1, "*");

    return newStr.substr(0, 2) + addStar(newStr.substr(2, newStr.length() - 1));
}


size_t replace(int target, int replacement, int numbers[], size_t size)
{
    if (size == 0) {
        return 0;
    }

    if (numbers[size - 1] == target) {
        numbers[size - 1] = replacement;
        return 1 + replace(target, replacement, numbers, size - 1);
    }

    return replace(target, replacement, numbers, size - 1);
}


size_t gcd(size_t x, size_t y)
{

}

