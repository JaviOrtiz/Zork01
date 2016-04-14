#include "World.h"



Exit::Exit(const char*name, const char*description, Room*origin, Room*destination, directions direction) :Entity(name, description),
origin(origin), destination(destination), direction(direction){

}
