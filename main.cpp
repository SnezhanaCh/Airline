#include "Date.h"
#include "Seat.h"
#include "Section.h"
#include "Flight.h"
#include "FlightSection.h"
#include "Airport.h"
#include "Airline.h"
#include <exception>


int main() {
	Airport SofiaAirport("T01");
	//Flight(ID, DURATION, FROM, TO, DAY, MONTH, YEAR)
	Flight f1(1111, 90, "Sofia", "London", 21, 07, 2021);
	Flight f2(1112, 100, "Sofia", "Bristol", 21, 07, 2021);
	Flight f3(1113, 90, "Sofia", "London", 22, 07, 2021);
	Flight f4(1114, 100, "Sofia", "Bristol", 22, 07, 2021);

	Airline Ryanair;
	Ryanair.addFlight(f1, SofiaAirport);
	Ryanair.addFlight(f2, SofiaAirport);
	Ryanair.addFlight(f3, SofiaAirport);
	Ryanair.addFlight(f4, SofiaAirport);

	//functions must be added
	//TODO:  Airline::reserveSpot();
	
}