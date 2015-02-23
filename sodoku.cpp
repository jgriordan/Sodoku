// John Riordan
// Lab 5
// main.cpp

#include "Puzzle.h"

class SodokuComplete{
public:
	static int isComplete(Puzzle<int> *puz){
		for( int i=0; i<puz->size(); i++ ){
			for( int j=0; j<puz->size(); j++ ){
				if( puz->get(i,j) == 0 )
					return 0;
			}
		}
		return 1;
	}
};

int main(){
	std::string fileName;
	std::cout << "Enter the file name of a 9x9 Sodoku: ";
	std::cin >> fileName;

	Puzzle<int> myP(9, fileName);
	std::cout << std::endl << "Current Sodoku:" << std::endl;
	myP.print();
	std::cout << std::endl;

	int row, col, val;
	while( !SodokuComplete::isComplete( &myP ) ){
		row = col = val = -1;
		while( row < 0 || row >= 9 ){
			std::cout << "Enter the row to modify (0-9): ";
			std::cin >> row;
			if( row < 0 || row >= 9 )
				std::cout << "Invalid row." << std::endl;
		}
		while( col < 0 || col >= 9 ){
			std::cout << "Enter the column to modify (0-9): ";
			std::cin >> col;
			if( col < 0 || col >= 9 )
				std::cout << "Invalid column." << std::endl;
		}
		if( myP.get( row, col ) != 0 )
			std::cout << "That location already has a value" << std::endl;
		else{
			while( val < 0 || val >= 9 ){
				std::cout << "Enter the value: ";
				std::cin >> val;
				if( val < 0 || val >= 9 )
					std::cout << "Invalid value." << std::endl;
			}
			myP.set( row, col, val );
		}

		std::cout << std::endl << "Current Sodoku:" << std::endl;
		myP.print();
		std::cout << std::endl;
	}

	std::cout << "The sodoku is complete." << std::endl << std::endl;

	return 0;
}
