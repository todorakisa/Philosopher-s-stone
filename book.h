#ifndef BOOK_H_
#define BOOK_H_

#include "formula.h"
#include <list>
#include <string>

class Book{
	std::list<Formula*> formulas;
	std::list<Formula*> not_valid_formulas;
	std::list<Formula*> del_formulas;
public:
	Book();
	void add_formula(Formula *formula);
	void setup(std::string filename);
	void printBook();
	std::list<Formula*> get_valid_formulas();
	std::list<Formula*> get_not_valid_formulas();
	std::list<Formula*> get_del_formulas();
	~Book();
};

#endif