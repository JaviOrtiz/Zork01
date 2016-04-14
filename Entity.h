#ifndef _Entity_
#define _Entity_

#include "My_String.h"
enum EntityType{

	ROOM,
	ENTITY,
	EXIT,
	ITEM,
	PLAYER

};



class Entity{
public:

	Entity* Type;
	String name;
	String  description;

public:
	Entity(const char* name, const char* description);
	virtual ~Entity();


};
#endif