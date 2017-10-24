/*
Given: A sequence of numbers x1, x2, ..., xn input one-by-one, find the median as the numbers arrive. 
See Heap lecture - 1 for solution. Solution implemented using a min-heap and max-heap that holds the bottom half and top half of the numbers respectively.

Heaps are implemented using the priority_queue container from the STL

The test function is provided below. Also included is a function print_queue if you need to view the contents of the heaps at any point. 
*/

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;

const int MAX_VAL = 100;
const int NUM_ELEM = 15;

int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num);
template<typename T> void print_queue(T& q);

int main() {
    int current_median;
    priority_queue<int> lo; // Bottom half of numbers - max-heap (default) 
    priority_queue<int, vector<int>, greater<int> > hi; // Top half of numbers - min-heap 
    srand(time(0)); // Seed for random number generator
    for (int i = 0; i < NUM_ELEM; i++) {
        int n = rand() % MAX_VAL;
        current_median = find_median(hi, lo, n);
		// print_queue(lo);
		// print_queue(hi);
        cout <<  "Inserted " << n << " Median " << current_median << endl << endl;
    }
    return 0;
}

template<typename T> void print_queue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        std::cout << q_copy.top() << " ";
        q_copy.pop();
    }
    std::cout << '\n';
}
 

int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num) {
	if (h_low.size() == 0 and h_high.size() == 0) {
		h_low.push(num);
		return num;
	}
	
	if (num < h_low.top())
		h_low.push(num);
	else
		h_high.push(num);
	
	while (static_cast<int>(h_high.size()) - static_cast<int>(h_low.size()) > 1) { // h_high is bigger
		h_low.push(h_high.top());
		h_high.pop();
	}
	
	while (static_cast<int>(h_low.size()) - static_cast<int>(h_high.size()) > 1) { // h_low is hbigger
		h_high.push(h_low.top());
		h_low.pop();
	}
	
	switch (static_cast<int>(h_high.size()) - static_cast<int>(h_low.size())) {
		case 0: // if they have the same length return the larger one
			return h_high.top();
		case 1: // h_high is larger
			return h_high.top();
		case -1: // h_low is larger
			return h_low.top();
		default:
			std::cerr << "Size Mismatch" << std::endl;
			throw "Size Mismatch";
	}
}