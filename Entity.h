#ifndef _Entity_
#define _Entity_

enum EntityType{

	ROOM,
	ENTITY,
	EXIT,
	ITEM,
	PLAYER

};



class Entity{
public:

	Entity* Type
	string name;

public:
	Entity(const char* name, const char* description);
	virtual ~Entity();


};
#endif