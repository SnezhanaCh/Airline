#include "Date.h"
#include <cassert>

int main() {
	Date obj;
	Date obj2(2, 10, 1999);
	
	
	//Testing Date::Date(size_t, size_t, size_t);
	assert(obj2.get_day() == 2);
	assert(obj2.get_month() == 10);
	assert(obj2.get_year() == 1999);

	//Testing Date::Date(const Date&);
	Date obj3(obj2);
	assert(obj3.get_day() == 2);
	assert(obj3.get_month() == 10);
	assert(obj3.get_year() == 1999);

	//Testing Date::Date& operator=(const Date&);
	obj = obj3;
	assert(obj.get_day() == 2);
	assert(obj.get_month() == 10);
	assert(obj.get_year() == 1999);


	try {
		Date obj4(30, 2, 2021);
	}
	catch (std::invalid_argument& ia) {
		std::cout << ia.what();
	}

	return 0;
}