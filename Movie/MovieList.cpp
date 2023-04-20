#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "MovieList.h"

using namespace std;
#define FAINT     "\033[2m"
#define BOLD      "\033[1m"
#define UNDERLINE "\033[4m"
#define CLOSE     "\033[0m"

#define ERROR     "\tERROR"



void MovieList::display()
{
	cout << BOLD << "Movies List:" << CLOSE << endl;
	int i = 0;
	for (auto movie : movies)
	{
		cout << "\t"<<i + 1 << "  ";
		cout << movie.second.getName() << "  ";
		cout << movie.second.getDescription() << endl;
		i++;
	}
}
void MovieList::insertMovie()
{
	cout << "Enter movie name " << endl;
	string movieName;
	getline(cin, movieName);
	cout << "Enter Threatre names (space separated) " << endl;
	string theatres;
	getline(cin, theatres);
	insertMovie(movieName, theatres);
}
void MovieList::insertMovie(string movieName, string theatres)
{
	auto movieFinder = movies.find(movieName);
	if (movieFinder != movies.end())
	{
		cout << ERROR<<"Movie with name " << movieName << " already exists." << endl;
	}
	else
	{
		unordered_map<string, Theatre> TheatreList;
		string theatre;
		// making a string stream
		stringstream iss(theatres);

		while (iss >> theatre)
		{
			//cout << theatre << endl;
			TheatreList.insert({ theatre, Theatre(theatre) });
		}
		Movie m(movieName, TheatreList);
		movies.insert({ movieName, m });
	}

}
unordered_map<string, Movie> & MovieList::getMovies()
{
	return movies;
}