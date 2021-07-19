#ifndef _FLIGHTSECTION_HEADER_
#define _FLIGHTSECTION_HEADER_
#include <iostream>
#include "Seat.h"
#include "Section.h"

class FlightSection {
	static const int MAX_SEAT_SIZE = 50;
	Seat seat[MAX_SEAT_SIZE];
	size_t bookedSeats;
	Section type;

	void createSeats();
	void copyFrom(const FlightSection& other);
	void lowerToUpperCase(char& ch);
public:
	FlightSection();
	FlightSection(size_t);
	FlightSection(const FlightSection&);
	FlightSection& operator=(const FlightSection&);
	size_t get_numofBookedSeats() const;
	Section get_type() const;
	bool hasAvailableSeats();
	bool isSuccessfullyBooked(int, char);
	void bookRandom();
};

#endif // !_SEAT_HEADER_