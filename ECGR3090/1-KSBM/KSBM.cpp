
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
#include <cmath>
#include <bitset>	

typedef unsigned long long ull;
const size_t MAX_BIT = 20;


namespace me {
	template <typename T> T max (T a, T b);
}

std::bitset<MAX_BIT> karatsuba (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);
std::bitset<MAX_BIT> add (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);
std::bitset<MAX_BIT> sub (const std::bitset<MAX_BIT>& x, std::bitset<MAX_BIT> y);
std::bitset<MAX_BIT> str2bitset(std::string str);
void db2 (std::string& str);
size_t getLength (std::bitset<MAX_BIT> a);

int main (int argc, char** argv) {
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
	
	std::bitset<MAX_BIT> ans = karatsuba (x, y);
	
	//cout << "The answer is " << bitset2str(ans) << endl;
	cout << "The answer is " << ans.to_ulong() << endl;
	
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

std::bitset<MAX_BIT> karatsuba (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y) {
	using std::bitset;
	
	size_t len1 = getLength(x);
	size_t len2 = getLength(y);
	
	// if(len1 == 1 || len2 == 1) {
		// return x * y;
	// }
	
	size_t halfSize = me::max(len1, len2) / 2;
	
	bitset<MAX_BIT> halfMask;
	for (int i = halfSize - 1; i != -1; --i) {
		halfMask.set(i, 1);
	}
	
	bitset<MAX_BIT> a = x >> halfSize; // get first set of digits
	bitset<MAX_BIT> b = x & halfMask; // second set of digits (\sa bitmask operation)
	
	bitset<MAX_BIT> c = y >> halfSize;
	bitset<MAX_BIT> d = y & halfMask;
	
	bitset<MAX_BIT> ac = a.to_ulong() * c.to_ulong();
	bitset<MAX_BIT> bd = b.to_ulong() * d.to_ulong();
	
	bitset<MAX_BIT> foil = add(a, b).to_ulong() * add(c, d).to_ulong();
	
	bitset<MAX_BIT> subt = sub(sub(foil, bd), ac);
	
	bitset<MAX_BIT> ans = add(add((ac << (halfSize * 2)), bd), (subt << halfSize));
	
	return ans;
	
}

size_t getLength (std::bitset<MAX_BIT> a) {
	size_t len = 0;
	while (a.to_string().find("1") != std::string::npos) {
		// cout << a.to_string() << endl;
		a >>= 1;
		len++;
	}
	return len;
}

namespace me {
	template <typename T>
	T max (T a, T b) {
		return (a > b)? a : b;
	}
}

std::bitset<MAX_BIT> sub (const std::bitset<MAX_BIT>& x, std::bitset<MAX_BIT> y) {
	y.flip();	
	return add(add(x, y), 1);
}


std::bitset<MAX_BIT> add (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y) {
	std::bitset<MAX_BIT> sum;
	unsigned carry = 0; // max should be 3 (2 bits)
	for (size_t i = 0; i < MAX_BIT; ++i) {
		unsigned rawsum = x[i] + y[i] + carry; // max should be 3 (2 bits)
		if (rawsum == 2) {
			carry = 1; // 2 = 0b10
			sum[i] = 0;
		} else if (rawsum == 3) {
			carry = 1; // 3 = 0b11
			sum[i] = 1;
		} else {
			carry = 0;
			sum[i] = rawsum;
		}
	}
	return sum;
}