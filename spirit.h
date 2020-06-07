#ifndef SPIRIT_H_
#define SPIRIT_H_

#include "baseElement.h"
#include "air.h"
#include <string>
#include <list>

class Spirit : public Air {
public:
	Spirit();

	std::list<std::string> delete_elem();

	~Spirit();
};

#endif