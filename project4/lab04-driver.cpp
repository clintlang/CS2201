// File name: lab04-driver.cpp
// Author: Clinton Lang and Dr. Roth
// VUnetid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 4
// Description: test cases for each method written in lab04.cpp
// Last Changed: March 6th, 2023

// Recursive programming lab

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include "lab04.h"


void printList(NodePtr head);


int main ()
{
    std::cout << "\nStarting tests...\n" << std::endl;


    if (addStar("hello") != "h*e*l*l*o") {
        std::cout << "addStar() FAIL" << std::endl;
    }
    if (addStar("bounce") != "b*o*u*n*c*e") {
        std::cout << "addStar() FAIL" << std::endl;
    }

    if (!isPalindrome("AoXomOxOa")) {
        std::cout << "isPalindrome() FAIL" << std::endl;
    }
    if (isPalindrome("gungt")) {
        std::cout << "isPalindrome() FAIL" << std::endl;
    }
    if (!isPalindrome("aoxooxoa")) {
        std::cout << "isPalindrome() FAIL" << std::endl;
    }
    if (isPalindrome("gugt")) {
        std::cout << "isPalindrome() FAIL" << std::endl;
    }

    int set[] = {3, 6, 8, 5};
    if (!member(5, set, 4)) {
        std::cout << "member() FAIL" << std::endl;
    }
    int set2[] = {3, 6, 8, 9};
    if (member(5, set2, 4)) {
        std::cout << "member() FAIL" << std::endl;
    }

    int numbers[] = {1, 2, 3, 4};
    if (replace(3, 5, numbers, 4) != 1) {
        std::cout << "replace() FAIL" << std::endl;
    }
    if (numbers[2] != 5) {
        std::cout << "replace() FAIL" << std::endl;
    }

    if (gcd(20, 15) != 5) {
        std::cout << "gcd() FAIL" << std::endl;
    }
    if (gcd(7, 6) != 1) {
        std::cout << "gcd() FAIL" << std::endl;
    }

    if (helloWorldRepeat(3) != "Hello Hello Hello World World World") {
        std::cout << "helloWorldRepeat() FAIL" << std::endl;
    }

    if (convert2Binary(25) != "11001") {
        std::cout << convert2Binary(25) << std::endl;
        std::cout << "convert2Binary() FAIL" << std::endl;
    }
    if (convert2Binary(0) != "0") {
        std::cout << convert2Binary(0) << std::endl;
        std::cout << "convert2Binary() FAIL" << std::endl;
    }
    if (convert2Binary(1) != "1") {
        std::cout << convert2Binary(1) << std::endl;
        std::cout << "convert2Binary() FAIL" << std::endl;
    }
    if (convert2Binary(2) != "10") {
        std::cout << convert2Binary(2) << std::endl;
        std::cout << "convert2Binary() FAIL" << std::endl;
    }

    int a[] = {4, 7, 8, 0};
    int b[] = {0, 8, 7, 4};
    reverseArray(a, 0, 3);
    for (size_t x = 0; x < 4; ++x) {
        if (a[x] != b[x]) {
            std::cout << "reverseArray() FAIL" << std::endl;
        }
    }
    int c[] = {4, 7, 8, 0, 1};
    int d[] = {1, 0, 8, 7, 4};
    reverseArray(c, 0, 4);
    for (size_t x = 0; x < 5; ++x) {
        if (c[x] != d[x]) {
            std::cout << "reverseArray() FAIL" << std::endl;
        }
    }

    int f[] = {0, 9, 9, 4};
    arrayInitialize(b, 9, 1, 2);
    for (size_t x = 0; x < 4; ++x) {
        if (b[x] != f[x]) {
            std::cout << "arrayInitialize() FAIL" << std::endl;
        }
    }
    int e[] = {1, 9, 9, 9, 4};
    arrayInitialize(d, 9, 1, 3);
    for (size_t x = 0; x < 5; ++x) {
        if (d[x] != e[x]) {
            std::cout << "arrayInitialize() FAIL" << std::endl;
        }
    }

    if (binomialCoeff(4, 2) != 6) {
        std::cout << "binomialCoeff() FAIL" << std::endl;
    }

    if (count2(222212) != 8) {
        std::cout << "count2() FAIL" << std::endl;
    }
    if (count2(2212) != 4) {
        std::cout << "count2() FAIL" << std::endl;
    }
    if (count2(212) != 2) {
        std::cout << "count2() FAIL" << std::endl;
    }
    if (count2(122) != 3) {
        std::cout << "count2() FAIL" << std::endl;
    }
    if (count2(3453) != 0) {
        std::cout << "count2() FAIL" << std::endl;
    }
    if (count2(0) != 0) {
        std::cout << "count2() FAIL" << std::endl;
    }

    int bruh[] = {2, 4, 16, 256};
    if (!relatedSquares(bruh, 4)) {
        std::cout << "relatedSquares() FAIL" << std::endl;
    }
    int hi[] = {2, 4, 16, 259};
    if (relatedSquares(hi, 4)) {
        std::cout << "relatedSquares() FAIL" << std::endl;
    }

    if (sumArray(bruh, 4) != 278) {
        std::cout << "sumArray() FAIL" << std::endl;
    }
    int roh[] = {1, 6, 3};
    if (sumArray(roh, 3) != 10) {
        std::cout << "sumArray() FAIL" << std::endl;
    }
    int om[] = {1};
    if (sumArray(om, 1) != 1) {
        std::cout << "sumArray() FAIL" << std::endl;
    }

    if (countSubs("catcowcat", "cat") != 2) {
        std::cout << "countSubs() FAIL" << std::endl;
    }
    if (countSubs("catcatca t", "cat") != 2) {
        std::cout << "countSubs() FAIL" << std::endl;
    }

    if (moveXs("rtxxxohxpx") != "rtohpxxxxx") {
        std::cout << "moveXs() FAIL" << std::endl;
    }
    if (moveXs("thnsporth") != "thnsporth") {
        std::cout << "moveXs() FAIL" << std::endl;
    }

    if (countTheWays(2, 2) != 2) {
        std::cout << "countTheWays() FAIL" << std::endl;
    }

    if (countTheWays(5, 5) != 70) {
        std::cout << "countTheWays() FAIL" << std::endl;
    }

    //************************************************************************
    std::cout << "Testing sumArray: ";
    int test[5] = {1, 2, 3, 4, 5};
    if (sumArray(test,5) == 15)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;

    //************************************************************************
    std::cout << "Testing member: ";
    int donaldTrump[10] = {12, 13, 21, 30, 2, 55, 1000, 5, 201, 789};
    if (member(55, donaldTrump, 10))
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;

    //************************************************************************
    std::cout << "Testing isPalindrome: ";
    std::string my_str("abcdeedcba");
    if (isPalindrome(my_str))
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;

    //************************************************************************
    std::cout << "Testing harmonicSum: ";
    double epsilon = 0.000000001;
    if (std::abs(harmonicSum(20) - double(55835135)/double(15519504)) < epsilon)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;

    std::cout << "Testing harmonicSum: ";
    std::cout << "the first 4 Harmonic sums are:" << std::endl;
    for (size_t i=1; i<5; i++) {
        std::cout << harmonicSum(i) << std::endl;
    }

    //************************************************************************
    std::cout << "Testing addStar: ";
    if (addStar("abc")=="a*b*c")
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing replace: ";
    int tmpR[10] = {12, 13, 21, 30, 2, 55, 1000, 5, 201, 789};
    size_t k3 = replace(2, 3, tmpR, 10);
    if (k3 == 1 && tmpR[4] == 3)
        std::cout << "Pass" << std::endl;
    else
        std::cout << "Fail" << std::endl;

    //************************************************************************
    std::cout << "Testing gcd: ";
    if (gcd(24,30) == 6)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;

    //************************************************************************
    std::cout << "Testing helloWorldRepeat: ";
    if (helloWorldRepeat(3) == "Hello Hello Hello World World World")
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing convert2Binary: ";
    if (convert2Binary(25) == "11001")
        std::cout << "Pass" << std::endl;
    else
        std::cout << "Fail" << std::endl;


    //************************************************************************
    std::cout << "Testing printPattern: ";
    std::cout << "A four star hourglass pattern: " << std::endl;
    printPattern(4);
    std::cout << std::endl;


    //************************************************************************
    std::cout << "Testing reverseArray: ";
    int tmp2[10] = {789, 201, 5, 1000, 55, 2, 30, 21, 13, 12};
    int tmp3[10] = {12, 13, 21, 30, 2, 55, 1000, 5, 201, 789};
    reverseArray(tmp2, 0, 9);
    bool okay = true;
    for (int k=0; k<10; k++)
    {
        if (tmp2[k] != tmp3[k])
            okay = false;
    }
    if (okay)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing arrayInitialize: ";
    int testI[100];
    for (int k=0; k<100; k++)
        testI[k] = 0;
    arrayInitialize(testI, 5, 20, 80);
    bool OK = true;
    for (int k=0; k<20; k++)
        if (testI[k]!=0)
            OK = false;
    for (int k=20; k<=80; k++)
        if (testI[k]!=5)
            OK = false;
    for (int k=81; k<100; k++)
        if (testI[k]!=0)
            OK = false;
    if (OK)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;



    //************************************************************************
    std::cout << "Testing binomialCoeff: ";
    if (binomialCoeff(4,2)==6)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing count2: ";
    if (count2(212)==2)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing relatedSquares: ";
    int arr1[4] = {3, 9, 81, 6561};
    if (relatedSquares(arr1, 4)) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }


    //************************************************************************
    std::cout << "Testing countSubs: ";
    if (countSubs("catcowcat","cat")==2)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing moveXs: ";
    if (moveXs("xxre")=="rexx")
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing newton: ";
    if (std::abs(newton(33333, 10) - std::sqrt(33333)) < 0.00001)   // test that Newton's approximate is within 0.00001 of actual
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    std::cout << "Testing countTheWays: ";
    if (countTheWays(2,2) == 2)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    //************************************************************************
    //************************************************************************
    // create a linked list
    NodePtr head = nullptr;
    NodePtr tmpPtr;
    size_t cnt = 0;
    for (int k=0; k<20; k++)
    {
        tmpPtr = new Node;
        assert(tmpPtr);
        tmpPtr->value = ((k%3)==0) ? 0 : k%10;
        if (tmpPtr->value != 0) cnt++;
        tmpPtr->next = head;
        head = tmpPtr;
    }
    if (cnt==0) {}
    //************************************************************************
    //************************************************************************
    //************************************************************************


    //************************************************************************
    std::cout << "Testing numOfTerms: ";
    if (numOfTerms(head) == cnt)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;

    std::cout << "Testing numOfTerms again: ";
    NodePtr head4 = nullptr;
    if (numOfTerms(head4) == 0)
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;
    delete head4;



    //************************************************************************
    //************************************************************************
    //************************************************************************
    // add some zeros at the end
    for (tmpPtr = head; tmpPtr->next!=nullptr; tmpPtr=tmpPtr->next)
    {} // nothing to do
    for (size_t i=0; i<6; i++) {
        auto newPtr = new Node;
        newPtr->value = 0;
        newPtr->next = tmpPtr->next;
        tmpPtr->next = newPtr;
    }
    //************************************************************************
    //************************************************************************
    //************************************************************************


    //************************************************************************
    std::cout << "Testing normalizeBigNum: ";
    std::cout << "These two lists should be identical except for zeros at the end" << std::endl;
    printList(head);
    normalizeBigNum(head);
    printList(head);


    //************************************************************************
    //************************************************************************
    //************************************************************************
    // free the linked list
    while (head != nullptr)
    {
        NodePtr tmp7 = head;
        head = head->next;
        delete tmp7;
    }



    //************************************************************************
    // create a new linked list
    NodePtr head2 = nullptr;
    NodePtr tmpPtr2;
    for (int k=3; k>0; k--)
    {
        tmpPtr2 = new Node;
        assert(tmpPtr2);
        tmpPtr2->value = k;
        tmpPtr2->next = head2;
        head2 = tmpPtr2;
    }
    //************************************************************************
    //************************************************************************
    //************************************************************************


    //************************************************************************
    std::cout << "Testing echo2: ";
    if (echo2(head2) == "1 2 3 3 2 1 ")
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;

    //************************************************************************
    //************************************************************************
    //************************************************************************
    // free the linked list
    while (head2 != nullptr) {
        NodePtr tmp7 = head2;
        head2 = head2->next;
        delete tmp7;
    }
    //************************************************************************
    //************************************************************************
    //************************************************************************

    std::cout << "Testing echo2 again: ";
    NodePtr head3 = nullptr;
    if (echo2(head3).empty())
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;
    delete head3;


    //************************************************************************
    // create 2 new linked lists
    NodePtr super = nullptr;
    NodePtr sub = nullptr;
    NodePtr tmpPtr3;
    for (int k=30; k>0; k=k-3)
    {
        tmpPtr3 = new Node;
        tmpPtr3->value = k;
        tmpPtr3->next = super;
        super = tmpPtr3;
        tmpPtr3 = new Node;
        tmpPtr3->value = k-2;
        tmpPtr3->next = super;
        super = tmpPtr3;
        tmpPtr3 = new Node;
        tmpPtr3->value = k;
        tmpPtr3->next = sub;
        sub = tmpPtr3;
    }
    //************************************************************************
    //************************************************************************
    //************************************************************************


    //************************************************************************
    std::cout << "Testing contains: ";
    if (contains(super,sub))
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    //************************************************************************
    //************************************************************************
    // free the linked lists
    while (super != nullptr) {
        NodePtr tmp7 = super;
        super = super->next;
        delete tmp7;
    }
    while (sub != nullptr) {
        NodePtr tmp7 = sub;
        sub = sub->next;
        delete tmp7;
    }
    //************************************************************************
    //************************************************************************
    //************************************************************************



    //************************************************************************
    // create 2 new linked lists
    NodePtr super2 = nullptr;
    NodePtr sub2 = nullptr;
    NodePtr tmpPtr32;
    for (int k=30; k>0; k=k-3)
    {
        tmpPtr32 = new Node;
        tmpPtr32->value = k;
        tmpPtr32->next = super2;
        super2 = tmpPtr32;
        tmpPtr32 = new Node;
        tmpPtr32->value = k-2;
        tmpPtr32->next = super2;
        super2 = tmpPtr32;
        tmpPtr32 = new Node;
        tmpPtr32->value = k-1;
        tmpPtr32->next = sub2;
        sub2 = tmpPtr32;
    }
    //************************************************************************
    //************************************************************************
    //************************************************************************


    //************************************************************************
    std::cout << "Testing contains again: ";
    if (!contains(super2,sub2))
        std::cout << "Pass " << std::endl;
    else
        std::cout << "Fail " << std::endl;


    //************************************************************************
    //************************************************************************
    //************************************************************************
    // free the linked lists
    while (super2 != nullptr) {
        NodePtr tmp7 = super2;
        super2 = super2->next;
        delete tmp7;
    }
    while (sub2 != nullptr) {
        NodePtr tmp7 = sub2;
        sub2 = sub2->next;
        delete tmp7;
    }
    //************************************************************************
    //************************************************************************
    //************************************************************************




#if CHALLENGE==1

    std::cout << "Challenge Test: These two lists should be the reverse of each other:" << std::endl;
    // free the linked list
    while (head != nullptr)
    {
        NodePtr tmp = head;
        head = head->next;
        delete tmp;
    }
    // give the list new data
    for (int k = 0; k<20; k++)
    {
        tmpPtr = new Node;
        tmpPtr->value = ((k % 2) == 0) ? -k : k;
        if (tmpPtr->value != 0) cnt++;
        tmpPtr->next = head;
        head = tmpPtr;
    }

    printList(head);
    head=reverseList(head);
    printList(head);
    std::cout << std::endl;

    // free the linked list
    while (head != nullptr)
    {
        NodePtr tmp = head;
        head = head->next;
        delete tmp;
    }

#endif


    std::cout << "\n\nDone testing" << std::endl;

//      std::cout << "press enter to exit";
//      std::cin.get();



    return 0;
}


// print a space-separated list of numbers from a linked-list
void printList(NodePtr head)
{

    std::cout << "contents of list: ";
    for (NodePtr cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->value << " ";
    }
    std::cout << " Done" << std::endl;

}
