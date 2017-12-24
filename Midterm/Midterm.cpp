/*
You are given an array that contains N numbers. You want to determine if there are two numbers whose sum equals a given number K. For instance, if the input is 8, 4, 1, 6, and K is 10, then the answer is true (4 and 6), whereas for K = 11, the input is false. A number may be used twice.

Do the following:

a. Give an O(N^2) algorithm to solve the problem.

b. Give an O(N log N) algorithm to solve the problem.

c. Code your solution (the better one) in the form of the function indicated below. Also, write a test program to see if your code works. You are allowed to use any library from the STL.
*/

// O(N^2) algorithm:
// foreach element in array
//    for element2 from element.next to array.end
//        if element + element2 == 10
//            return true
// return false

#include <iostream>
#include <vector>
using std::vector;
#include <algorithm>

bool hasNumber(vector<int>& vec, int K);

int main() {
	std::vector<int> vec1 = {8, 0, 4, 9, 9, 9, 9, 9, 9, 9, 9, 5, 5, 7, 3};
	// pretty(vec1);
	
	bool b1 = hasNumber(vec1, 10);
	
	std::cout << ((b1)? "Has Number" : "Does not have number") << std::endl;
}

bool hasNumber(vector<int>& vec, int K) {
	// go through backwards and forwards
	// if sum of values is to big
	// decrement large value
	// else decremt smaller value
	// if found sum, return true
	// else return false
	
	std::sort(vec.begin(), vec.end());
	
	std::vector<int>::const_iterator fbegin = vec.begin();
	std::vector<int>::reverse_iterator rbegin = vec.rbegin();
	
	while (fbegin != vec.end() and rbegin != vec.rend()) {
		decltype(*fbegin) sum = *fbegin + *rbegin;
		
		if (sum == K)
			return true;
		
		/// there should be a way to make this better
		if (sum > K) // sum is too big, decrement larger value
			if (*fbegin > *rbegin) 
				++fbegin;
			else
				++rbegin;
		else
			if (*fbegin > *rbegin) 
				++rbegin;
			else
				++fbegin;
	}
	
	return false;
}
/*
Write the pseudo code for the 2 solutions in comments. Please upload your file as <your_lastname>.cpp
*/
