#include "Flight.h"
#include <cassert>

int main() {
	//Testing Flight::Flight();
	Flight obj;
	assert((obj.get_id() == 0) && (obj.get_duration() == 0));
	assert(obj.get_origin() == nullptr && obj.get_destination() == nullptr);

	//Testing Flight::Flight(int, int, const char*, const char*, Section, size_t, size_t, size_t);
	try {
		Flight obj2(2231, 60, "Sofia", "London", 20, 06, 2021);
		assert((obj2.get_id() == 2231) && (obj2.get_duration() == 60));
		assert(strcmp(obj2.get_origin(), "Sofia") == 0);
		assert(strcmp(obj2.get_destination(), "London") == 0);
	}
	catch (std::bad_alloc& ba) {
		std::cout << ba.what() << '\n';
	}
	

	Flight obj2(2231, 60, "Sofia", "London", 20, 06, 2021);
	//Testing Flight::operator=(const Flight&);
	obj = obj2;
	assert((obj.get_id() == 2231) && (obj.get_duration() == 60));
	assert(strcmp(obj.get_origin(), "Sofia") == 0);
	assert(strcmp(obj.get_destination(), "London") == 0);

	
	return 0;
}