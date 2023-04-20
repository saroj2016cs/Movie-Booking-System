#pragma once
#include "Theatre.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// Capture the details of movie and store in Movie class
// Movie details will be stored and displayed from Movie class
// This will be further used in the movie list.
class Movie
{
    string name;
    string description;
    unordered_map<string, Theatre> theatreList;
public:

    //Constructor for adding the movie and its playing theatre list
    Movie(string name, unordered_map<string, Theatre> theatreList);

    //Copy Constructor
    Movie(const Movie& m);

    //R-Value Constructor
    Movie(const Movie&& m);

    //Get the name of the Movie
    string getName();

    //Get a Description of the Movie
    string getDescription();

    //Get a handle to the List of Theatres playing this movie
    unordered_map<string, Theatre> &getTheatreList();

    //Diplay the theatres playing this movie
    void displayTheatreList();
};