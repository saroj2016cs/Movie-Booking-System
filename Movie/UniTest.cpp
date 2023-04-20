
#include <iostream>
#include "UnitTest.h"
#include "MovieList.h"
using namespace std;
bool UnitTest::Test_Movie_and_theatre_Insertion()
{
	MovieList m;
	string movieName = "Avataar";
	string theatre1 = "Chennai";
	string theatre2 = "Bangalore";
	string theatre3 = "Central";

	string Theatres = theatre1 + " " + theatre2 + " " + theatre3;
	m.insertMovie("Avataar", "Chennai Bangalore Central");

	auto movies = m.getMovies();
	auto it = movies.find(movieName);
	if (it == movies.end())
	{
		cout << "FAIL: Movie name " << movieName << " is not found after insertion." << endl;
		return false;
	}
	auto TheatreList = it->second.getTheatreList();
	auto th1 = TheatreList.find(theatre1);
	auto th2 = TheatreList.find(theatre1);
	auto th3 = TheatreList.find(theatre1);

	if (th1 == TheatreList.end() || th2 == TheatreList.end() || th3 == TheatreList.end())
	{
		cout << "FAIL: Movie name " << movieName << " does not have the added theatres." << endl;
		return false;
	}
	return true;
}
bool UnitTest::TestTheatreClass()
{
	string theatreName = "Chennai";
	Theatre t(theatreName);

	if (theatreName.compare(t.getName()) != 0)
	{
		cout << "FAIL: Theatre object could not be created with a given name " << theatreName << endl;
		return false;
	}
	return true;
}
bool UnitTest::TestMovieClass()
{
	unordered_map<string, Theatre> TheatreList;
	string theatre1 = "Chennai";
	string theatre2 = "Bangalore";
	TheatreList.insert({ theatre1, Theatre(theatre1) });
	TheatreList.insert({ theatre2, Theatre(theatre2) });
	string movieName = "Harry Potter";
	Movie m(movieName, TheatreList);
	if (movieName.compare(m.getName())!=0)
	{
		cout << "FAIL: Movie name " << movieName << " could not be found after insertion." << endl;
		return false;
	}
	auto& tl = m.getTheatreList();
	auto it1 = tl.find(theatre1);
	auto it2 = tl.find(theatre2);
	if(it1 == tl.end())
	{
		cout << "FAIL: Theatre name " << theatre1 << " could not be found after insertion." << endl;
		return false;
	}
	if (it2 == tl.end())
	{
		cout << "FAIL: Theatre name " << theatre2 << " could not be found after insertion." << endl;
		return false;
	}
	return true;
}
bool UnitTest::TestBookingTicket()
{
	MovieList m;
	string movieName = "Avataar";
	string theatre1 = "Chennai";
	string theatre2 = "Bangalore";
	string theatre3 = "Central";

	string Theatres = theatre1 + " " + theatre2 + " " + theatre3;
	m.insertMovie("Avataar", "Chennai Bangalore Central");
	auto &movies = m.getMovies();
	auto it = movies.find(movieName);
	if (it == movies.end())
	{
		cout << "FAIL: Movie name " << movieName << " is not found after insertion." << endl;
		return false;
	}
	auto &TheatreList = it->second.getTheatreList();
	auto th1 = TheatreList.find(theatre1);
	auto& theatre = th1->second;
	bool booked = false;
	booked = theatre.bookseat("A21");
	if (booked)
	{
		cout << "FAIL: Out of range booking is successful.A21" << endl;
		return false;
	}
	booked = theatre.bookseat("A0");
	if (booked)
	{
		cout << "FAIL: Out of range booking is successful. A0" << endl;
		return false;
	}
	booked = theatre.bookseat("A1");
	if (!booked)
	{
		cout << "FAIL: Unable to book ticket. A1" << endl;
		return false;
	}
	booked = theatre.bookseat("A20");
	if (!booked)
	{
		cout << "FAIL:  Unable to book ticket. A20" << endl;
		return false;
	}
	theatre.bookseat("A2-A6");
	bool booked2 = theatre.bookseat("A2");
	bool booked3 = theatre.bookseat("A3");
	bool booked4 = theatre.bookseat("A4");
	bool booked5 = theatre.bookseat("A5");
	bool booked6 = theatre.bookseat("A6");
	if (booked2 || booked3 || booked4 || booked5 || booked6)
	{
		cout << "FAIL: Range booking is not successful." << endl;
		return false;
	}
	return true;
}


void UnitTest::PerformTest()
{
	cout << "Unit Testing in progress..." << endl;
	int total = 4;
	int pass = 0;
	pass += Test_Movie_and_theatre_Insertion() == true ? 1 : 0;
	pass += TestTheatreClass() == true ? 1 : 0;
	pass += TestMovieClass() == true ? 1 : 0;
	pass += TestBookingTicket() == true ? 1 : 0;

	if (pass == total)
		cout << "Unit Test has been successful with 100%." << endl;
	else
		cout << "Unit Test has failures: " << pass << "/" << total << " has passed." << endl;
}

