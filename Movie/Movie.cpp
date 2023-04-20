#pragma once

#include <iostream>
#include "Theatre.h"
#include "Movie.h"
// Capture the details of movie and store in Movie class
// Movie details will be stored and displayed from Movie class
// This will be further used in the movie list.

Movie::Movie(string name, unordered_map<string, Theatre> theatreList)
{
    this->name = name;
    this->theatreList = theatreList;
}
Movie::Movie(const Movie& m)
{
    this->name = m.name;
    this->theatreList = m.theatreList;
}
Movie::Movie(const Movie&& m)
{
    this->name = m.name;
    this->theatreList = m.theatreList;
}
string Movie::getName() 
{
    return name;
}
string Movie::getDescription()
{
    return description; 
}
unordered_map<string, Theatre>& Movie::getTheatreList()
{
    return theatreList;
}
void Movie::displayTheatreList()
{
    cout << "Theatre List : "<< endl;
    int i = 1;
    for (auto t : theatreList)
    {
        cout <<"\t"<<i<<" "<< t.first << endl;
        i++;
    }
}

