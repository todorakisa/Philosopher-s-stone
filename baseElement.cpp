#ifndef BASE_ELEMENT_CPP_
#define BASE_ELEMENT_CPP_

#include "baseElement.h"
#include <list>
#include <string>
#include <iostream>

Base_Element::Base_Element(std::string name_){
	name = name_;
}

std::string Base_Element::get_name(){
	return name;
}
std::list<std::string> Base_Element::get_reactions(){
	return reactions;
}	

void Base_Element::add_reaction(std::string react){
	bool tmp = true;
	for(std::string reaction : reactions){
		if(reaction.compare(react) == 0){
			tmp = false;
		}
	}
	if(tmp){
		reactions.push_back(react);
	}	
}

bool Base_Element::is_reactive_with(Base_Element* elem){
	bool result = false;
	if((name.compare("Water") == 0 || name.compare("Earth") == 0 || name.compare("Air") == 0 || name.compare("Fire") == 0) 
		&& (elem->get_name().compare("Water") == 0 || elem->get_name().compare("Earth") == 0 || elem->get_name().compare("Air") == 0 || elem->get_name().compare("Fire") == 0)){
		for(std::string rec : reactions)
		{
			if(rec.compare(elem->get_name()) == 0){
				result = true;
			}
		}
	}else if(elem->get_name().compare("Water") == 0 || elem->get_name().compare("Earth") == 0 || elem->get_name().compare("Air") == 0 || elem->get_name().compare("Fire") == 0){
		result = true;
		std::list<std::string> elem_reactions = elem->get_reactions();
		for(std::string elem_reaction : elem_reactions)
		{
			bool tmp = false;
			for(std::string reaction : reactions){
				if(elem_reaction.compare(reaction) == 0){
					tmp = true;
				}
			}
			if(!tmp){
				result = false;
			}
		}
	}else if(name.compare("Water") == 0 || name.compare("Earth") == 0 || name.compare("Air") == 0 || name.compare("Fire") == 0){
		result = true;
		std::list<std::string> elem_reactions = elem->get_reactions();
		for(std::string elem_reaction : reactions)
		{
			bool tmp = false;
			for(std::string reaction : elem_reactions){
				if(elem_reaction.compare(reaction) == 0){
					tmp = true;
				}
			}
			if(!tmp){
				result = false;
			}
		}
	}else{
		result = true;
		std::list<std::string> elem_reactions = elem->get_reactions();
		for(std::string elem_reaction : elem_reactions)
		{
			bool tmp = false;
			for(std::string reaction : reactions){
				if(elem_reaction.compare(reaction) == 0){
					tmp = true;
				}
			}
			if(!tmp){
				result = false;
			}
		}
	}
	
	return result;
}

std::list<std::string> Base_Element::delete_elem(){
	std::list<std::string> result;
	result.push_back(name);
	result.push_back(name);
	return result;
}


void Base_Element::print_reactions(){
	std::cout << "Name of element: " << name << std::endl;
	std::cout << "Can react with: ";
	for (std::string rec : reactions)
	{
		std::cout << rec << ", ";
	}
	std::cout << std::endl;
}

Base_Element::~Base_Element(){}

#endif