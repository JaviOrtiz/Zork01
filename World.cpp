#include <stdio.h>
#include "World.h"
#include "Exits.h"
#include "Room.h"
#include <string.h>
#include <stdlib.h>
#define Num_Rooms 10
#define Num_Exits 17

World::World()
{
	rooms = new Room[Num_Rooms];
	exits = new Exit[Num_Exits];
	players = new Player[0];

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
	for (int i = 0; i < Num_Rooms; i++) {
		strcpy_s(rooms[i].description, descriptions[i]);
	}
}

void World::createExits() const{
	//0.Create the  Exit from the cell to the First Corridor//
	strcpy_s(exits[0].name, "First Corridor");
	strcpy_s(exits[0].description, rooms[1].description);
	exits[0].origin = &rooms[0];
	exits[0].destination = &rooms[1];
	exits[0].direction = north;

	//1.Create the  Exit from the First Corridor to the Cell// 
	strcpy_s(exits[1].name, "Your Cell");
	strcpy_s(exits[1].description, rooms[0].description);
	exits[1].origin = &rooms[1];
	exits[1].destination = &rooms[0];
	exits[1].direction = south;

	//2.Create the  Exit from the First Corridor to the Kitchen// 
	strcpy_s(exits[2].name, "The Kitchen");
	strcpy_s(exits[2].description, rooms[2].description);
	exits[2].origin = &rooms[1];
	exits[2].destination = &rooms[2];
	exits[2].direction = north;

	//3.Create the  Exit from the Kitchen to the First Corridor// 
	strcpy_s(exits[3].name, "First Corridor");
	strcpy_s(exits[3].description, rooms[1].description);
	exits[3].origin = &rooms[2];
	exits[3].destination = &rooms[1];
	exits[3].direction = south;

	//4.Create the  Exit from the Kitchen to the Prison snake's room// 
	strcpy_s(exits[4].name, "Prison snake's room");
	strcpy_s(exits[4].description, rooms[3].description);
	exits[4].origin = &rooms[2];
	exits[4].destination = &rooms[3];
	exits[4].direction = west;

	//5.Create the  Exit from the Prison snake's room to the Kitchen// 
	strcpy_s(exits[5].name, "The Kitchen");
	strcpy_s(exits[5].description, rooms[2].description);
	exits[5].origin = &rooms[3];
	exits[5].destination = &rooms[2];
	exits[5].direction = east;

	//6.Create the  Exit from kitchen to the courtyard// 
	strcpy_s(exits[6].name, "The Coutyard");
	strcpy_s(exits[6].description, rooms[4].description);
	exits[6].origin = &rooms[2];
	exits[6].destination = &rooms[4];
	exits[6].direction = east;

	//7.Create the  Exit from the Coutyard to the Kitchen// 
	strcpy_s(exits[7].name, "The Kitchen");
	strcpy_s(exits[7].description, rooms[2].description);
	exits[7].origin = &rooms[4];
	exits[7].destination = &rooms[2];
	exits[7].direction = west;

	//8.Create the  Exit from the kitchen to the Second Corridor// 
	strcpy_s(exits[8].name, "Second Corridor");
	strcpy_s(exits[8].description, rooms[5].description);
	exits[8].origin = &rooms[2];
	exits[8].destination = &rooms[5];
	exits[8].direction = north;

	//9.Create the  Exit from Second Corridor to the Kitchen// 
	strcpy_s(exits[9].name, "The Kitchen");
	strcpy_s(exits[9].description, rooms[2].description);
	exits[9].origin = &rooms[5];
	exits[9].destination = &rooms[2];
	exits[9].direction = south;

	//10.Create the  Exit from Second Corridor to the booker's cell// 
	strcpy_s(exits[10].name, "Booker's Cell");
	strcpy_s(exits[10].description, rooms[6].description);
	exits[10].origin = &rooms[5];
	exits[10].destination = &rooms[6];
	exits[10].direction = east;

	//11.Create the  Exit from booker's cell to the second corridor// 
	strcpy_s(exits[11].name, "Second Corridor");
	strcpy_s(exits[11].description, rooms[5].description);
	exits[11].origin = &rooms[6];
	exits[11].destination = &rooms[5];
	exits[11].direction = west;

	//12.Create the  Exit from Second Corridor to the execcution room// 
	strcpy_s(exits[12].name, "Execcution Room");
	strcpy_s(exits[12].description, rooms[7].description);
	exits[12].origin = &rooms[5];
	exits[12].destination = &rooms[7];
	exits[12].direction = west;

	//13.Create the  Exit from execcution room to the second corridor// 
	strcpy_s(exits[13].name, "Second Corridor");
	strcpy_s(exits[13].description, "You go away from the Execcution room and walk to the Second Corridor");
	exits[13].origin = &rooms[7];
	exits[13].destination = &rooms[5];
	exits[13].direction = east;

	//14.Create the  Exit from Second Corridor to the bathroom// 
	strcpy_s(exits[14].name, "Bathroom");
	strcpy_s(exits[14].description, rooms[8].description);
	exits[14].origin = &rooms[5];
	exits[14].destination = &rooms[8];
	exits[14].direction = north;

	//15.Create the  Exit from the bathroom to the second corridor// 
	strcpy_s(exits[15].name, "Second Corridor");
	strcpy_s(exits[15].description, rooms[5].description);
	exits[15].origin = &rooms[8];
	exits[15].destination = &rooms[5];
	exits[15].direction = south;

	//16.Create the  Exit from the bathroom to the cliff// 
	strcpy_s(exits[16].name, "Cliff");
	strcpy_s(exits[16].description, rooms[9].description);
	exits[16].origin = &rooms[8];
	exits[16].destination = &rooms[9];
	exits[16].direction = west;
	};

void World::comand(){  //Create the Commands  Help, Go, Look, Close, Open and Quit
	
	players[0].position = &rooms[0];
	char command[15];
	char *help;
	char *first;
	char *second;

	do{
		int i = 0, j;
		do{
			
			printf("you are in %s\n", players[0].position);
			printf("What do you want to do?\n");
			gets_s(command);
			first = strtok_s(command, " ", &help);
		} while (first == NULL);
		second = strtok_s(NULL, " ", &help);


		if (strcmp(command, "help") == 0)
		{
			printf("Hi, and Wellcome to my zork\n\nComands:\n\n'help' for show this help again\n'go' for walk in a direction\n'look' for receive the description of the room\n'open' for open a door or a window\n'close' for close a door or a window\n'quit' for quite the game\n ENJOY PLAYING :D\n\n");
			
		}
		//-------------------------------------------------------------------------------------------//
		else if (strcmp(command, "go") == 0 )
		{
			if (strcmp(second, "north") == 0 || (strcmp(second, "n") == 0)){
				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == north) && (exits[i].origin == (players[0].position)))
					{

						printf("%s\n", exits[i].description);
						(players[0].position) = (exits[i].destination);
						break;


					}
				}
			}
			else if (strcmp(second, "south") == 0 || (strcmp(second, "s") == 0)){
				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == south) && (exits[i].origin == (players[0].position)))
					{

						printf("%s\n", exits[i].description);
						(players[0].position) = (exits[i].destination);
						break;


					}
				}

			}

			else if (strcmp(second, "west") == 0 || (strcmp(second, "w") == 0)){
				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == west) && (exits[i].origin == (players[0].position)))
					{

						printf("%s\n", exits[i].description);
						(players[0].position) = (exits[i].destination);
						break;


					}
				}
			}
			if (strcmp(second, "east") == 0 || (strcmp(second, "e") == 0)){
				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == east) && (exits[i].origin == (players[0].position)))
					{

						printf("%s\n", exits[i].description);
						(players[0].position) = (exits[i].destination);
						break;


					}
				}
			}
		
		
		}
		//------------------------------------------------------------------------------------//
		else if (strcmp(command, "look")){

		

		};






	} while (strcmp(command, "quit") != 0);
};


	void World::movement(char direction){
		int i;
		switch (direction)
		{
		case 'n':
			for (i = 0; i < Num_Exits; i++)
			{
				if ((exits[i].direction == north) && (exits[i].origin == (&rooms[0])))
				{
					(rooms[i]) = (*(exits[i].destination));
					printf("%s", exits[i].description);
					
				}
			}
			break;

		}
	};



World::~World(){

	delete[] rooms;
	delete[] exits;
}


/*strtok_s(command, " ", &first);
strtok_s(first, "\n", &second);
strtok_s(command, "\n", &second);*/