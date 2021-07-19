#include "Date.h"

Date::Date() :day(0), month(0), year(0) {}
Date::Date(const Date& other) {
	day = other.day;
	month = other.month;
	year = other.year;
}
Date::Date(size_t day, size_t month, size_t year) {
	if (!isValidDate(day, month, year))
		throw std::invalid_argument("Date data is not valid");
	this->day = day;
	this->month = month;
	this->year = year;
}
Date& Date::operator=(const Date& other) {
	if (this != &other) {
		day = other.day;
		month = other.month;
		year = other.year;
	}
	return *this;
}
Date::~Date() {}
void Date::print_date() const {
	std::cout << day << '.' << month << '.' << year;
}
bool Date::isLeapYear(size_t year) {
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
bool Date::isValidDate(size_t day, size_t month, size_t year) {
	size_t months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (!year || !month || !day || month > 12) {
		return false;
	}
	if (isLeapYear(year) && (month == 2)) {
		months[1]++;
	}
	if (day > months[month - 1])
		return false;
	return true;
}
void Date::updateDay(size_t day) {
	if (isValidDate(day, this->month, this->year)) {
		this->day = day;
	}
}
void Date::updateMonth(size_t month) {
	if (isValidDate(this->day, month, this->year)) {
		this->month = month;
	}
}
void Date::updateYear(size_t year) {
	if (isValidDate(this->day, this->month, year)) {
		this->year = year;
	}
}