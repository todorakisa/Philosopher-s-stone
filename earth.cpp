#ifndef EARTH_CPP_
#define EARTH_CPP_

#include "earth.h"
#include "baseElement.h"

Earth::Earth():Base_Element("Earth"){
	add_reaction("Air");add_reaction("Fire");add_reaction("Water");
}

Earth::~Earth(){}

#endif