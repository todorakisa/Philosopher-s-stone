#ifndef GOLD_H_
#define GOLD_H_

#include "baseElement.h"
#include "metal.h"
#include <string>
#include <list>

class Gold : public Metal {
public:
	Gold();

	std::list<std::string> delete_elem();

	~Gold();
};

#endif