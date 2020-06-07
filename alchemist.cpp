#ifndef ALCHEMIST_CPP_
#define ALCHEMIST_CPP_

#include "book.h"
#include "baseElement.h"
#include "formula.h"
#include "alchemist.h"
#include "factory.h"
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

Alchemist::Alchemist(){}

void Alchemist::setupBook(std::string file){
	book.setup(file);
}

void Alchemist::setupInventory(std::string file){
	std::string elem;
	int quantity = 0;
	int status = 0;
	std::ifstream myfile (file);

	if (myfile.is_open())
	{	
		while(myfile >> elem){
			if(status == 0){
				quantity = stoi(elem);
				status = 1;
			}else if(status == 1){
				status = 0;
				inventory.insert(std::make_pair(elem,quantity));
			}
		}
		
		myfile.close();
	}else{
		std::cout << "The file could't be opened!" << std::endl;
	}
}

void Alchemist::print_not_valid_formulas(){
	std::list<Formula*> formulas = book.get_not_valid_formulas();
	std::cout << "Not valid formulas:" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for(Formula* f : formulas){
		f->print_formula();
	}
	std::cout << std::endl;
}

void Alchemist::print_valid_formulas(){
	std::list<Formula*> formulas = book.get_valid_formulas();
	std::cout << "Valid formulas:" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for(Formula* f : formulas){
		f->print_formula();
	}
	std::cout << std::endl;
}

bool Alchemist::findPhilosophersStone(){
	bool result = true;
	std::list<Formula*> formulas = book.get_valid_formulas();
	std::list<Formula*> del_formulas = book.get_del_formulas();
	Formula* start = nullptr;

	for(Formula* f : formulas){
		std::string name = f->get_result_elements().back()->get_name();
		if(name.compare("Philosopher’s Stone") == 0){
			start = f;
		}
	}

	if(rec_find(start)){
		std::cout << "It's possible to create the mighty stone!" << std::endl;
		std::cout << "The way: " << std::endl;
		for(Formula* f : right_order){
			f->print_formula();
		}
		std::cout << std::endl;
		printInventroy();
		return true;
	}else{
		std::cout << "It's NOT possible to create the mighty stone!" << std::endl;
		return false;
	}
}

bool Alchemist::rec_find(Formula* start){
	bool ended = true;
	std::map<std::string,int>::iterator it;

	std::list<Base_Element*> starting_elements = start->get_starting_elements();
	int size = starting_elements.size();
	if(size == 1){
		it = inventory.find(starting_elements.back()->get_name());
		if(it != inventory.end()){
			if(it->second == 0){
				return false;
			}else{
				it->second--;
				Base_Element* elem = Factory::make(it->first);
				std::list<std::string> elems = elem->delete_elem();
				for(std::string el : elems){
					Base_Element* e = Factory::make(el);
					it = inventory.find(e->get_name());
					if(it != inventory.end()){
						it->second++;
					}else{
						inventory.insert(make_pair(e->get_name(),1));
					}
				}
				right_order.push_back(start);
				return true;
			}
		}else{
			return false;
		}
	}

	int found = 0;
	for(Base_Element* elem : starting_elements){
		it = inventory.find(elem->get_name());
		if(it != inventory.end()){
			if(it->second == 0){
				bool break_ = false;
				std::list<Formula*> del_formulas = book.get_del_formulas();
				for(Formula *f : del_formulas){
					std::list<Base_Element*> result_elements = f->get_result_elements();
					for(Base_Element* el : result_elements){
						if(el->get_name().compare(elem->get_name()) == 0){
							if(rec_find(f)){
								right_order.push_back(start);
								found++;
								it->second--;
								break_ = true;
								break;
							};
						}
					}
					if(break_) break;
				}
				if(!break_){
					return false;
				}
			}else if(it->second == 1 && (it->first.compare("Water") == 0 || it->first.compare("Earth") == 0 || it->first.compare("Fire") == 0 || it->first.compare("Air") == 0)){
				bool break_ = false;
				std::list<Formula*> del_formulas = book.get_del_formulas();
				for(Formula *f : del_formulas){
					std::list<Base_Element*> result_elements = f->get_result_elements();
					for(Base_Element* el : result_elements){
						if(el->get_name().compare(elem->get_name()) == 0){
							if(rec_find(f)){
								right_order.push_back(f);
								found++;
								break_ = true;
								break;
							};
						}
					}
					if(break_) break;
				}
				if(!break_){
					found++;
					it->second--;
				}
			}else if(it->second > 1){
				found++;
				it->second--;
			}
		}else{
			bool founded_in_normal_formulas = false;
			std::list<Formula*> formulas = book.get_valid_formulas();
			for(Formula *f : formulas){
				if(f->get_result_elements().back()->get_name().compare(elem->get_name()) == 0){
					if(rec_find(f)){
						found++;
						founded_in_normal_formulas = true;
						break;
					};
				}
			}

			bool break_ = false;
			if(!founded_in_normal_formulas){
				std::list<Formula*> del_formulas = book.get_del_formulas();
				for(Formula *f : del_formulas){
					std::list<Base_Element*> result_elements = f->get_result_elements();
					for(Base_Element* el : result_elements){
						if(el->get_name().compare(elem->get_name())){
							if(rec_find(f)){
								found++;
								break_ = true;
								break;
							};
						}
					}
					if(break_) break;
				}
			}
		}
	}
	if(found == size){
		right_order.push_back(start);
		return true;
	}else{
		return false;
	}
}

void Alchemist::printInventroy(){
	std::cout << "The inventory of the Alchemist:" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (auto const &pair : inventory)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
}

Alchemist::~Alchemist(){}

#endif