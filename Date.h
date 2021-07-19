#ifndef _DATE_HEADER_
#define _DATE_HEADER_
#include <iostream>
#include <exception>

class Date {
	size_t day;
	size_t month;
	size_t year;
public:
	Date();
	Date(size_t, size_t, size_t);
	Date(const Date&);
	Date& operator=(const Date&);
	~Date();
	void print_date() const;
	bool isLeapYear(size_t);
	bool isValidDate(size_t, size_t, size_t);
	void updateDay(size_t);
	void updateMonth(size_t);
	void updateYear(size_t);
	size_t get_day() const {
		return day;
	}
	size_t get_month() const {
		return month;
	}
	size_t get_year() const {
		return year;
	}
};

#endif // !_DATE_HEADER_
