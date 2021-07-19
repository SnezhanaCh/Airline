#include <iostream>
#include "Airport.h"
#include <exception>

Airport::Airport(const char* aname) {
	if (strlen(aname)>=MAX_NAME) {
		throw std::invalid_argument("Airport name is too long.\n");
	}
	strcpy_s(airportName, MAX_NAME, aname);
}
Airport::Airport(const Airport& other) {
	
	strcpy_s(airportName, MAX_NAME, other.airportName);
}
Airport& Airport::operator=(const Airport& other) {
	if (this != &other) {
		strcpy_s(airportName, MAX_NAME, other.airportName);
	}
	return *this;
}
const char* Airport::get_name() {
	return airportName;
}