#include "Flight.h"

void Flight::free() {
	delete[] origin;
	delete[] destination;
}
void Flight::copyFrom(const Flight& other) {
	const size_t originSIZE = strlen(other.origin) + 1;
	const size_t destSIZE = strlen(other.destination) + 1;
	try {
		origin = new char[originSIZE];
	}
	catch (std::bad_alloc) {
		throw;
	}
	try {
		destination = new char[destSIZE];
	}
	catch (std::bad_alloc) {
		delete[] origin;
		throw;
	}
	strcpy_s(origin, originSIZE, other.origin);
	strcpy_s(destination, destSIZE, other.destination);
}
Flight::Flight()
	: id(0), duration_minutes(0), origin(nullptr), destination(nullptr),
	flightSection{ businessClass,firstClass,premiumEconomyClass,economyClass }
{
}

Flight::Flight(const Flight& other)
	:id(other.id), duration_minutes(other.duration_minutes),
	flightSection{ other.flightSection[0], other.flightSection[1], other.flightSection[2], other.flightSection[3] },
	date(other.date)
{
	try {
		copyFrom(other);
	}
	catch (std::bad_alloc) {
		throw;
	}
}
Flight& Flight::operator=(const Flight& other) {
	if (this != &other) {
		free();
		try {
			copyFrom(other);
		}
		catch (std::bad_alloc) {
			throw;
		}
	}
	id = other.id;
	duration_minutes = other.duration_minutes;
	for (size_t i = 0; i < MAX_SECTIONS; ++i) {
		flightSection[i] = other.flightSection[i];
	}
	date = other.date;
	return *this;
}
Flight::~Flight() {
	free();
}
Flight::Flight(int id, int dur, const char* orig, const char* dest, size_t day, size_t month, size_t year)
	:id(id), duration_minutes(dur), date(day, month, year)
{	
	for (size_t i = 0; i < MAX_SECTIONS; ++i) {
			FlightSection tmp(i);
			flightSection[i] = tmp;
	}
	const size_t originSIZE = strlen(orig) + 1;
	const size_t destSIZE = strlen(dest) + 1;
	try {
		origin = new char[originSIZE];
	}
	catch (std::bad_alloc) {
		throw;
	}
	try {
		destination = new char[destSIZE];
	}
	catch (std::bad_alloc) {
		delete[] origin;
		throw;
	}
	strcpy_s(origin, originSIZE, orig);
	strcpy_s(destination, destSIZE, dest);
}
const char* Flight::get_origin() const {

	return origin;
}
const char* Flight::get_destination() const {
	return destination;
}
int Flight::get_id() const {
	return id;
}
int Flight::get_duration() const {
	return duration_minutes;
}
void Flight::printDate() const{
	std::cout << date.get_day() << '.'
		<< date.get_month() << '.'
		<< date.get_year();
}