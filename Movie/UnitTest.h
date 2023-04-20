
#pragma once

class UnitTest
{
	//Testing for inserting a movie nd its respective theatres
	bool Test_Movie_and_theatre_Insertion();

	//Tesing for checking if the Theatre class functionality works fine
	bool TestTheatreClass();

	//Tesing for checking if the Movie class functionality works fine
	bool TestMovieClass();

	//Tesing for checking if the ticket booking is working fine or not
	bool TestBookingTicket();

public:

	//Perform the Unit Testing
	void PerformTest();
};
