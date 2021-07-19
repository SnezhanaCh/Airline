#include "Airport.h"
#include <iostream>
#include <cassert>

int main() {

	Airport obj("SFA");
	Airport obj2("BBS");
	Airport obj3("KTB");
	Airport obj4(obj2);

	//Testing Airport::Airport(const char*);
	assert(strcmp(obj.get_name(), "SFA") == 0);
	assert(strcmp(obj2.get_name(), "BBS") == 0);
	assert(strcmp(obj3.get_name(), "KTB") == 0);

	//Testing Airport::Airport(const Airport&);
	assert(strcmp(obj4.get_name(), "BBS") == 0);

	//Testing Airport::operator=(const Airport&);
	obj = obj3;
	assert(strcmp(obj.get_name(), "KTB") == 0);

	
	try {
		Airport obj5("ABCD");
	}
	catch (std::invalid_argument& ia) {
		std::cout << ia.what();
	}

	return 0;
}