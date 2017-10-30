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
		size_t hash{};
		std::hash<char> alg;
		for (char ch : str) { // we want to hash the actual char and not the placement
			hash ^= alg(ch);
		}
		
		return hash;
	}
};

vector<vector<string>> findAnagrams(const vector<string>& dict)
{
	std::unordered_map<
		std::string,
		std::vector<std::string>// ,
		// pi_str_hash
	> anagrams;
	
	// pi_str_hash h;
	
	for (auto& str : dict) {
		std::string str_sort{str};
		std::sort(str_sort.begin(), str_sort.end());
		anagrams[str_sort].push_back(str);
		
	}
	
	std::vector<std::vector<std::string>> ret_val;
	for (auto begin = anagrams.begin(), end = anagrams.end(); begin != end; ++begin) {
		// std::cout << begin->second.size() << std::endl;
		if (begin->second.size() > 1)
			ret_val.push_back(begin->second);
	}
	
	return ret_val;
	
}