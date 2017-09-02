
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

typedef unsigned long long ull;
const size_t MAX_BIT = 20;


namespace me {
	template <typename T> T max (T a, T b);
}

ull karatsuba (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);
std::bitset<MAX_BIT> str2bitset(std::string str);
void db2 (std::string& str);

int main (int argc, char** argv) {
	using std::cout;
	using std::cin;
	using std::endl;
	
	std::string var1, var2;
	
	cout << "Please enter 2 numbers you want to muliply" << endl;
	cout << ":: ";
	cin >> var1;
	cout << ":: ";
	cin >> var2;
	
	std::bitset<MAX_BIT> x = str2bitset(var1);
	// cout << x.to_string() << endl;
	
	std::bitset<MAX_BIT> y = str2bitset(var2);
	// cout << y.to_string() << endl;
	
	exit(0);
	std::bitset<MAX_BIT> ans = karatsuba (x, y);
	
	//cout << "The answer is " << bitset2str(ans) << endl;
	
	return 0;
}

std::bitset<MAX_BIT> str2bitset(std::string str) {
	std::bitset<MAX_BIT> ret;
	size_t idx = 0;
	while (str != "") {
		ret[idx++] = (str[str.length() - 1] - '0') % 2;
		db2(str);
		// cout << str << endl;
	}
	return ret;
}

void db2 (std::string& str) {
	int nadd = 0;
	for (char& ch : str) {
		int add = nadd;
		
		if ((ch - '0') % 2 == 1) nadd = 5;
		else nadd = 0;
		
		ch = ((ch - '0') / 2 + add) + '0';
	}
	
	while (str[0] == '0') {
		str.erase(str.begin());
	}
}

ull karatsuba (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y) {
	const ull var1 = 12; const ull var2 = 12;
	// get half size
	size_t len1 = 0; //getLength(var1);
	size_t len2 = 0; //getLength(var2);
	
	if(len1 == 1 || len2 == 1) {
		return var1 * var2;
	}
	
	size_t halfSize = me::max(len1, len2) / 2;
	
	/* bitmask operation
		The code is pretty much getting a bunch of 1's with the size of halfSize
		EX. If halfSize = 4 -- (0b00001111)
		1 << halfSize = 0b00010000
		$_ - 1 = 0b00001111
	*/
	ull a = var1 >> halfSize, // get first set of digits
		b = var1 & ((1 << halfSize) - 1), // second set of digits (\sa bitmask operation)
		
		c = var2 >> halfSize,
		d = var2 & ((1 << halfSize) - 1);
	
	ull ac = karatsuba (a, c);
	ull bd = karatsuba (b, d);

	ull foil = karatsuba (a + b, c + d);
	
	ull sub = foil - bd - ac;
	
	ull ans = (ac << (halfSize * 2)) + bd + (sub << halfSize);
	
	return ans;
	
}

namespace me {
	template <typename T>
	T max (T a, T b) {
		return (a > b)? a : b;
	}
}