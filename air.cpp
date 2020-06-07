#ifndef AIR_CPP_
#define AIR_CPP_

#include "air.h"

Air::Air():Base_Element("Air"){
	add_reaction("Air");add_reaction("Fire");add_reaction("Earth");add_reaction("Water");
}

Air::~Air(){}

#endif