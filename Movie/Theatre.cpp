#pragma once

#include "Theatre.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;
#define FAINT     "\033[2m"
#define BOLD      "\033[1m"
#define UNDERLINE "\033[4m"
#define CLOSE     "\033[0m"
#define ERROR     "\tERROR: "
#define SUCCESS   "\tSUCCESS: "

bool Theatre::isHousefull()
{
	if (count >= 20)
	{
		return true;
	}
	return false;
}

Theatre::Theatre(string name)
{
	seatsBooked.assign(20, false);
	count = 0;
	this->name = name;
}
string Theatre::getName()
{
	return name;
}
string Theatre::setName(string name)
{
	return this->name = name;
}
bool Theatre::validateSeat(string seat)
{
	if (seat.size() > 1 && (seat[0] == 'a' || seat[0] == 'A'))
	{
		for (int i = 1; i < seat.size(); i++)
		{
			if (seat[i] < '0' || seat[i] > '9')
			{
				cout << ERROR << "Invalid seat number : " << seat << endl;
				return false;
			}
		}
		return true;
	}
	else
		return false;

}
void Theatre::trim(std::string& s) {
	int i = 0;
	int j = s.size() - 1;
	while (i <= j && s[i] == ' ')
		i++;
	while (i <= j && s[j] == ' ')
		j--;
	s = s.substr(i, j - i + 1);
}
bool Theatre::bookseat(string seat)
{
	string hyphen = "-";
	string comma = ",";
	if (seat.find(hyphen) != std::string::npos)
	{
		size_t i = seat.find(hyphen);
		string s1 = seat.substr(0, i);
		string s2 = seat.substr(i + 1, seat.size() - i - 1);
		cout << s1 << " " << s2 << endl;
		if (validateSeat(s1) && validateSeat(s2))
		{
			int ss1 = stoi(s1.substr(1, s1.size() - 1));
			int ss2 = stoi(s2.substr(1, s2.size() - 1));
			if (ss1 >= 1 && ss2 <= 20 && ss1 <= ss2)
			{
				for (int booking = ss1; booking <= ss2; booking++)
				{
					bookseat(booking, "A" + to_string(booking));
				}
			}
			else
			{
				cout << ERROR << "Invalid range of seat number : " << seat << endl;
				return false;
			}
		}
		else
		{
			cout << ERROR << "Invalid seat number : " << seat << endl;
			return false;
		}
	}
	else if (seat.find(comma) != std::string::npos)
	{
		seat += " ";
		std::replace(seat.begin(), seat.end(), ',', ' ');
		std::stringstream ss(seat);

		for (string st; ss >> st;)
		{
			//cout << "SEAT" <<st << endl;
			if (validateSeat(st))
			{
				int seat_number = stoi(st.substr(1, seat.size() - 1));
				bookseat(seat_number, st);
			}
			else
			{
				cout << ERROR << "Invalid seat number : " << seat << endl;
				return false;
			}
		}
	}
	else if (validateSeat(seat))
	{
		int seat_number = stoi(seat.substr(1, seat.size() - 1));
		return bookseat(seat_number, seat);
	}
	else
	{
		cout << ERROR << "Invalid seat number : " << seat << endl;
		return false;
	}
	return true;
}
bool Theatre::bookseat(int seat_number, string seat)
{
	if (seat_number >= 1 && seat_number <= 20)
	{
		if (seatsBooked[seat_number - 1] == false)
		{
			seatsBooked[seat_number - 1] = true;
			count++;
			cout << SUCCESS << "Booked Seat number " << seat << "." << endl;
			return true;
		}
		else
		{
			cout << ERROR << "Seat number " << seat << " is already booked." << endl;
			return false;
		}
	}
	else
		cout << ERROR << "Out of range seat number : " << seat << endl;
	return false;
}
string Theatre::getAddress()
{
	return address;
}
void Theatre::displaySeats()
{
	cout << name << endl;
	for (int i = 0; i < seatsBooked.size(); i++)
	{
		if (seatsBooked[i])
			cout << FAINT << "      A" << setw(2) << i + 1 << setw(8) << "(Booked)" << CLOSE;
		else
			cout << "      A" << setw(2) << i + 1 << setw(8) << "";
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
}
