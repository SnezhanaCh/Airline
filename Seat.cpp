#include "Seat.h"

void Seat::copyFrom(const Seat& other) {
	this->row = other.row;
	this->column = other.column;
	this->isBooked = other.isBooked;
}
bool Seat::isValid(int row, char col) {
	if (row > 0 && row <= MAX_COL) {
		if (col >= 'A' && col <= 'J')
			return true;
	}
	return false;
}
void Seat::lowerToUpperCase(char& ch) {
	if (ch >= 'a' && ch <= 'j')
		ch -= 32;
}

Seat::Seat() :row(0), column('#'), isBooked(false) {}
Seat::Seat(int row, char col) : isBooked(false) {
	lowerToUpperCase(col);
	if (isValid(row, col)) {
		this->row = row;
		this->column = col;
	}
}
Seat::Seat(int row, char col, bool isBooked = false) {
	lowerToUpperCase(col);
	if (isValid(row, col)) {
		this->row = row;
		this->column = col;
	}
}
Seat::Seat(const Seat& other) {
	copyFrom(other);
}
Seat& Seat::operator=(const Seat& other) {
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}
void Seat::book_seat() {
	isBooked = true;
}
char Seat::get_column() {
	return column;
}
int Seat::get_row() {
	return row;
}
bool Seat::isItBooked() {
	return isBooked;
}