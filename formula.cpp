#ifndef FORMULA_CPP_
#define FORMULA_CPP_

#include <iostream>
#include <list>

#include "baseElement.h"
#include "formula.h"

Formula::Formula(){}

std::list<Base_Element*> Formula::get_starting_elements(){
	return starting_elements;
}

std::list<Base_Element*> Formula::get_result_elements(){
	return result_elements;
}

void Formula::add_starting_elem(Base_Element* elem){
	starting_elements.push_back(elem);
}

void Formula::add_result_elem(Base_Element* elem){
	result_elements.push_back(elem);
}

void Formula::print_formula(){
	if(starting_elements.size() == 1){
		std::cout << "/" << starting_elements.back()->get_name() << std::endl;
		return;
	}
	int i = 0;
	for(Base_Element* elem : starting_elements){
		if(i == 0){
			std::cout << elem->get_name();
		}else{
			std::cout << " + " << elem->get_name();
		}
		i++;
	}
	std::cout << " = ";
	i = 0;
	for(Base_Element* elem : result_elements){
		if(i == 0){
			std::cout << elem->get_name();
		}else{
			std::cout << " + " << elem->get_name();
		}
		i++;
	}
	std::cout << std::endl;
}

Formula::~Formula(){
	for(Base_Element* elem : starting_elements){
		delete elem;
	}

	for(Base_Element* elem : result_elements){
		delete elem;
	}
}

#endif