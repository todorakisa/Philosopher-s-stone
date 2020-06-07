#ifndef BOOK_CPP_
#define BOOK_CPP_

#include "book.h"
#include "formula.h"
#include "baseElement.h"
#include "factory.h"

#include <fstream>
#include <iostream>

Book::Book(){}

void Book::add_formula(Formula *formula){

	bool valid = true;
	std::list<Base_Element*> starting_elemets = formula->get_starting_elements();
	if(starting_elemets.size() == 1){
		del_formulas.push_back(formula);
		return;
	}
	for(std::list<Base_Element*>::iterator it = starting_elemets.begin();it!= starting_elemets.end();++it){
		for(std::list<Base_Element*>::iterator ti = starting_elemets.begin();ti!= starting_elemets.end();++ti){
			if(it != ti){
				if((*it)->is_reactive_with(*ti) == false || (*ti)->is_reactive_with(*it) == false){
					valid = false;
				}
			}
		}
	}
	if(valid){
		formulas.push_back(formula);
	}else{
		not_valid_formulas.push_back(formula);
	}
}

void Book::setup(std::string filename){
	std::string word;
	bool status = false;
	std::ifstream myfile (filename);

	if (myfile.is_open())
	{	
		Formula *f = new Formula();
		while (myfile >> word)
		{
			if(word.compare("+") == 0){
				status = false;
			}else if(word.compare("=") == 0){
				status = true;
			}else if(word[0]!='/'){
				if(word.compare("Philosopher’s")==0){
					std::string fix;
					myfile >> fix;
					word += " ";
					word += fix;
				}
				Base_Element* elem = Factory::make(word);
				if(elem == nullptr){
					std::cout << "Wrong file!" << std::endl;
					break;
				}else{
					
					if(status){
						f->add_result_elem(elem);
						add_formula(f);
						f = new Formula();
					}else{
						f->add_starting_elem(elem);
					}
					status = false;
				}
			}else{
				std::string new_word;
				for (int i = 1; i < word.size(); ++i)
				{
					new_word += word[i];
				}

				Base_Element* elem = Factory::make(new_word);
				if(elem == nullptr){
					std::cout << "Wrong file!" << std::endl;
					break;
				}else{
					f->add_starting_elem(elem);
					std::list<std::string> elems = elem->delete_elem();
					Base_Element* elem1 = Factory::make(elems.back());
					elems.pop_back();
					Base_Element* elem2 = Factory::make(elems.back());
					elems.pop_back();
					f->add_result_elem(elem1);
					f->add_result_elem(elem2);
					add_formula(f);
					f = new Formula();
				}
			}
		}
		delete f;
		myfile.close();
	}else{
		std::cout << "The file could't be opened!" << std::endl;
	}
}

void Book::printBook(){
	std::cout << "Valid formulas:" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for(Formula* f : formulas){
		f->print_formula();
	}
	for(Formula* f : del_formulas){
		f->print_formula();
	}
	std::cout << std::endl;
	std::cout << "Not valid formulas:" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for(Formula* f : not_valid_formulas){
		f->print_formula();
	}
	std::cout << std::endl;
}

std::list<Formula*> Book::get_valid_formulas(){
	return formulas;
}

std::list<Formula*> Book::get_not_valid_formulas(){
	return not_valid_formulas;
}

std::list<Formula*> Book::get_del_formulas(){
	return del_formulas;
}

Book::~Book(){
	for(Formula* f : formulas){
		delete f;
	}

	for(Formula* f : not_valid_formulas){
		delete f;
	}

	for(Formula* f : del_formulas){
		delete f;
	}
}

#endif