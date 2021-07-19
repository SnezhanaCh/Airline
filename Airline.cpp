#include "Airline.h"


Airline::Airline() : flights(nullptr), counter(0), airport("###") {
	try {
		flights = new Flight * [MAX_FLIGHTS];
	}
	catch (std::bad_alloc) {
		throw;
	}
}
Airline::Airline(const Airline& other) :airport("###") {
	copyFrom(other);
}
Airline& Airline::operator=(const Airline& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Airline::~Airline() {
	free();
}
void Airline::copyFrom(const Airline& other) {
	flights = new Flight * [other.counter];
	counter = other.counter;
	airport = other.airport;
	for (size_t i = 0; i < counter; ++i) {
		flights[i] = new Flight(*other.flights[i]);
	}
}
void Airline::free() {
	for (size_t i = 0; i < counter; ++i) {
		delete flights[i];
	}
	delete[] flights;
}
void Airline::addFlight(const Flight& f, Airport& airp) {
	try {
		flights[counter++] = new Flight(f);
	}
	catch (std::bad_alloc) {
		throw;
	}
	Airport tmp(airp);
	airport = tmp;
}
void Airline::printFlight(const Flight& fl) {
	std::cout << "\n---------------------------------\n";
	std::cout << "Information about flight N" << fl.get_id();
	std::cout << "\nFrom: " << fl.get_origin();
	std::cout << "\nTo: " << fl.get_destination();
	std::cout << "\nDuration: " << fl.get_duration() << "m";
	std::cout << "\nDate: ";
	fl.printDate();
	std::cout << "\n---------------------------------\n";
}