#ifndef SPIRIT_CPP_
#define SPIRIT_CPP_

#include "baseElement.h"
#include "air.h"
#include <string>
#include <list>
#include "spirit.h"

Spirit::Spirit():Base_Element("Spirit"),Air(){}

std::list<std::string> Spirit::delete_elem(){
	std::list<std::string> result;
	result.push_back("Air");
	result.push_back("Air");
	return result;
}

Spirit::~Spirit(){}

#endif