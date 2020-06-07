#ifndef METAL_H_
#define METAL_H_

#include "baseElement.h"
#include "fire.h"
#include "earth.h"
#include <string>
#include <list>


class Metal : public Earth, public Fire{
public:
	Metal();

	std::list<std::string> delete_elem();

	~Metal();
};

#endif