#ifndef _World
#define _World
#include "Room.h"
#include "Exits.h"

class World
{
public:
	Room* rooms;
	Exit* exits;
		

public:
	World();
	~World();

	void createWorld() const;
	void createExits() const;


};


#endif _World