#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "Movie.h"
#include "Theatre.h"

using namespace std;


class MovieList
{
	unordered_map<string, Movie> movies;
public:
	//To display the list fo Movies
	void display();

	//Use this method to insert a Movie manually
	void insertMovie();

	//For adding a new Movie to the movie list
	//Provide the movie name and the list of theatres (space separated)
	void insertMovie(string movieName, string theatres);

	//Get handle of the Movies map
	unordered_map<string, Movie> & getMovies();
};