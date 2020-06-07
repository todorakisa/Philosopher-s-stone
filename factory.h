#ifndef FACTORY_H
#define FACTORY_H

#include"baseElement.h"
#include<string>

class Factory{
public: 
	static Base_Element* make(std::string type);
};

#endif