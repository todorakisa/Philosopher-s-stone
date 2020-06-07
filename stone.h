#ifndef STONE_H_
#define STONE_H_

#include "baseElement.h"
#include "fire.h"
#include "water.h"
#include <string>
#include <list>

class Stone : public Fire, public Water{
public:
	Stone();

	std::list<std::string> delete_elem();

	~Stone();
};

#endif