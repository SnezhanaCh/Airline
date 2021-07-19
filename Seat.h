#ifndef _SEAT_HEADER_
#define _SEAT_HEADER_
#include <iostream>
#include <exception>
class Seat {
	int row;
	char column;
	bool isBooked;
	void copyFrom(const Seat&);
	bool isValid(int, char);
	void lowerToUpperCase(char&);
	static const int MAX_COL = 5;
public:
	Seat();
	Seat(int, char);
	Seat(int, char, bool);
	Seat(const Seat& other);
	Seat& operator=(const Seat&);
	void book_seat();
	char get_column();
	int get_row();
	bool isItBooked();
};

#endif // !_SEAT_HEADER_