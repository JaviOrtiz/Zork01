#include "Room.h"
#include "World.h"
#include "Exits.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	World map;
	map.createWorld();
	map.createExits();
	map.comand();
}