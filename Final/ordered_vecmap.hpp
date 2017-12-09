
#ifndef ORDERED_VECMAP_HPP
#define ORDERED_VECMAP_HPP

#include <list>

namespace ari {

// I dont have the internet so Im going to create custom exxceptions,
// will later go back and find the std:: versions

struct key_not_found {};

// I am rushing through this so this may have some bad coding practacies

// This data structure gives the following benifits
//    O(1) look up time
//    O(1) insert time of new value
//    O(N) insert of pre-computed value
//    O(N) deletion
//    Ordered data

// This data structure keeys its data ordered by value_type and also offers 
// O(1) lookup and new-insertion of a key/value pair.

// This data structure assumes
//    The default created value is the lowest value possible
template <
	typename TKey,
	typename TValue //,
	//typename THash = std:: // we can add this functionality later
> class ordered_vecmap {
public:
	using key_type   = TKey;
	using value_type = TValue;
	using size_type  = size_t;
	using locator    = typename std::list<std::pair<key_type, value_type>>::iterator;
	
	ordered_vecmap() : mIndex{}, mData{} {}
	
	// void add_key(const std::pair<key_type, value_type>& pair) { add_key(pair.first, pair.second); }
	// void add_key(const key_type& key, const value_type& value) {
		// if (mIndex.find(key) == mIndex.end()) { // new key-value pair
			// mIndex.add({key, mData.size()}); // add the key so it now points to the last member of the vector
			// mData.emplace_back(key, 0.0); // insert new value
		// }
	// }
	
	// std::pair<key_type, value_type>& get_pair(const key_type& key) {
		// if (mIndex.find(key) == mIndex.end())
			// throw key_not_found{};
		
		// return mData[mIndex[key]];
	// }
	
	// value_type get_value(const key_type& key) {
		// if (mIndex.find(key) == mIndex.end())
			// throw key_not_found{};
		
		// return mData[mIndex[key]].second;
	// }
	
	// void set_new_value(const std::pair<key_type, value_type>& pair) { set_new_value(pair.first, pair.second); }
	// void set_new_value(const key_type& key, const value_type& value) {
		// if (mIndex.find(key) == mIndex.end())
			// throw key_not_found{};
		
		// mData[mIndex[key]].second = value;
	// }
	
	void add_to_value(const key_type& key, const value_type& val) {	
		// create valuu if not exists
		if (mIndex.find(key) == mIndex.end()) { // new key-value pair
			mData.emplace_back(key, 0.0); // insert new value
			mIndex.insert({key, --mData.end()}); // add the key so it now points to the last member of the vector
		}
		
		// add to the value
		locator idx = mIndex[key];
		idx->second += val;
		
		// fix it so its ordered
		// while the current value is out of ordered
		// and we havent reached the max value
		// also prevents iterator invalidation
		auto prev = std::prev(idx);
		while (idx != mData.begin() and idx->second > prev->second) {
			mData.splice(prev, mData, idx);
			--(--prev);
		}
	}
	
	std::list<std::pair<key_type, value_type>>& get_results() { return mData; }
	
private:
	
	std::unordered_map<key_type, locator> mIndex; // this containtains all the indexes
	std::list<std::pair<key_type, value_type>> mData; // this contains the actual data
	
};


} // end namespace ari

#endif // end ORDERED_VECMAP_HPP