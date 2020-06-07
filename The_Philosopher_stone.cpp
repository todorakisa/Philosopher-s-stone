#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>

#include "alchemist.h"

using namespace std;

int main(){
	cout << "In order to use the program you need file <name>.txt for formulas!" << endl;
	cout << "For example book.txt:" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Air + Air = Spirit" << endl;
	cout << "Metal + Stone = Gold" << endl;
	cout << "Fire + Earth = Metal" << endl;
	cout << "Fire + Water + Earth = Gold" << endl;
	cout << "Water + Earth = Stone" << endl;
	cout << "Spirit + Air = Energy" << endl;
	cout << "Gold + Spirit + Earth = Philosopher’s Stone" << endl;
	cout << "/Fire" << endl;
	cout << "Energy + Earth = Stone" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "And you will need file <name>.txt for inventory!" << endl;
	cout << "For example inventory.txt:" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "3 Earth" << endl;
	cout << "4 Fire" << endl;
	cout << "1 Water" << endl;
	cout << "10 Air" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	Alchemist Nikola_Flamel;
	string file;
	cout << "Enter a file with formulas:" << endl;
	cin >> file;
	Nikola_Flamel.setupBook(file);
	cout << "Enter a file whith owned elements:" << endl;
	cin >> file;
	cout << endl;
	Nikola_Flamel.setupInventory(file);

	Nikola_Flamel.print_valid_formulas();
	Nikola_Flamel.print_not_valid_formulas();
	
	Nikola_Flamel.printInventroy();
	cout << endl;
	Nikola_Flamel.findPhilosophersStone();
	return 0;
}