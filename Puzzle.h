// John Riordan
// Lab 5
// Puzzle.h

#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

template<typename T>
class Puzzle{
public:
	Puzzle(int,std::string);// non-default constructor
	T get(int,int);// gets the value from a specified location
	void set(int,int,T);// sets a location to the specified value
	void print();
	int size();
private:
	std::vector< std::vector<T> > myPuzzle;// the puzzle itself- 2D dynamic array of T
	int dim;// dimension of the puzzle
};

template <typename T>
Puzzle<T>::Puzzle(int n, std::string fileName){// non-default constructor
	dim = n;
	if( dim != 9 && dim != 4 && dim != 16 ){// check that parameter is 4, 9, or 16
		std::cout << dim << " is not a valid value for the dimension of the puzzle." << std::endl;// error message
		dim = 9;// set the parameter to the default value
	}

	std::ifstream myFile(fileName.c_str());

	for( int i=0; i<dim; i++ ){// loop through rows
		std::vector<T> tempVec;
		for( int j=0; j<dim; j++ ){
			T temp;
			myFile >> temp;
			tempVec.push_back(temp);
		}
		myPuzzle.push_back(tempVec);
	}
}

template <typename T>
T Puzzle<T>::get(int x, int y){
	if( x < 0 || y < 0 || x >= dim || y >= dim ){// check if in valid range
		std::cout << "Cannot get the value at (" << x << ", " << y << ").  Out of range." << std::endl;// error message
		return NULL;
	}
	return myPuzzle[x][y];
}

template <typename T>
void Puzzle<T>::set(int x, int y, T value){
	if( x < 0 || y < 0 || x >= dim || y >= dim )// check if in valid range
		std::cout << "Cannot set the value at (" << x << ", " << y << ").  Out of range." << std::endl;// error message
	else
		myPuzzle[x][y] = value;
}

template <typename T>
void Puzzle<T>::print(){
	for( int i=0; i<dim; i++ ){
		for( int j=0; j<dim; j++ )
			std::cout << myPuzzle[i][j] << " ";
		std::cout << std::endl;
	}
}

template <typename T>
int Puzzle<T>::size(){
	return dim;
}

#endif
