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
	
   return 0;
}

// placement independent string hash. 
struct pi_str_hash {
	// Tried this without google, got a hash collision ratio of 0.0112282 (1.112282%)
	// then found this: https://stackoverflow.com/questions/18781106/
	
	static const std::string alpha;
	static const std::vector<unsigned> primes;
	
	size_t operator()(const std::string& str) const {
		uint64_t pre_hash{1};
		
		for (char c : str) {
			pre_hash *= primes.at(alpha.find(c));
		}
		
		return pre_hash % std::numeric_limits<size_t>::max();
	}
};

// 26 + 26 + 10 = 62 letters
// 75 primes
// we can add more characters later on 
const std::string pi_str_hash::alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
const std::vector<unsigned> pi_str_hash::primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379};

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

float test_hash() { // lol this is becoming messy
	const static int MAX_SIZE = 3;
	
	unsigned long long total_num{}, found_hash{};
	
	//std::hash<std::string> hasher;
	pi_str_hash hasher;
	std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890$";
	std::string to_test = "aaa";
	
	// std::cout << std::pow(chars.size() - 1, to_test.size());
	
	unordered_map<size_t, std::string> rainbow_table; // im testing collisions not going to worry about pair
	
	// for (int size = 1; size < MAX_SIZE; ++size) {
		std::string end(3, '0');
		while (to_test != end) { // go through all the posiblities
			// std::cout << to_test << std::endl;
			
			auto hash = hasher(to_test);
			++total_num;
			
			std::string sorted{to_test};
			std::sort(sorted.begin(), sorted.end());			
			if (rainbow_table.find(hash) != rainbow_table.end()) {
				auto a = rainbow_table.find(hash);
				std::string sorted_org{a->second};
				std::sort(sorted_org.begin(), sorted_org.end());
				
				if (sorted_org != sorted) {
					std::cout << a->first << '\t' << a->second << '\t' << to_test << endl;
					++found_hash;
				}

			} else {
				rainbow_table[hash] = to_test;
			}
			
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
	
	// std::cout << double(found_hash) / total_num << std::endl;
	
	return float(found_hash) / total_num;
	
}