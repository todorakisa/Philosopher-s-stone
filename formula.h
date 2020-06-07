#ifndef FORMULA_H_
#define FORMULA_H_

#include "baseElement.h"
#include <list>

class Formula{
	std::list<Base_Element*> starting_elements;
	std::list<Base_Element*> result_elements;
public:
	Formula();
	std::list<Base_Element*> get_starting_elements();
	std::list<Base_Element*> get_result_elements();
	void add_starting_elem(Base_Element* elem);
	void add_result_elem(Base_Element* elem);
	void print_formula();
	~Formula();
};

#endif