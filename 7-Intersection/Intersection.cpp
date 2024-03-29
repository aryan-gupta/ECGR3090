/*
Write a program which takes as input two sorted arrays, and returns a new array containing elements that are present
in both of the input arrays. The input arrays may have duplicate entries, but the returned array should be free of duplicates. 
For example, the input array is <2,3,3,5,5,6,7,7,8,12> and <5,5,6,8,8,9,10,10>, your output array should be <5,6,8>. 
A brute force O(n^2) algorithm is easily obtained. Devise a O(n) algorithm. 
*/
#include <iostream>
#include <vector>

using namespace std;

const int NUM_ELEM = 15;
const int MAX_VAL = 100;

vector<int> intersection(const vector<int>&a, const vector<int>& b);

int main() {
    vector<int> a = {2,3,3,5,5,6,7,8,8,12};
    vector<int> b = {5,5,6,8,8,9,10,10};
    
    vector<int> c = intersection(a,b);
    for (auto elem : c)
        cout << elem << " ";
    cout << endl;
    
    return 0;
    
}

vector<int> intersection(const vector<int>&a, const vector<int>& b) {
	std::vector<int> ret;
	
	std::vector<int>::const_iterator abegin = a.begin(), bbegin = b.begin();
	
	while (abegin != a.end() and bbegin != b.end()) { // go through 2 arrays
		if (*abegin == *bbegin) {
			// https://en.wikipedia.org/wiki/Short-circuit_evaluation
			if (!(ret.size() >= 1 and *abegin == *ret.rbegin())) // checks already created list for duplicates
				ret.push_back(*abegin); // not found in either array or in already created array
			
			// I had to different if statements the one above and this on:
			// if (ret.size() == 0 or *abegin != *ret.rbegin()) // demorgans law -- makes things more efficient
			// after assembly dumb of both if statements, turns out that the compiler optimizations
			// creates 2 line-by-line identical binaries. Chose to keep the one above as it is easier to understand
			
			++abegin;
			++bbegin; // increment both cause oth points to the same value
			continue;
		}
		
		(*abegin < *bbegin)? abegin++ : bbegin++; // different values, increment lesser one
	}
	
	return ret;
}