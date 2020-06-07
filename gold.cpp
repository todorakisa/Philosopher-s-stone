#ifndef GOLD_CPP_
#define GOLD_CPP_

#include "baseElement.h"
#include "metal.h"
#include "gold.h"
#include <string>
#include <list>

Gold::Gold():Base_Element("Gold"),Metal(){}

std::list<std::string> Gold::delete_elem(){
	std::list<std::string> result;
	result.push_back("Metal");
	result.push_back("Metal");
	return result;
}

Gold::~Gold(){}

#endif