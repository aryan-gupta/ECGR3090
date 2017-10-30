/*
Write a program that takes as input a set of words and returns groups of anagrams
for those words. Here's the test program - 
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);


float test_hash();

int main() 
{
  vector<string> word_list = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom",    "listen", "levis"};
   vector<vector<string>> result = findAnagrams(word_list);
   for (auto anagrams: result) {
      for (auto words: anagrams)
         cout << words << " ";
         cout << endl;
    }
	
	test_hash();
   return 0;
}

// placement independent string hash. 
struct pi_str_hash { /// todo test collision resistance of this guy
	constexpr static unsigned shift = 15;
	
	size_t operator()(const std::string& str) const {
		using ull = unsigned long long;
		
		ull pre_hash{};
		std::hash<ull> alg;
		
		for (char ch : str) { // we want to hash the actual char and not the placement
			ull num = ch; // cast
			num <<= (num % shift);
			pre_hash += alg(num);
		}
		
		size_t hash = pre_hash % std::numeric_limits<size_t>::max();
		
		return hash;
	}
};

struct pi_str_equal {
	const static pi_str_hash h; // prevent it from being recreated eveytime we call this callable
	
	bool operator() (const std::string& a, const std::string& b) const {
		return h(a) == h(b);
	}
};

const pi_str_hash pi_str_equal::h{}; // instantize out of class cause ints are the only
// ones that can be instantize in class

vector<vector<string>> findAnagrams(const vector<string>& dict)
{
	
	using anagram_map_t = std::unordered_map< std::string, std::vector<std::string>, pi_str_hash, pi_str_equal>;
	anagram_map_t anagrams;
	
	for (const auto& str : dict) {
		anagrams[str].push_back(str);
	}
	
	std::vector<std::vector<std::string>> ret_val;
	
	for (auto begin = anagrams.begin(), end = anagrams.end(); begin != end; ++begin) {
		if (begin->second.size() > 1)
			ret_val.push_back(begin->second);
	}
	
	return ret_val;
	
}

float test_hash() {
	const static int MAX_SIZE = 3;
	
	unsigned long long total_num{}, found_hash{};
	
	//std::hash<std::string> hasher;
	pi_str_hash hasher;
	std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890$";
	std::string to_test = "AAA";
	
	// std::cout << std::pow(chars.size() - 1, to_test.size());
	
	unordered_set<size_t> rainbow_table; // im testing collisions not going to worry about pair
	
	// for (int size = 1; size < MAX_SIZE; ++size) {
		std::string end(3, '0');
		while (to_test != end) { // go through all the posiblities
			// std::cout << to_test << std::endl;
			
			auto hash = hasher(to_test);
			++total_num;
			if (rainbow_table.find(hash) != rainbow_table.end()) {
				++found_hash;
				// std::cout << "Found Collision" << std::endl;
			}
			
			rainbow_table.insert(hash);
			
			// incrment
			to_test[to_test.size() - 1] = chars.at(chars.find(to_test[to_test.size() - 1]) + 1); // increment letter
			
			for (int j = to_test.size() - 1; j >= 0; --j) {
				if (to_test[j] == '$') {
					to_test[j] = 'A';
					if (j != 0)
						to_test[j - 1] = chars.at(chars.find(to_test[j - 1]) + 1);
				} // else { break; }
			}
			
			// std::cout << found_hash << '\t' << total_num << std::endl;
		}
		
		// add letter
		// to_test.push_back('A');
	// }
	
	std::cout << double(found_hash) / total_num << std::endl;
	
}