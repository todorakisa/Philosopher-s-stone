#ifndef PHILOSOPHERSTONE_H_
#define PHILOSOPHERSTONE_H_

#include "air.h"
#include "water.h"
#include "earth.h"
#include "fire.h"

class PhilosopherStone : public Air, public Water, public Earth, public Fire{
public:
	PhilosopherStone();
	~PhilosopherStone();
};

#endif
