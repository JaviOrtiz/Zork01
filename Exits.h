#ifndef _Exits
#define _Exits
#include "World.h"
#include "Entity.h"


enum directions { north, south, west, east };
enum locked{open,close};

class Exit:public Entity
{
public:
	
	Room* origin;
	Room* destination;
	directions direction;
	locked lock;

public:
	Exit(const char*, const char*, Room*, Room*, directions);

public:
	
	~Exit();

};


#endif _Exits