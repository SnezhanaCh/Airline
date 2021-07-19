#include "FlightSection.h"
#include <cassert>

int main() {
	//Testing FlightSection::FlightSection();
	FlightSection obj;
	assert(obj.get_numofBookedSeats() == 0);
	assert(obj.hasAvailableSeats() == true);
	obj.bookRandom();
	assert(obj.get_numofBookedSeats() == 1);

	//Testing FlightSection::FlightSection(Section type);
	FlightSection obj2(premiumEconomyClass);
	assert(obj2.get_numofBookedSeats() == 0);
	assert(obj2.get_type()== premiumEconomyClass);
	assert(obj2.hasAvailableSeats() == true);
	obj2.bookRandom();
	assert(obj2.get_numofBookedSeats() == 1);
	
	//Testing FlightSection::FlightSection& operator=(const FlightSection&);
	obj = obj2;
	assert(obj.get_numofBookedSeats() == 1);
	assert(obj.get_type() == premiumEconomyClass);
	assert(obj.hasAvailableSeats() == true);

	//Testing FlightSection::bookRandom();
	obj.bookRandom();
	assert(obj.get_numofBookedSeats() == 2);
	//Testing FlightSection::isSuccessfullyBooked(int, char)
	obj.isSuccessfullyBooked(3, 'd');
	assert(obj.get_numofBookedSeats() == 3);

	return 0;
}