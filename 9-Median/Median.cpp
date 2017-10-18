/*
Given: A sequence of numbers x1, x2, ..., xn input one-by-one, find the median as the numbers arrive. 
See Heap lecture - 1 for solution. Solution implemented using a min-heap and max-heap that holds the bottom half and top half of the numbers respectively.

Heaps are implemented using the priority_queue container from the STL

The test function is provided below. Also included is a function print_queue if you need to view the contents of the heaps at any point. 
*/

#include <iostream>
#include <queue>
#include <vector>
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

 // Your code here...

 

}