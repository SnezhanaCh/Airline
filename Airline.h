#ifndef _AIRLINE_HEADER_
#define _AIRLINE_HEADER_
#include "Flight.h"
#include "Airport.h"

class Airline {
	static const int MAX_FLIGHTS = 50;
	Flight** flights;
	size_t counter;
	Airport airport;
public:
	Airline();
	Airline(const Airline&);
	Airline& operator=(const Airline&);
	~Airline();
	void addFlight(const Flight&, Airport&);
	void printFlight(const Flight&);
private:
	void copyFrom(const Airline&);
	void free();
	//TODO ReserveSpot
	void reserveSpot();
};
#endif // !_AIRLINE_HEADER_
