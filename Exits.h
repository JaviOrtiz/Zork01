#ifndef _Exits
#define _Exits
#include "Room.h"

enum directions { north, south, west, east };

class Exit
{
public:
	char name[20];
	char description[300];
	Room* origin;
	Room* destination;
	directions direction;

public:
	Exit();
	~Exit();

};


#endif _Exits