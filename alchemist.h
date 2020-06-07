#ifndef ALCHEMIST_H_
#define ALCHEMIST_H_

#include "book.h"
#include "formula.h"
#include <map>
#include <list>
#include <string>

class Alchemist{
	Book book;
	std::map<std::string,int> inventory;
	std::list<Formula*> right_order;
public:
	Alchemist();
	void setupBook(std::string file);
	void setupInventory(std::string file);
	void print_not_valid_formulas();
	void print_valid_formulas();
	bool findPhilosophersStone();
	bool rec_find(Formula* start);
	void printInventroy();
	~Alchemist();
};

#endif