#ifndef WATER_CPP_
#define WATER_CPP_

#include "water.h"

Water::Water():Base_Element("Water"){
	add_reaction("Air");add_reaction("Fire");
}

Water::~Water(){}

#endif