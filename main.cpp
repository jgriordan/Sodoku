// John Riordan
// Lab 5
// main.cpp

#include "Puzzle.h"

int main(){
	std::string fileName;
	std::cout << "Enter the file name of a 9x9 Sodoku or Wordoku: ";
	std::cin >> fileName;

	Puzzle<int> myP(9, fileName);
	myP.print();

	return 0;
}
