#ifndef _World
#define _World
#include "Room.h"
#include "Exits.h"
#include "Player.h"

class World
{
public:
	Room* rooms;
	Exit* exits;
	Player* players;
		

public:
	World();
	~World();

public:

	void createWorld() const;
	void createExits() const;
	void comand()const;
};


#endif _World