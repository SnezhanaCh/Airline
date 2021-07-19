#include "Seat.h"
#include <cassert>


int main() {
	Seat obj;
	Seat obj2(1, 'B');
	Seat obj3(3, 'j', true);
	Seat obj4(obj2);
	//Testing Seat::Seat(int, char);
	assert(obj2.get_row() == 1);
	assert(obj2.get_column() == 'B');

	//Testing Seat::Seat(int, char, bool);
	assert(obj3.get_row() == 3);
	assert(obj3.get_column() == 'J');

	//Testing Seat::Seat(const Seat& other);
	assert(obj4.get_row() == 1);
	assert(obj4.get_column() == 'B');

	//Testing Seat::operator=(const Seat&);
	obj = obj3;
	assert(obj.get_row() == 3);
	assert(obj.get_column() == 'J');

	return 0;
}