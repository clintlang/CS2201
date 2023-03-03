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
    if (size == 0) {return false;}

    if (set[size - 1] == target) {return true;}

    return member(target, set, size - 1);
}


bool isPalindrome(const std::string &str)
{
    if (str.length() <= 1) {return true;}

    if (tolower(str[0]) == tolower(str[str.length() - 1])) {
        return isPalindrome(str.substr(1, str.length() - 2));
    }

    return false;
}


double harmonicSum(size_t n)
{
    if (n == 0) {return 0;}

    return ((1.0 / (double)n) + harmonicSum(n - 1));
}


std::string addStar(const std::string &str)
{
    if (str.length() == 0 || str.length() == 1) {return str;}

    std::string newStr(str);
    newStr.insert(1, "*");

    return newStr.substr(0, 2) + addStar(newStr.substr(2, newStr.length() - 1));
}


size_t replace(int target, int replacement, int numbers[], size_t size)
{
    if (size == 0) {return 0;}

    size_t newSize(size - 1);
    if (numbers[newSize] == target) {
        numbers[newSize] = replacement;
        return 1 + replace(target, replacement, numbers, newSize);
    }

    return replace(target, replacement, numbers, newSize);
}


size_t gcd(size_t x, size_t y)
{
    if (y == 0) {return x;}

    return gcd(y, x % y);
}


std::string helloWorldRepeat(size_t num)
{
    if (num == 0) {return "";}

    if (num != 1) {return "Hello " + helloWorldRepeat(num - 1) + " World";}

    return "Hello " + helloWorldRepeat(num - 1) + "World";
}


std::string convert2Binary(size_t num)
{
    if (num == 0) {return "";}

    if (num % 2 == 0) {return convert2Binary(num / 2) + "0";}

    return convert2Binary(num / 2) + "1";
}


void printPattern(size_t num)
{
    if (num != 0) {
        for (size_t x = 0; x < num; ++x) { std::cout << "*"; }
        std::cout << std::endl;

        printPattern(num - 1);

        if (num != 1) {
            for (size_t x = 0; x < num; ++x) { std::cout << "*"; }
            std::cout << std::endl;
        }
    }
}


void reverseArray(int a[], size_t first, size_t last)
{
    if (first < last) {
        int tmp = a[first];
        a[first] = a[last];
        a[last] = tmp;
        reverseArray(a, first + 1, last - 1);
    }
}


void arrayInitialize(int a[], int value, size_t lb, size_t ub)
{
    if (ub > lb) {
        size_t half = (ub - lb) / 2;
        a[lb] = value;
        a[ub] = value;

        arrayInitialize(a, value, lb + 1, half);
        arrayInitialize(a, value, half, ub - 1);
    }
}


size_t binomialCoeff(size_t n, size_t r)
{
    if (r == 0 || r == n) {return 1;}

    return binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);
}


size_t count2(size_t n)
{
    if (n == 2) {return 1;}

    if (n < 10) {return 0;}

    if (n % 100 == 22) {return 2 + count2(n / 10);}

    if (n % 10 == 2) {return 1 + count2(n / 10);}

    return count2(n / 10);
}


bool relatedSquares(int anArray[], size_t size)
{
    if (size <= 1) {return true;}

    if ((double)sqrt(anArray[size - 1]) != (double)anArray[size - 2]) {return false;}

    return relatedSquares(anArray, size - 1);
}