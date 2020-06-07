#ifndef ENERGY_H_
#define ENERGY_H_

#include "baseElement.h"
#include "air.h"
#include "water.h"
#include <string>
#include <list>


class Energy : public Air, public Water{
public:
	Energy();

	std::list<std::string> delete_elem();

	~Energy();
};

#endif