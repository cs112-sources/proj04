/*
 * App.cpp
 *
 *  Created on: Feb 27, 2020
 *      Author: vtn2
 */

#include "App.h"
#include <iostream>
#include "Vec.h"
using namespace std;

App::App() {}

void App::run() {
    unsigned numDims = printInstructions();
    Vec startingPos = getStartingPosition(numDims);
    Vec resultingPos = getVectors(startingPos);
    printResults(startingPos, resultingPos);
}

unsigned App::printInstructions() {
    unsigned numDims;
    cout << "This application simulates how to move through space by\nadding "
            "together any number of vectors of a given size."
         << endl;
    cout << "How many dimensions would you like to work with? ";
    cin >> numDims;
    return numDims;
}

Vec App::getStartingPosition(unsigned numDims) {
    cout << "Enter starting position: " << endl;
    return getVectorFromUser(numDims);
}

Vec App::getVectorFromUser(unsigned numDims) {
    // TODO
}

Vec App::getVectors(const Vec& startVec) {
    char yorn;
    Vec res(startVec);
    while (true) {
        cout << "Do you want to enter another vector? (y/n): ";
        cin >> yorn;
        if (yorn == 'y') {
            Vec v = getVectorFromUser(startVec.getSize());
            // UNCOMMENT THIS NEXT LINE WHEN YOU HAVE IMPLEMENTED operator+
            // res = res + v;
        } else {
            break;
        }
    }
    return res;
}

void App::printResults(const Vec &start, const Vec &end) {
    // TODO
}