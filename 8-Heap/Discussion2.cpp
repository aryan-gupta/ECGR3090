#include <iostream>
#include <functional>

// This is the signature for the template, as you can seekdir
// the T is kind of obvious, it is the type of variable I want
// be it int, or a double. The second template parameter is 
// where it gets interesting. F is a type of object that contains
// our function that returns wheather one item is greate than 
// the other. If we have a line of code:: int a = 5; then we can 
// deduce that int is the type, a is the name and 5 is the value
// Similary a function is also a type. And the type is a bit 
// complicated. For example, bool(*)(int, double) is a type
// (like int, or double) its a type of function that takes an int
// and a double and returns a bool. we can name the funtion like this
// bool(*DoIt)(int, double), where DoIt is the name, we can later
// call it by doing this DoIt(1, 3.14); We will discuss this more
// in a min. The = std::less<T> is just the default value, its so 
// we can create a class with GetMag<int> and the compare Function
// will automatically default to less than. 
template <typename T, typename F = std::less<T>>
// template <typename T, typename F>
class GetMag {
public:
	// Here we are doing to have a basic constructor. Remember F is
	// a type so we have to create an instance of it, we are going
	// to create a default instance of the compare function. If you are
	// confused on why, I will talk about callable objects a bit later
	GetMag(T a, T b) 
	: mVal1{a}, mVal2{b}, mFunc{} {}
	
	// Here the constructor takes a parameter of F, this means we can pass
	// an acutal function to be our compare funtion. Remember F is out type
	// and mFunc is the name of the function variable. It really helps if you
	// think of functions as a function object 
	GetMag(T a, T b, F func) 
	: mVal1{a}, mVal2{b}, mFunc{func} {}
	
	// This functions evaluates the function that we created in our constructor. 
	bool getValue() {
		return mFunc(mVal1, mVal2);
	}
	
private:
	T mVal1;
	T mVal2;
	F mFunc;
	
};

// So here is somthing cool, If you have a object that has the operator() overloaded, 
// like here, it means that it is a callable type. like if you overload a class with []
// you can do somthing like vec[2]; . In that exaample, it will return the 3rd object.
// Now, if you overload operator() , you can call it like this callme(); if you want
// to learn more about this, google is your best friend.
// https://stackoverflow.com/questions/19278424/what-is-a-callable-object-in-c 
struct LessThanOBJ {
	bool operator() (const int& a, const int& b) {
		return a < b;
	}
};

// This is a function. The type of function is bool (*) (int, int) . (returns a bool
// and has 2 integers as parameters). This is the full signature of the function 
// is bool (*LessThanFUNC) (int, int)
bool LessThanFUNC(int a, int b) {
	return a < b;
}

int main() {
	// So remember our callable object, well we are going to use that type (a class
	// is a type) as out lessthan function. When the first consructor runs, it will
	// create an instance of LessThanOBJ and will call is when we call GetMag::getValue()
	// take note we did not call the second constructor, meaning the LessThanOBJ will
	// be created with the default constructor
	GetMag<int, LessThanOBJ> tmp1(4, 5);
	std::cout << (tmp1.getValue() ? "True" : "False") << std::endl; // true
	
	// std::greater<T> is also a callable object, however, it is a object that is given
	// by the standard library, in order to use it, the operator> HAS to be defined. 
	// In Assignment 8, if you take a look at task.h, you will see that only the
	// operator< is defined, meaning if we used this, it will FAIL. You can see
	// a example of how std::greater<T> is implemented here: 
	// http://en.cppreference.com/w/cpp/utility/functional/greater
	// scroll all the ewy to the bottom. 
	// std::greater<t> is for greater than operator, std::less<T> is for less than
	GetMag<int, std::greater<int> > tmp2(4, 5);
	std::cout << (tmp2.getValue() ? "True" : "False") << std::endl; // false
	
	// Remember how we talked about funtion objects? Well LessThanFUNC is of type
	// bool (*) (int, int) so thats why we will use that as our second parameter,
	// then when we construct our object we will pass our function, to our constructor
	// if you want to get deaper in to it bool(*)(int, int) is a functional pointer
	// hense the * after the bool and LessThanFUNC is a pointer to the function we
	// declared up there. So when we call somthing like func(1, 3.0), we are techically
	// calling the address of func with parameters of 1 and 3.0. Fun stuff. Am I right?
	GetMag<int, bool (*) (int, int) > tmp3(4, 5, LessThanFUNC);
	std::cout << (tmp3.getValue() ? "True" : "False") << std::endl; // true

	// But what if we want dont want to create a whole seperate function for our object
	// Lamdas come to save the day. A lambda is a function that is inside of another
	// function, so the lambda here is defined inside of the main() function. The basic
	// syntax of a lambda is [](){} . Cool right? Inside the parentesis goes the parameters
	// and inside the braces goes the code, I am pretty sure we touched this if you took 
	// ECGR 2104 (C++ 2). Remeber Sorting? 
	// std::sort(vec.begin(), vec.end(), [](int a, int b){ return a < b; })
	// but messing around with raw pointers is a bad idea so lets do somthing else
	GetMag<int, bool (*) (int, int) > tmp4(4, 5, [](int a, int b) { return a > b; });
	std::cout << (tmp4.getValue() ? "True" : "False") << std::endl; // false
	
	// The STL Library has a cool class called functional which holds a function. Becuase its
	// generally a bad idea to have naked pointers, we are going to use this. Because function
	// isnt holding a pointer but an actual function we dont need the * so the whole thing 
	// collapses to bool (int, int) . Here we also have the lambda expression for our actual
	// compare function. Remeber to add the proper header at the top #include <functional>
	GetMag<int, std::function<bool(int, int)> > tmp5(4, 5, [](int a, int b) { return a > b; });
	std::cout << (tmp5.getValue() ? "True" : "False") << std::endl; // false
	
	// Remeber how we had a default value for the F template parameter? Well because the default
	// is less<T>, then this will automatically call less<T>(4, 5) and as we discussed in the 
	// callable objects section, this will in turn call return 4 < 5; which is true. 
	GetMag<int> tmp6(4, 5);
	std::cout << (tmp6.getValue() ? "True" : "False") << std::endl; // true
	
}