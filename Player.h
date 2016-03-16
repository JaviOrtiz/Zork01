#ifndef _Player
#define _Player
#include "Room.h"


class Player{
public:
	Room* position;
	char description[200];
public:
	Player::Player();
	Player::~Player();
};

#endif _Player