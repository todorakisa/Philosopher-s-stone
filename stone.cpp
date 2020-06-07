#ifndef STONE_CPP_
#define STONE_CPP_

#include "baseElement.h"
#include "fire.h"
#include "water.h"
#include "stone.h"
#include <string>
#include <list>

Stone::Stone():Base_Element("Stone"),Fire(),Water(){}

std::list<std::string> Stone::delete_elem(){
	std::list<std::string> result;
	result.push_back("Fire");
	result.push_back("Water");
	return result;
}

Stone::~Stone(){}

#endif