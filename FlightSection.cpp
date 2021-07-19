#include "FlightSection.h"
#include "Section.h"
#include "Seat.h"


void FlightSection::createSeats() {
	size_t tmp_counter = 0;
	for (size_t row = 1; row <= 5; row++) {
		for (char col = 'A'; col <= 'J'; col++) {
			Seat tmp(row, col);
			seat[tmp_counter++] = tmp;
		}
	}
}
void FlightSection::copyFrom(const FlightSection& other) {
	bookedSeats = other.bookedSeats;
	type = other.type;
	for (size_t i = 0; i < MAX_SEAT_SIZE; ++i) {
		seat[i] = other.seat[i];
	}
}
void FlightSection::lowerToUpperCase(char& ch) {
	if (ch >= 'a' && ch <= 'j')
		ch -= 32;
}

FlightSection::FlightSection() : bookedSeats(0), type(businessClass) {
	createSeats();
}
FlightSection::FlightSection(size_t t) : bookedSeats(0)
{
	switch (t) {
	case 0:
		this->type = businessClass;
		break;
	case 1:
		this->type = firstClass;
		break;
	case 2:
		this->type = premiumEconomyClass;
		break;
	case 3:
		this->type = economyClass;
		break;
	}
	createSeats();
}
FlightSection::FlightSection(const FlightSection& other) {
	copyFrom(other);
}
FlightSection& FlightSection::operator=(const FlightSection& other) {
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}
size_t FlightSection::get_numofBookedSeats() const {
	return bookedSeats;
}
Section FlightSection::get_type() const {
	return type;
}
bool FlightSection::hasAvailableSeats() {
	for (size_t i = 0; i < MAX_SEAT_SIZE; i++) {
		if (!(seat[i].isItBooked()))
			return true;
	}
	return false;
}
bool FlightSection::isSuccessfullyBooked(int row, char col) {
	for (size_t i = 0; i < MAX_SEAT_SIZE; i++) {
		lowerToUpperCase(col);
		if ((seat[i].get_row() == row) && (seat[i].get_column() == col)){
			if (!seat[i].isItBooked()) {
				seat[i].book_seat();
				bookedSeats++;
				return true;
			}
		}
	}
	return false;
}
void FlightSection::bookRandom() {
	if (hasAvailableSeats()) {
		for (size_t i = 0; i < MAX_SEAT_SIZE; i++) {
			if (!seat[i].isItBooked()) {
				seat[i].book_seat();
				bookedSeats++;
				std::cout << "\n[SUCCESS] You successfully booked a seat\n";
				break;
			}
		}
	}
	else
		std::cout << "\n[ERROR] No Available Seats\n";
}