// File name: DnaNode.h
// Author: Prof. Roth
// VUnetid: rothgh
// Email: j.roth@vanderbilt.edu
// Class: CS2201
// Date: Feb 2023
// Honor statement: This file was provided by the instructor for my use
// Assignment Number: 3
// Description: This declares the structure of a node of our linked list.

#ifndef DNANODE_H
#define DNANODE_H

// DO NOT CHANGE THIS FILE
// DO NOT CHANGE THIS FILE

// the structure of a linked list node contains a single char and a next pointer

struct DnaNode {
    char val;
    DnaNode *next;
};

typedef DnaNode* DnaNodePtr;

// DO NOT CHANGE THIS FILE
// DO NOT CHANGE THIS FILE

#endif //DNANODE_H
