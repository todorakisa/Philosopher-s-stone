#ifndef FIRE_CPP_
#define FIRE_CPP_

#include "fire.h"
#include "baseElement.h"

Fire::Fire():Base_Element("Fire"){
	add_reaction("Fire");add_reaction("Earth");add_reaction("Water");
}

Fire::~Fire(){}

#endif