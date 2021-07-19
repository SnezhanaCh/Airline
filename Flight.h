#ifndef _FLIGHT_HEADER_
#define _FLIGHT_HEADER_

#include "Date.h"
#include "Seat.h"
#include "Section.h"
#include "FlightSection.h"

class Flight {
	int id;
	int duration_minutes;
	char* origin;
	char* destination;
	FlightSection flightSection[MAX_SECTIONS];
	Date date;
	void free();
	void copyFrom(const Flight& other);
public:
	Flight();
	Flight(const Flight& other);
	Flight(int id, int dur, const char* orig, const char* dest, size_t day, size_t month, size_t year);
	Flight& operator=(const Flight& other);
	~Flight();
	const char* get_origin() const;
	const char* get_destination() const;
	int get_id() const;
	int get_duration() const;
	void printDate() const;
};
#endif // !_FLIGHT_HEADER_
