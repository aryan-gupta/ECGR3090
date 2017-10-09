
// BEGIN OF "Pair.h"
#ifndef PAIR_H
#define PAIR_H

template <typename T>
class Pair {
public:
	Pair(T one, T two);
	
	// Im going to define these outside 
	// the definition see code below
	const T& get_one() const;
	const T& get_two() const ;
	
	// Im going to define these 
	// two finctions inside of the
	// declaration
	void set_one(T item) {
		mOne = item;
	}
	
	void set_two(T item) {
		mTwo = item;		
	}
	
private:
	T mOne;
	T mTwo;
	
};


// Here Im going to define my class

// constructor
template <typename T>
Pair<T>::Pair(T one, T two)
: mOne{one}, mTwo{two}
{ /* no code */ }


// get one function
template <typename T>
const T& Pair<T>::get_one() const {
	return mOne;
}

// get two function
template <typename T>
const T& Pair<T>::get_two() const {
	return mTwo;
}

#endif
// END OF "Pair.h"

// BEGIN OF "main.cpp"

#include <iostream>
#include <string>

#ifndef PAIR_H
	#include "Pair.h"
#endif


int main() {
	Pair<double> pi_e(3.14, 2.71);
	std::cout << pi_e.get_one() << std::endl; // 3.14
	std::cout << pi_e.get_two() << std::endl; // 2.71
	
	Pair<std::string> name("John", "Doe");
	std::cout << name.get_one() << std::endl; // John
	std::cout << name.get_two() << std::endl; // Doe
	
	name.set_one("Buttercup");
	name.set_two("CumberSnatch");
	std::cout << name.get_one() << std::endl; // Buttercup
	std::cout << name.get_two() << std::endl; // CumberSnatch
	
	return 0;
}

// END OF "main.cpp"