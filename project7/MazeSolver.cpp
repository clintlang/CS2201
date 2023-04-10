// File name: MazeSolver.cpp
// Author: Clinton Lang
// userid: langct
// Email: clinton.t.lang@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 7
// Honor Statement: I attest that I understand the honor code for this class and have neither given
//                  nor received any unauthorized aid on this assignment.
// Description: defines functions to solve a maze
// Last Changed: April 5th, 2023


#include "MazeSolver.h"
#include <thread>


// constructor
// pre: accepts a Maze and a PointAgenda
// post: MazeSolver is created and initialized
MazeSolver::MazeSolver(Maze& newMaze, PointAgenda& newAgenda) : maze(newMaze), agenda(newAgenda) {}


// solves maze
// pre: instantiated Maze object
// post: lists all visited points and prints count of visited points. ALso prints
// if the ending point is reachable or unreachable.
bool MazeSolver::solve(bool trace)
{
    int bounds[] = {maze.getNumCols() - 1, maze.getNumRows() - 1};
    agenda.add(maze.getStartLocation());
    int count = 0;

    while (!agenda.isEmpty()) {
        auto point = agenda.peek();

        if (point == maze.getEndLocation()) {
            std::cout << point << "->Solution found!\nNumber of nodes visited: " << ++count << std::endl;
            return true;
        } else if (!maze.hasBeenVisited(point)) {
            if (point.x < bounds[0] && maze.isOpen(point.x + 1, point.y))
                agenda.add(Point(point.x + 1, point.y));
            if (point.x > 0 && maze.isOpen(point.x - 1, point.y))
                agenda.add(Point(point.x - 1, point.y));
            if (point.y < bounds[1] && maze.isOpen(point.x, point.y + 1))
                agenda.add(Point(point.x, point.y + 1));
            if (point.y > 0 && maze.isOpen(point.x, point.y - 1))
                agenda.add(Point(point.x, point.y - 1));

            maze.markVisited(point);
            ++count;
            if (trace) {
                #if defined _WIN32
                    system("cls");
                #elif defined __APPLE__
                    system("clear");
                #endif
                maze.printVisitedMaze();
                std::cout << "Current point: " << point << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            } else {
                std::cout << point << "->";
            }
        } else {
            agenda.remove();
        }
    }

    std::cout << "Solution not found :(\nNumber of nodes visited: " << count << std::endl;
    return false;
}