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


//Task: compute the sum of an array of integers
//Pre: anArray is an array of 'size' integers, size is nonnegative
//Post: the sum of anArray[0]...anArray[size-1] is returned
// Additional requirement: This function must be done by dividing the array
//   in half and performing recursive calls on each half (as opposed to just
//   shrinking the size by one each time). Hint: use pointer arithmetic
int sumArray(int anArray[], size_t size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return *anArray;

    auto size1 = size >> 1;
    auto size2 = size1 + (size & 1);

    return sumArray(anArray, size1) + sumArray(anArray + size1, size2);
}


//Task: determine if target is in the set
//Pre: set is an array of 'size' integers, size is nonnegative
//Post: true is returned if target is in the set, else false;
//  the set is unchanged
bool member(int target, const int set[], size_t size)
{
    if (size == 0)
        return false;
    if (set[size - 1] == target)
        return true;

    return member(target, set, size - 1);
}


//Task: determine if a string is a palindrome
//Pre: str is a string object
//Post: returns true if str is a palindrome, otherwise returns false
//      The test is case insensitive [look up toupper() and
//      tolower()]. You do not need to worry about
//      trimming blanks from the ends of the string.
//Note: the empty string is a palindrome
bool isPalindrome(const std::string &str)
{
    if (str.length() <= 1)
        return true;

    if (tolower(str[0]) == tolower(str[str.length() - 1])) {
        return isPalindrome(str.substr(1, str.length() - 2));
    }

    return false;
}


//Task: compute the sum of the first n harmonic terms
//Pre: n is a positive integer
//Post: the sum of the first n harmonic terms is returned.
// The harmonic series is 1 + (1/2) + (1/3) + (1/4) + ...
double harmonicSum(size_t n)
{
    return n == 0 ? 0 : (1.0 / (double)n) + harmonicSum(n - 1);
}


// Task: Given a string, compute recursively a new string where all the adjacent
//   chars are now separated by a "*".
// Pre: str is a string (may be empty).
// Post: a correctly starred string is returned.
// Examples:
//   addStar("hello") --> "h*e*l*l*o"
//   addStar("abc") --> "a*b*c"
//   addStar("ab") --> "a*b"
std::string addStar(const std::string &str)
{
    if (str.length() <= 1)
        return str;

    return str.substr(0, 1) + "*" + addStar(str.substr(1, str.length() - 1));
}


//Task: replace all occurrences of 'target' in the array 'numbers'
//      with 'replacement'
//Pre: 'numbers' is an array of 'size' integers, size is nonnegative
//Post: all occurrences of 'target' in 'numbers' have been replaced
//      with 'replacement'; the number of replacements performed is
//      returned to the caller.
size_t replace(int target, int replacement, int numbers[], size_t size)
{
    if (size == 0)
        return 0;

    size_t newSize(size - 1);
    if (numbers[newSize] == target) {
        numbers[newSize] = replacement;
        return 1 + replace(target, replacement, numbers, newSize);
    }

    return replace(target, replacement, numbers, newSize);
}


// Task: compute the Greatest Common Divisor (GCD) of two nonnegative
//       integers using Euclid's formula:
//
// Euclid's method for computing the greatest common divisor (GCD) of two
// nonnegative integers a and b is as follows. Divide a and b to obtain the
// integer quotient q and remainder r, so that a = bq+r (if b = 0,
// then GCD(a, b) = a). Then GCD(a, b) = GCD(b, r). Replace a with b and
// b with r and repeat the procedure. Because the remainders are decreasing,
// eventually a remainder of 0 will result. The last nonzero remainder is
// the greatest common divisor of a and b.
//
// Pre: the parameters x & y are nonnegative
// Post: the GCD of x & y is returned
size_t gcd(size_t x, size_t y)
{
    return y == 0 ? x : gcd(y, x % y);
}


// Task: produce a string of num copies "Hello World"'s, where all the "Hello"'s precede
//   all the "World"'s. For example:
//   When num is 1, return "Hello World"
//   When num is 3, return "Hello Hello Hello World World World"
//   Note: there is only a single space between any two words, and there is
//   no space at the beginning or end of the string
// Pre: num is a nonnegative integer
// Post: the desired string is returned
std::string helloWorldRepeat(size_t num)
{
    if (num == 0)
        return "";
    if (num == 1)
        return "Hello World";

    return "Hello " + helloWorldRepeat(num - 1) + " World";
}


// Task: produce the binary representation of a decimal number
//   A decimal number is converted to binary by repeated
//   division by 2. For each division, keep track of the quotient
//   and remainder. The remainder becomes the low-order bit (rightmost
//   bit) of the binary representation. The higher-order bits are
//   determined by repeating the processes with the quotient.
//   The process stops when num is either zero or one.
// Pre: num is a nonnegative integer
// Post: the binary representation of num is produced and returned
//   as a string.
std::string convert2Binary(size_t num)
{
    if (num == 0)
        return "0";
    if (num == 1)
        return "1";

    return convert2Binary(num >> 1) + std::to_string(num & 1);
}


// Task: Print a pseudo hourglass pattern on the screen
// Pre: num is a positive integer
// Post: the desired pattern is displayed on cout
// You may use iteration anytime to print a single line of *'s, but
// must use recursion to complete the pattern.
// Example: a call to printPattern(4) should produce the
// pattern below (excluding the beginning and ending comment):
// Each & every line you print should end with a newline character.
/*
****
***
**
*
**
***
****
*/
void printPattern(size_t num)
{
    if (num > 0) {
        for (size_t x = 0; x < num; ++x) std::cout << "*";
        std::cout << std::endl;

        printPattern(num - 1);

        if (num > 1) {
            for (size_t x = 0; x < num; ++x) std::cout << "*";
            std::cout << std::endl;
        }
    }
}


// Task: reverse the contents of a[first]...a[last]
// Pre: 'a' is an array of at least 'last'+1 integers, first&last are nonnegative
// Post: the elements a[first]...a[last]have been reversed.
void reverseArray(int a[], size_t first, size_t last)
{
    if (first < last) {
        int tmp = a[first];
        a[first] = a[last];
        a[last] = tmp;
        reverseArray(a, first + 1, last - 1);
    }
}


// Task: initialize all elements of the array between indices lb and ub to the
//   given value, including the elements at lb & ub
// Note: lb = lower bound, ub = upper bound
// Pre: lb and ub are valid indices into the array a [the actual size of the
//   array is unknown]
// Post: the array elements in the segment a[lb..ub] have been set to value
// Additional requirement: This function must be done by dividing the array
//   segment in half and performing recursive calls on each half (as opposed
//   to just shrinking the array bound by one each time)
void arrayInitialize(int a[], int value, size_t lb, size_t ub)
{
    if (ub > lb) {
        size_t half = (ub + lb) >> 1;

        arrayInitialize(a, value, lb, half);
        arrayInitialize(a, value, half + 1, ub);
    } else if (ub == lb) {
        a[ub] = value;
    }
}


// Task: Compute the Binomial Coefficient using Pascal's Triangle.
// The Binomial Coefficient B(n, r) is the coefficient of the term x^r in the
// binormial expansion of (1 + x)^n.
// For example, B(4, 2) = 6 because (1+x)^4 = 1 + 4x + 6x^2 + 4x^3 + x^4.
// The Binomial Coefficient can be computed using the Pascal Triangle formula:
//	B(n, r) = 1                          if r = 0 or r = n
//	B(n, r) = B(n-1, r-1) + B(n-1, r)    otherwise
// Pre: r & n are non-negative, and r<=n
// Post: the correct coefficient is returned
size_t binomialCoeff(size_t n, size_t r)
{
    return r == 0 || r == n ? 1 : binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);
}


// Task: Given a non-negative int n, compute recursively (no loops) the count
//   of the occurrences of 2 as a digit, except that a 2 with another 2
//   immediately to its left counts double, so 2212 yields 4, and 222212
//   yields 8. Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
//   while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
// Pre: n is non-negative
// Post: count of the occurrences of 2 is returned (with doubling as appropriate)
// Examples:
//   count2(2) --> 1
//   count2(212) --> 2
//   count2(2212) --> 4
//   count2(222212) --> 8
size_t count2(size_t n)
{
    if (n == 2)
        return 1;
    if (n < 10)
        return 0;
    if (n % 100 == 22)
        return 2 + count2(n / 10);
    if (n % 10 == 2)
        return 1 + count2(n / 10);

    return count2(n / 10);
}


// Task: determine if each number in the array (except for the first element)
//       is the square of the number before it
// Pre:  anArray is an array of 'size' integers, size is nonnegative
// Post: true is returned if each number (except for the first element) is
//       the square of the number before it, returns false otherwise. Also
//       returns false if there are less than two elements in the array
bool relatedSquares(int anArray[], size_t size)
{
    if (size < 2)
        return false;
    if (anArray[size - 1] != anArray[size - 2] * anArray[size - 2])
        return false;

    return size == 2 || relatedSquares(anArray, size - 1);
}


// Task: Given a string and a non-empty substring sub, compute recursively
//   the number of times that sub appears in the string, without the sub
//   strings overlapping.
// Pre: sub is a non-empty string
// Post: the count of non-overlapping occurrences of sub in str is returned
// Examples:
//   countSubs("catcowcat", "cat") --> 2
//   countSubs("catcowcat", "cow") --> 1
//   countSubs("catcowcat", "dog") --> 0
size_t countSubs(const std::string &str, const std::string &sub)
{
    if (sub.length() > str.length())
        return 0;

    if (str.substr(0, sub.length()) == sub) {
        return 1 + countSubs(str.substr(sub.length()), sub);
    }

    return countSubs(str.substr(1), sub);
}


// Task: Given a string, compute recursively a new string where all the
//   lowercase 'x' chars have been moved to the end of the string.
// Pre: str is a string (possibly empty)
// Post: return a new string where all lowercase 'x' chars have been
//   moved to the end
// Examples:
//   moveXs("xxre") --> "rexx"
//   moveXs("xxhixx") --> "hixxxx"
//   moveXs("xhixhix") --> "hihixxx"
std::string moveXs(const std::string &str)
{
    if (str.length() == 0)
        return "";
    if (str[0] != 'x')
        return str[0] + moveXs(str.substr(1));

    return moveXs(str.substr(1)) + 'x';
}


// Newtons method for approximating square roots.
// The next iteration is the average of the previous iteration and the
// ratio of the number in question to the previous iteration.
// In other words:
//     x_i = ( x_(i-1) + number/x_(i-1) ) / 2
// if i is 0 the approximation is simply half the number.
// Pre: number & iterations are non-negative integers
// Post: return an approximation of sqrt(number)
// Note: number & iterations are integers, but the return value is double
double newton(size_t number, size_t iterations)
{
    auto dubNum = (double)number;
    if (iterations < 1)
        return dubNum / 2;

    return (newton(number, iterations - 1) + dubNum / newton(number, iterations - 1)) / 2;
}


// Task: Determine the number of ways to get from the top-left corner of an NxM grid
//   to the bottom-right corner of the grid. You can only move right or down from each
//   grid position.
// Pre: n>0 and m>0
// Post: The number of paths is returned
// Example: Given a 2 by 2 matrix, you should return 2, since there are two ways to get
//   to the bottom-right: (1) right, then down; or (2) down, then right.
//   Thus countTheWays(2,2) should return 2. Similarly, countTheWays(5,5) should return 70.
size_t countTheWays(size_t n, size_t m)
{
    return n == 1 || m == 1 ? 1 : countTheWays(n - 1, m) + countTheWays(n, m - 1);
}


// Task: Count the number of nodes with a nonzero value in a linked list
// Pre: tmpPtr points to the first node of the list, or it is nullptr if
//  the list is empty
// Post: the number of nodes with a nonzero value in the linked list is
//  returned, and the linked list is unchanged.
size_t numOfTerms(NodePtr tmpPtr)
{
    if (tmpPtr)
        return numOfTerms(tmpPtr->next) + (tmpPtr->value ? 1 : 0);

    return 0;
}


// Task: Remove leading zeroes from a BigNum represented by a linked list.
// Pre: tmpPtr points to the first node of a list, or is nullptr if the
//  list is empty
// Post: all nodes at the end of the list which have a zero have been removed
// Note 1: as discussed in lecture, a BigNum stores the digits of the number
//         in reverse order, with the ones digit at the front of the list.
//         We are deleteing leading zeroes, which would appear at the end
//         of the list if they exist
// Note 2: The parameter tmpPtr is passed by reference, so any changes to it
//         will affect the pointer in the caller
void normalizeBigNum(NodePtr &tmpPtr)
{
    if (!tmpPtr)
        return;

    normalizeBigNum(tmpPtr->next);

    if (tmpPtr->value == 0 && !tmpPtr->next) {
        delete tmpPtr;
        tmpPtr = nullptr;
    }
}


// Task: Create a string of the contents of the linked list in forward order and then
//   echo the same values in reverse order. Each value is followed by a space in the string.
// Pre: tmpPtr points to the first node of the list, or it is nullptr if
//  the list is empty
// Post: the values of all nodes in the linked list are in the string in forward
//  order, and then the same values are printed in reverse order, with each value
//  followed by a single blank, and the linked list is unchanged.
// Ex: if the list contains tmpPtr->1->2->3, we will return "1 2 3 3 2 1 "
std::string echo2(NodePtr tmpPtr)
{
    if (tmpPtr) {
        auto valString = std::to_string(tmpPtr->value) + " ";

        return valString + echo2(tmpPtr->next) + valString;
    }

    return "";
}


// Task: Find out whether a linked list sub is contained within another linked list super
// Pre: super and sub are head pointers to non-empty linked lists
// Post: Return true or false depending on whether sub is contained in super
// A list is contained in another list if all the data elements appear in the
// same relative order. Both linked lists are unchanged.
// If super was 2->13->5->6->10->21 and if sub was 13->5->10 then contains would be true.
// If super was 2->13->5->6->10->21 and if sub was 5->13->10 then contains would be false.
// If super was 2->13->5->6->10->21 and if sub was 13->7->10 then contains would return false.
bool contains(NodePtr super, NodePtr sub)
{
    if (!sub)
        return true;

    if (!super)
        return false;

    if (super->value != sub->value)
        return contains(super->next, sub);

    return contains(super->next, sub->next);
}


// Task: Reverse the nodes in a linked list.
// Pre: tmpPtr points to the first node of the list, or it is nullptr if the list is empty.
// Post: the list has been reversed and a pointer to the new first node is returned.
// This must be accomplished without allocating any new nodes or deleting existing nodes.
// In fact, you should only change the 'next' field of each node.
// You must accomplish this task only with recursion and without any code to walk the list.
NodePtr reverseList(NodePtr tmpPtr)
{
    if (!tmpPtr->next)
        return tmpPtr;

    auto newHead = reverseList(tmpPtr->next);
    tmpPtr->next->next = tmpPtr;
    tmpPtr->next = nullptr;

    return newHead;
}