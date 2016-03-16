#ifndef _Exits
#define _Exits
#include "Room.h"

enum directions { north, south, west, east };
enum locked{open,close};

class Exit
{
public:
	char name[25];
	char description[300];
	Room* origin;
	Room* destination;
	directions direction;
	locked lock;

public:
	Exit();
	~Exit();

};


#endif _Exits