#ifndef METAL_CPP_
#define METAL_CPP_

#include "metal.h"
#include "baseElement.h"
#include "fire.h"
#include "earth.h"
#include <string>
#include <list>

Metal::Metal():Base_Element("Metal"),Earth(),Fire(){}

std::list<std::string> Metal::delete_elem(){
	std::list<std::string> result;
	result.push_back("Fire");
	result.push_back("Earth");
	return result;
}

Metal::~Metal(){}

#endif
