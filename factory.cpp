#ifndef FACTORY_CPP_
#define FACTORY_CPP_

#include "factory.h"
#include "baseElement.h"
#include "water.h"
#include "fire.h"
#include "earth.h"
#include "air.h"
#include "stone.h"
#include "metal.h"
#include "energy.h"
#include "gold.h"
#include "spirit.h"
#include "philosopherstone.h"

Base_Element* Factory::make(std::string type){
	Base_Element* newElem = nullptr;
	if(type.compare("Water") == 0){
		newElem = new Water();
	}else if(type.compare("Earth") == 0){
		newElem = new Earth();
	}else if(type.compare("Fire") == 0){
		newElem = new Fire();
	}else if(type.compare("Air") == 0){
		newElem = new Air();
	}else if(type.compare("Stone") == 0){
		newElem = new Stone();
	}else if(type.compare("Metal") == 0){
		newElem = new Metal();
	}else if(type.compare("Spirit") == 0){
		newElem = new Spirit();
	}else if(type.compare("Energy") == 0){
		newElem = new Energy();
	}else if(type.compare("Gold") == 0){
		newElem = new Gold();
	}else if(type.compare("Philosopher’s Stone") == 0){
		newElem = new PhilosopherStone();
	}

	return newElem;
}

#endif