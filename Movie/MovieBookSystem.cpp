// Movie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MovieList.h"

#include "FrameWork.h"
#include "UnitTest.h"
using namespace std;

int main()
{

    //To Perform Unit Testing uncomment the following two lines
    //UnitTest ut;
    //ut.PerformTest();

    //Create a MovieList object to store the MovieList
    MovieList m;

    FrameWork f;

    //Insert few data about the Movies being played
    //in their respective Theatres
    f.BackEnd(m);

    //Allow clients for the interactive booking of the movie tickets at specific theatre
    f.FrontEnd(m);
    
}

