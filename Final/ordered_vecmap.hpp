
#ifndef ORDERED_VECMAP
#define ORDERED_VECMAP

template <
	typename TKey,
	typename TValue //,
	//typename THash = std:: // we can add this functionality later
> class ordered_vecmap {
public:
	using key_type   = TKey;
	using value_type = TValue;
	using size_type  = size_t;
	
	ordered_vecmap();
	~ordered_vecmap();
	
	void add_key(const std::pair<key_type, value_type>&)
	void add_key()
	void set_new_value
	
private:
	
	std::unordered_map<key_type, size_type> mIndex; // this containtains all the indexes
	std::vector<std::pair<key_type, value_type>> mData; // this contains the actual data
	
};

#endif