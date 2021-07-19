#ifndef _AIRPORT_HEADER_
#define _AIRPORT_HEADER_

class Airport {
	static const int MAX_NAME = 4;
	char airportName[MAX_NAME];
public:
	Airport() = delete;
	Airport(const char*);
	Airport(const Airport&);
	Airport& operator=(const Airport&);
	const char* get_name();
};
#endif // !_AIRPORT_HEADER_
