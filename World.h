#ifndef _World
#define _World

#include "Room.h"
#include "Exits.h"
#include "Player.h"
#include "Entity.h"
#include "My_String.h"
#include "Vector.h"

class World
{
public:
	Vector <Room*> rooms;
	Vector <Exit*> exits;
	Vector <Player*> players;
		

public:
	World();
	~World();

public:

	void createWorld() ;
	void createExits() ;
	void comand()const;
};


#endif _World