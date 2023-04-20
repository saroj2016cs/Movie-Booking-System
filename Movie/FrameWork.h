#pragma once
#include<iostream>
#include<string>
using namespace std;

class FrameWork
{
    //Convert a string to a word with all lowercase characters
    //and First character as Uppercase
    string toWord(string s);

    //Check if a string is number or not
    bool isNum(string s);
public:

    //It allows the content creator or 
    //the movies database creators to 
    //make entries for a movie and 
    //the theatres playing the movie.
    void FrontEnd(MovieList& m);

    //A client interaction of the Movie Booking System
    //It display the list of movies
    //It allows the clients to choose a movie
    //It allows the clients to see the list of theatres playing this movie
    //It allows to slecet the Threatre
    //It allows to book the seat and provide a response if booked or not
    //While movie List displayed: Enter Quit to exit the booking system
    //While seat numbers are displayed, enter q to go to main menu
    void BackEnd(MovieList& m);
};