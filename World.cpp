#include <stdio.h>
#include "World.h"
#include <string.h>
#define Num_Rooms 10

World::World()
{
	rooms = new Room[Num_Rooms];
	exits = new Exit[40];


}

void World::createWorld() const {
	const char *names[] = { "Your Cell", "First Corridor", "Kitchen", "Prison Snake' Room", "Coutyard", "Second Corridor", "Booker Cell", "Execcution Room", "Bathroom", "Cliff" };
	for (int i = 0; i < Num_Rooms; i++) {
		strcpy_s(rooms[i].name, names[i]);
	}

	const char *descriptions[] = {
		"You are in Your Cell, there is a bed and a toilet, the First Corridor is in the north",
		"You are in the First Corridor, Your cell is in the south, the Kitchen is in the north",
		"You are in the Kitchen,the Second Corridor is in the north, the First Corridor is in the south, the Prison Snake's Room is in the west, the Courtyard is in the east",
		"You are in the Prison Snake's Room, the Kitchen is in the east",
		"You are in the Coutyard, the Kitchen is in the west",
		"You are in the second Corridor, the Bathroom is in the north, the Kitchen is in the south,",
		"You are in the Booker Cell, the Second Corridor is in the west;",
		"You are in the execution room, the Second Corridor is in the east",
		"You are in the Bathroom,the Second Corridor is in the south, there is a open window who takes you to a cliff",
		"You are in the cliff, seems you can jump and go away from this Prison"
	};
}


World::~World(){
	delete[] rooms;
	delete[] exits;
}