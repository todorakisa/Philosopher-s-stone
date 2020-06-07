#ifndef ENERGY_CPP_
#define ENERGY_CPP_

#include "energy.h"
#include "baseElement.h"
#include "air.h"
#include "water.h"
#include <string>
#include <list>

Energy::Energy():Base_Element("Energy"),Air(),Water(){}

std::list<std::string> Energy::delete_elem(){
	std::list<std::string> result;
	result.push_back("Air");
	result.push_back("Water");
	return result;
}

Energy::~Energy(){}

#endif