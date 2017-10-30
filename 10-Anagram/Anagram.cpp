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
struct pi_str_hash {
	size_t operator()(const std::string& str) const {
		using ull = unsigned long long;
		
		size_t hash{};
		std::hash<ull> alg;
		
		for (char ch : str) { // we want to hash the actual char and not the placement
			ull num = ch; // cast
			unsigned shift = num % 15;
			num <<= shift;
			hash += alg(num);
		}
		
		// hash %= std::numeric_limits<size_t>::max();
		
		return hash;
	}
};

vector<vector<string>> findAnagrams(const vector<string>& dict)
{
	using anagram_map_t = std::unordered_map< std::string, std::vector<std::string>>;//, pi_str_hash>;
	anagram_map_t anagrams;
	
	typename anagram_map_t::hasher h = anagrams.hash_function();
	
	for (auto& str : dict) {
		std::cout << h(str) << std::endl;
		
		//anagrams[str].push_back(str);
		
		std::string sorted{str};
		std::sort(sorted.begin(), sorted.end());
		anagrams[sorted].push_back(str);
	}
	
	std::vector<std::vector<std::string>> ret_val;
	for (auto begin = anagrams.begin(), end = anagrams.end(); begin != end; ++begin) {
		std::cout << begin->second.size() << std::endl;
		if (begin->second.size() > 1)
			ret_val.push_back(begin->second);
	}
	
	return ret_val;
	
}