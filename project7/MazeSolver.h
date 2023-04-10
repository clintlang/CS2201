// File name: MazeSolver.h
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 7
// Honor Statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Description: declares functions to solve a maze
// Last Changed: April 5th, 2023


#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "PointAgenda.h"
#include "Maze.h"


class MazeSolver
{
    Maze& maze;
    PointAgenda& agenda;

    public:

        // constructor
        // pre: accepts a Maze and a PointAgenda
        // post: MazeSolver is created and initialized
        MazeSolver(Maze& newMaze, PointAgenda& newAgenda);

        // solves maze
        // pre: instantiated Maze object
        // post: lists all visited points and prints count of visited points. ALso prints
        // if the ending point is reachable or unreachable.
        bool solve(bool trace);
};


#endif /* ifndef */