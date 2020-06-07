#ifndef BASE_ELEMENT_H_
#define BASE_ELEMENT_H_

#include <list>
#include <string>

class Base_Element{
	std::string name;
	std::list<std::string> reactions;
public:
	Base_Element(std::string name_);
	std::string get_name();
	std::list<std::string> get_reactions();
	void add_reaction(std::string react);
	bool is_reactive_with(Base_Element* elem);
	virtual std::list<std::string> delete_elem();
	void print_reactions();
	virtual ~Base_Element();
};

#endif