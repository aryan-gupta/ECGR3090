/*
Write a program that takes as input a set of words and returns groups of anagrams
for those words. Here's the test program - 
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);

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