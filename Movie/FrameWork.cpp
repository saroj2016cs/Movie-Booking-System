//Convert a string to lower case and convert the first character as uppercase
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include "MovieList.h"
#include "Movie.h"
#include "Theatre.h"
#include "UnitTest.h"
#include "FrameWork.h"
using namespace std;

string FrameWork::toWord(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s[0] = toupper(s[0]);
    return s;
}

//Check if a string is number or not
bool FrameWork::isNum(string s)
{
    for (auto a : s)
        if (a < '0' || a>'9')
            return false;
    return true;
}

//It allows the content creator or 
//the movies database creators to 
//make entries for a movie and 
//the theatres playing the movie.
void FrameWork::BackEnd(MovieList& m)
{
    m.insertMovie("Avataar", "Chennai Bangalore Central");
    m.insertMovie("Gladiator", "Chennai Bangalore Noida");
    m.insertMovie("Avengers", "Secunderabad Hyderabad Golconda");
    m.insertMovie("Titanic", "Juhu Marina Malad");
    m.insertMovie("Robot", "Belandur Hyderabad Golconda");
    m.insertMovie("Malan", "Secunderabad Hyderabad Golconda");
    m.insertMovie("Fighters", "Belandur Golconda Secunderabad Hyderabad");
}


//A client interaction of the Movie Booking System
//It display the list of movies
//It allows the clients to choose a movie
//It allows the clients to see the list of theatres playing this movie
//It allows to slecet the Threatre
//It allows to book the seat and provide a response if booked or not
//While movie List displayed: Enter Quit to exit the booking system
//While seat numbers are displayed, enter q to go to main menu
void FrameWork::FrontEnd(MovieList& m)
{
    
    while (1)
    {
        m.display();
        cout << "Type Quit for closing this app. " << endl;

        //Prompt the user input for the Movie Name
        cout << "Enter movie name (eg Avataar) : " << endl;
        string movieName;

        //Capture the movie name
        getline(cin, movieName);
        string s1 = movieName;
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);

        //Quit the application, if user enters quit
        if (s1.compare("quit") == 0)
            break;

        //Look for the Movie name in the existing movie Lists
        unordered_map<string, Movie>& movies = m.getMovies();

        //If user has entered a number for the Movie ptocess it accordingly
        if (isNum(movieName))
        {
            int num = stoi(movieName);
            int i = 1;
            for (auto a : movies)
            {
                if (i == num)
                {
                    movieName = a.first;
                    cout << "Movie slected : " << movieName << endl;
                }
                i++;
            }
        }
        //Find the movie object based on its Movie Name
        unordered_map<string, Movie>::iterator movie = movies.find(toWord(movieName));
        if (movie == movies.end())
        {
            cout << "ERROR: Movie name entered does not exist." << endl;
            continue;
        }
        Movie& movieObject = movie->second;
        auto& theatreList = movieObject.getTheatreList();
        movieObject.displayTheatreList();

        //Prompt the user input for the Theatre Name
        cout << "Enter theatre name : " << endl;
        string theatreName;

        //Capture the theatre name
        getline(cin, theatreName);

        //Find the theatre name if a number is entered
        if (isNum(theatreName))
        {
            int num = stoi(theatreName);
            int i = 1;
            for (auto a : theatreList)
            {
                if (i == num)
                {
                    theatreName = a.first;
                    cout << "Theatre selected : " << theatreName << endl;
                }
                i++;
            }
        }
        auto theatre = theatreList.find(toWord(theatreName));
        if (theatre == theatreList.end())
        {
            cout << "ERROR: Theatre name entered does not exist." << endl;
            continue;
        }
        theatre->second.displaySeats();
        while (1)
        {
            //Prompt the user input for the seat numbers
            cout << "Enter \'q\' to go to Movie List. " << endl;
            cout << "Enter seat numbers (eg Single:\"A1\"  Multiple:\"A1,A17,A20\" Range based:\"A3-A13\"): " << endl;
            string seatNumber;

            //Capture the seat number
            getline(cin, seatNumber);
            if ((seatNumber.compare("q") == 0) || (seatNumber.compare("Q") == 0))
                break;
            theatre->second.bookseat(seatNumber);
        }
    }
}
