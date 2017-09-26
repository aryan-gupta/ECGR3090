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
#include <tuple>

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
                my_vec.push_back(2);
                my_vec.push_back(4);
                my_vec.push_back(1);
                my_vec.push_back(3);
                my_vec.push_back(5);
                // my_vec.push_back(6);
               // my_vec.push_back(3);
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
    cout << "Number of inversions " << countInv(my_vec, sort_vec, 0, my_vec.size()) << endl;

    // Sorted array
    for (it = sort_vec.begin(); it != sort_vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <typename TYPE>
void pretty(std::vector<TYPE>& a) {
	for (TYPE e : a) {
		std::cout << e << ' ';
	}
	std::cout << std::endl;
}


template <typename ITER>
std::tuple<
	std::vector<typename std::iterator_traits<ITER>::value_type>,
	int
> merge_sort_merge(ITER lbegin, const ITER& lend, ITER rbegin, const ITER& rend) {
	typedef typename std::iterator_traits<ITER>::value_type TYPE;
	
	int inversion = 0;
	std::vector<TYPE> combined;
	while (lbegin != lend and rbegin != rend) {
		if (*lbegin <= *rbegin) {
			combined.push_back(*lbegin++);
		} else {
			inversion += std::distance(lbegin, lend); // http://www.geeksforgeeks.org/counting-inversions/
			combined.push_back(*rbegin++);
		}
		
	}
	
	combined.insert(combined.end(), lbegin, lend);
	combined.insert(combined.end(), rbegin, rend);
	
	return {combined, inversion};
}

template <typename ITER>
std::tuple<
	std::vector<typename std::iterator_traits<ITER>::value_type>, // vector of values held by input ITER
	int // number of inversions
> merge_sort(const ITER& begin, const ITER& end) {
	// if base case (only one element)
	int len = std::distance(begin, end);
	if (len < 2) { // if we are sorted then return cause its already sorted
		return {{begin, end}, 0};
	}
	
	auto mid = std::next(begin, len / 2); // caculate mid point

#if __cplusplus >= 201703L
	// split and recusively call for first half and second half
	auto [c1, inv1] = merge_sort(begin, mid);
	auto [c2, inv2] = merge_sort(mid, end);
	
	auto [sorted, inv] = merge_sort_merge(c1.begin(), c1.end(), c2.begin(), c2.begin()); // merge the 2 halves and get the number of inversions
#else
	std::vector<typename std::iterator_traits<ITER>::value_type> c1, c2, sorted;
	int inv, inv1, inv2;
	
	std::tie(c1, inv1) = merge_sort(begin, mid);
	std::tie(c2, inv2) = merge_sort(mid, end);
	
	std::tie(sorted, inv) = merge_sort_merge(c1.begin(), c1.end(), c2.begin(), c2.end());
#endif

	return {sorted, inv + inv1 + inv2}; // return the amout of inversions and sorted vector
	
}

int countInv(vector<int> &in_vec, vector<int> &out_vec, int begin, int end) {
	// auto mid = std::next(std::distance(in_vec.end(), in_vec.begin()) / 2); // caculate mid point
	
	std::vector<int> sorted;
	int inv;
	
	std::tie(sorted, inv) = merge_sort(in_vec.begin(), in_vec.end());
	
	out_vec = sorted;
	
	return inv;
}