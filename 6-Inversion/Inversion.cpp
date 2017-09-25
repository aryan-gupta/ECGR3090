/*Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

What would the complexity of a brute force approach be? Code an O(nlog(n)) algorithm to count the number of inversions. Hint - piggy back on the merging step of the mergesort algorithm.

Here's the test program - 
/* Test cases - 1) Random array mixed positive and negative numbers 2) Sorted array 3) Reverse sorted array 4) Custom input */ 
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

const int NUM_ELEM = 15;
const int MAX_VAL = 100;

int countInv(vector<int> &in_vec, vector<int> &out_vec, int begin, int end); 

int main(int argc, char **argv)
{
    vector<int> my_vec;
    vector<int>::iterator it;
    srand(time(0)); // Seed for random number generator
    assert(argc == 2);
    switch(atoi(argv[1])) {
        case 1:
                // Input vector of positive and negative random ints
                for (int i = 0; i < NUM_ELEM; i++)
                    my_vec.push_back(rand() % MAX_VAL - (MAX_VAL/2));
                break;
        case 2:
                // Input vector of sorted ints
                for (int i = 0; i < NUM_ELEM; ++i)
                    my_vec.push_back(i);
                break;
        case 3: 
                // Input vector of reverse sorted ints
                for (int i = 0; i < NUM_ELEM; ++i)
                    my_vec.push_back(NUM_ELEM-i);
                break;
        case 4:
                // Custom input
                my_vec.push_back(4);
                my_vec.push_back(5);
                my_vec.push_back(6);
                my_vec.push_back(1);
                my_vec.push_back(2);
                my_vec.push_back(3);
                break;
        default: 
                cout << "Invalid input" << endl;
                return -1;
        
    }
    
    // Print vector
    for (it = my_vec.begin(); it !=  my_vec.end(); ++it)
        cout << *it << " ";
    cout << endl << endl;
    
    vector<int> sort_vec(my_vec);
    cout << "Number of inversions " << mergeSort(my_vec, sort_vec, 0, my_vec.size()) << endl;

    // Sorted array
    for (it = sort_vec.begin(); it != sort_vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int countInv(vector<int> &in_vec, vector<int> &out_vec, int begin, int end) {

 // Your code goes here

}