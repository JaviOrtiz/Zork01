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
	

}

void World::createWorld() {

	/*Create the world now in vectors, they got name and description */


	rooms.push_back(new Room("Your Cell", "You are in Your Cell, there is a bed and a toilet, the First Corridor is in the north "));
	rooms.push_back(new Room("First Corridor", "You are in the First Corridor, Your cell is in the south, the Kitchen is in the north"));
	rooms.push_back(new Room("Kitchen", "You are in the Kitchen, the Second Corridor is in the north, the First Corridor is in the south, the Prison Snake's Room is in the west, the Courtyard is in the east"));
	rooms.push_back(new Room("Prisen Snake's Room", "You are in the Prison Snake's Room, the Kitchen is in the east"));
	rooms.push_back(new Room("Coutyard", "You are in the Coutyard, the Kitchen is in the west"));
	rooms.push_back(new Room("Second Corridor", "You are in the second Corridor, the Bathroom is in the north, the Kitchen is in the south"));
	rooms.push_back(new Room("Booker Cell", "You are in the Booker Cell, the Second Corridor is in the west"));
	rooms.push_back(new Room("Execcution Room", "You are in the Execution room, the Second Corridor is in the east"));
	rooms.push_back(new Room("Bathroom", "You are in the Bathroom, the Second Corridor is in the south, there is a open window who takes you to a cliff"));
	rooms.push_back(new Room("Cluff", "You are in the cliff, seems you can jump and go away from this Prison"));



}

void World::createExits() {

	exits.push_back(new Exit("First Corridor", "You go to the First Corridor", rooms[0], rooms[1], north));
	exits.push_back(new Exit("Your Cell", "You go to Your Cell", rooms[1], rooms[0], south));
	exits.push_back(new Exit("The Kitchen", "You go to the Kitchen", rooms[1], rooms[2], north));
	exits.push_back(new Exit("First Corridor", "You go to the First Corridor", rooms[2], rooms[1], south));
	exits.push_back(new Exit("Prison Snake's Room", "You go to the Prison Snake's Room ", rooms[2], rooms[3], west));
	exits.push_back(new Exit("Kitchen", "You go to the Kitchen", rooms[3], rooms[2], east));
	exits.push_back(new Exit("Coutyard", "You go to the Coutyard", rooms[2], rooms[4], east));
	exits.push_back(new Exit("Kitchen", "You go to the Kitchen", rooms[4], rooms[2], west));
	exits.push_back(new Exit("Second Corridor", "You go to the Second Corridor", rooms[2], rooms[5], north));
	exits.push_back(new Exit("Kitchen", "You go to the Kitchen", rooms[5], rooms[2], south));
	exits.push_back(new Exit("Booker's Cell", "You go to the Booker's Cell", rooms[5], rooms[6], east));
	exits.push_back(new Exit("Second Corridor", "You go to the Second Corridor", rooms[6], rooms[5], west));
	exits.push_back(new Exit("Execcution Room", "You go to the Execcution Room", rooms[5], rooms[7], west));
	exits.push_back(new Exit("Second Corridor", "You go to the Second Corridor", rooms[7], rooms[5], east));
	exits.push_back(new Exit("Bathroom", "You go to the Bathroom", rooms[5], rooms[8], north));
	exits.push_back(new Exit("Second Corridor", "You go to the Second Corridor", rooms[8], rooms[5], south));
	exits.push_back(new Exit("Cliff", "You go to the Cliff", rooms[8], rooms[9], east));


}

void World::comand()const{  //Create the Commands  Help, Go, Look, Close, Open and Quit

	players[0].position = rooms[0];
	char command[20];

	char *help;
	char *first;
	char *second;
	printf("<<Wellcome to Javi's Zork>>\n\n>You are in %s\n", players[0].position);

	int i = 0;
	do{

		do{


			printf("\n>What do you want to do?\n\n>>");
			gets_s(command);
			first = strtok_s(command, " ", &help);
		} while (first == NULL);
		second = strtok_s(NULL, " ", &help);



		if (strcmp(command, "help") == 0 || strcmp(command, "HELP") == 0 || strcmp(command, "Help") == 0)
		{
			printf("Hi, and Wellcome to my zork\n\nComands:\n\n'help' for show this help again\n'go' for walk in a direction\n'look' for receive the description of the room\n'open' for open a door or a window\n'close' for close a door or a window\n'quit' for quite the game\n ENJOY PLAYING :D\n\n");

		}
		//-------------------------------------------------------------------------------------------//
		else if (strcmp(command, "go") == 0 || strcmp(command, "Go") == 0 || strcmp(command, "GO") == 0)
		{

			if (second == NULL){
				printf("Writte a right command please ( 'GO' 'Direction'?");   //if the player do not writte a second word, the program will ask again
			}
			else if (strcmp(second, "north") == 0 || strcmp(second, "n") == 0 || strcmp(second, "N") == 0 || strcmp(second, "NORTH") == 0 || strcmp(second, "North") == 0){
				for (i = 0; i <= Num_Exits; i++)
				{
					if ((exits[i].direction == north) && (exits[i].origin == (players[0].position)))
					{
						if (exits[i].lock != close){

							printf("\n%s\n", exits[i].name);
							(players[0].position) = (exits[i].destination);
							strcpy_s(players[0].description, exits[i].description);
							break;
						}
						else  { printf("\n>The door is closed\n\n"); }
					}
					if (i == Num_Exits && exits[i].origin != players[0].position){
						printf("\n>You cant go throug walls...yet\n");
					}
				}
			
			}
			else if (strcmp(second, "south") == 0 || strcmp(second, "s") == 0 || strcmp(second, "S") == 0 || strcmp(second, "SOUTH") == 0 || strcmp(second, "South") == 0){
				for (i = 0; i <= Num_Exits; i++)
				{
					if ((exits[i].direction == south) && (exits[i].origin == (players[0].position)))
					{
						if (exits[i].lock != close){
							printf("\n%s\n", exits[i].name);
							(players[0].position) = (exits[i].destination);
							strcpy_s(players[0].description, exits[i].description);
							break;
						}
						else { printf("\n>The door is closed\n\n"); }
					}
					if (i == Num_Exits && exits[i].origin != players[0].position){
						printf("\n>You cant go throug walls...yet\n");
					}
				}
			}

			else if (strcmp(second, "west") == 0 || strcmp(second, "w") == 0 || strcmp(second, "W") == 0 || strcmp(second, "WEST") == 0 || strcmp(second, "West") == 0){
				for (i = 0; i <= Num_Exits; i++)
				{
					if ((exits[i].direction == west) && (exits[i].origin == (players[0].position)))
					{

						printf("\n%s\n", exits[i].name);
						(players[0].position) = (exits[i].destination);
						strcpy_s(players[0].description, exits[i].description);
						break;
					}
					if (i == Num_Exits && exits[i].origin != players[0].position){
						printf("\n>You cant go throug walls...yet\n");
					}
				
				}
			}
			else if (strcmp(second, "east") == 0 || strcmp(second, "e") == 0 || strcmp(second, "E") == 0 || strcmp(second, "EAST") == 0 || strcmp(second, "East") == 0)
			{
				for (i = 0; i <= Num_Exits; i++)
				{
					if ((exits[i].direction == east) && (exits[i].origin == (players[0].position)))
					{
						printf("\n%s\n", exits[i].name);
						(players[0].position) = (exits[i].destination);
						strcpy_s(players[0].description, exits[i].description);
						break;
					}if (i == Num_Exits && exits[i].origin != players[0].position){
						printf("\n>You cant go throug walls...yet\n");
					}
					
				}

				}
			
			else {
				printf("\n>You cant walk throug walls...yet\n"); break;
			}

		}


		//------------------------------------------------------------------------------------//
		else if (strcmp(command, "look") == 0 || strcmp(command, "LOOK") == 0 || strcmp(command, "Look") == 0) {

			printf("\n%s\n", players[0].description);

		}
		//------------------------------------------------------------------------------------//
		else if (strcmp(command, "open") == 0 || strcmp(command, "OPEN") == 0 || strcmp(command, "Open") == 0){
			if (second == NULL){
				printf("Writte a right command please ( 'Open' 'Direction'?");
			}
			else if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "N") == 0 || strcmp(second, "n") == 0){

				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == north) && (exits[i].lock == close) && (exits[i].origin == (players[0].position)))
					{
						exits[i].lock = open;
						printf("\n You open the North Door\n");
						break;
					}
					else if ((exits[i].direction == north) && (exits[i].lock == open) && (exits[i].origin == (players[0].position))){
						printf("\n>This door is already open\n");
					}
					else if ((exits[i].direction == north) && (exits[i].origin == (players[0].position))){
						printf("\n>You can't open this door\n"); break;

					}
				}

			}
			else if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "S") == 0 || strcmp(second, "s") == 0){

				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == south) && (exits[i].lock == close) && (exits[i].origin == (players[0].position)))
					{
						exits[i].lock = open;
						printf("\n You open the South Door\n");
						break;
					}
					else if ((exits[i].direction == south) && (exits[i].lock == open) && (exits[i].origin == (players[0].position))){
						printf("\n>This door is already open\n");
					}
					else if ((exits[i].direction == south) && (exits[i].origin == (players[0].position))){
						printf("\n>You can't open this door\n"); break;

					}
				}

			}
		}
		//--------------------------------------------------------------------//
		else if (strcmp(command, "close") == 0 || strcmp(command, "CLOSE") == 0 || strcmp(command, "close") == 0){
			if (second == NULL){
				printf("Writte a right command please ( 'close' 'Direction'?");
			}
			else if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "N") == 0 || strcmp(second, "n") == 0){

				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == north) && (exits[i].lock == open) && (exits[i].origin == (players[0].position)))
					{
						exits[i].lock = close;
						printf("\n You close the North Door\n");
						break;
					}
					else if ((exits[i].direction == north) && (exits[i].lock == close) && (exits[i].origin == (players[0].position))){
						printf("\n>This door is already closed\n");
					}
					else if ((exits[i].direction == north) && (exits[i].origin == (players[0].position))){
						printf("\n>You can't close this door\n"); break;

					}
				}

			}
			else if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "S") == 0 || strcmp(second, "s") == 0){

				for (i = 0; i < Num_Exits; i++)
				{
					if ((exits[i].direction == south) && (exits[i].lock == open) && (exits[i].origin == (players[0].position)))
					{
						exits[i].lock = close;
						printf("\n You close the South Door\n");
						break;
					}
					else if ((exits[i].direction == south) && (exits[i].lock == close) && (exits[i].origin == (players[0].position))){
						printf("\n>This door is already closed\n");
					}
					else if ((exits[i].direction == south) && (exits[i].origin == (players[0].position))){
						printf("\n>You can't close this door\n"); break;

					}
				}

			}
			else if (strcmp(command, "quit") == 1){ printf("\n>Invalid Command, type 'help' if u need it\n"); }

		}
		} while (strcmp(command, "quit") != 0);
};

World::~World(){
	
	delete  players;
	delete[] exits;
	delete[] rooms;
};
