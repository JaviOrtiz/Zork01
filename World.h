#ifndef _World
#define _World
#endif _World
#include "Room.h"
class World
{
public:
	Room *rooms = nullptr;
	Exit *exits = nullptr;
	

public:
	World();
	~World();

	void createWorld() const;
	void createExits() const;


};