#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

class Theatre
{
	string name;
	string address;
	vector<bool> seatsBooked;
	int count;
public:
	//Detect if it is hosefull
	bool isHousefull();

	//Constructor for a theatre
	Theatre(string name);


	//Get the Theatre name
	string getName();

	//set the name of the theatre
	string setName(string name);

	//Book a given seat
	bool bookseat(string seat);

	//book the given seat in integer format
	bool bookseat(int seat_number, string seat);

	//return the address of the theatre
	string getAddress();

	//Display the booked seats and available seats
	void displaySeats();

	//Validate if the seat number is valid or not
	bool validateSeat(string seat);


	//trim a string from beginning and end
	void trim(string& s);

};
