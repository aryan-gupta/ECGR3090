/**
*** Name:		Aryan Gupta
*** 800#:		800963490
*** Assignment: Karatsuba Multiplication
*** Class:		ECGR3090
*** Brief:		This code multiplies 2 numbers together. The answer has a theoretical limit of 2^MAX_BIT - 1
**/


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
#include <cmath>
#include <bitset>	
#include <chrono>

typedef unsigned long long ull;
const size_t MAX_BIT = 10000;


namespace me {
	template <typename T> T max (T a, T b);
}

ull karatsuba (const ull x, const ull y);
std::string karatsuba (const std::string& x, const std::string& y)

std::bitset<MAX_BIT> ksbm (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);
std::bitset<MAX_BIT> add (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);
std::bitset<MAX_BIT> sub (const std::bitset<MAX_BIT>& x, std::bitset<MAX_BIT> y);
inline std::bitset<MAX_BIT> multiply (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);

std::bitset<MAX_BIT> str2bitset (std::string str);
void db2 (std::string& str);

std::string bitset2str (std::bitset<MAX_BIT> bit);
void mb2 (std::string& str);

size_t getLength (std::bitset<MAX_BIT> a);

int main() {
	cout << "7*6 = " << karatsuba(7, 6) << endl; // 42
    cout << "15*15 = " << karatsuba(15, 15) << endl; // 225
    cout << "6*13 = " << karatsuba(6, 13) << endl; // 78
    cout << "51*49 = " << karatsuba(51, 49) << endl; // 2499
    cout << "111*111 = " << karatsuba(111, 111) << endl; // 12321
    cout << "5678*1234 = " << karatsuba(5678, 1234) << endl; // 7006652
    cout << "12345678*1 = " << karatsuba(12345678, 1) << endl; // 12345678
    cout << "12345678*0 = " << karatsuba(12345678, 0) << endl; // 0
    return 0;

}

std::bitset<MAX_BIT> str2bitset (std::string str) {
	std::bitset<MAX_BIT> ret;
	size_t idx = 0;
	while (str != "") {
		ret[idx++] = (str[str.length() - 1] - '0') % 2;
		db2(str);
	}
	return ret;
}

void db2 (std::string& str) { // https://stackoverflow.com/questions/11006844
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

ull karatsuba (const ull x, const ull y) {
	return ksbm(x, y).to_ullong();
}

std::string karatsuba (const std::string& x, const std::string& y) {
	return bitset2str(ksbm(str2bitset(x), str2bitset(y)));
}

std::bitset<MAX_BIT> ksbm (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y) {
	using std::bitset;
	
	size_t len1 = getLength(x);
	size_t len2 = getLength(y);
	
	if (len1 <= 1 || len2 <= 1) {
		return multiply(x, y);
	}
	
	size_t halfSize = me::max(len1, len2) / 2;
	
	bitset<MAX_BIT> halfMask; // get bitmask for the second half of the digits
	for (int i = halfSize - 1; i >= 0; --i) {
		halfMask.set(i, 1);
	}
	
	bitset<MAX_BIT> a = x >> halfSize; // get first set of digits
	bitset<MAX_BIT> b = x & halfMask; // second set of digits (\sa bitmasking)
	
	bitset<MAX_BIT> c = y >> halfSize;
	bitset<MAX_BIT> d = y & halfMask;
	
	bitset<MAX_BIT> ac = ksbm(a, c);
	bitset<MAX_BIT> bd = ksbm(b, d);
	
	bitset<MAX_BIT> foil = ksbm(add(a, b), add(c, d)); // (a + b) * (c + d)
	
	bitset<MAX_BIT> subt = sub(sub(foil, bd), ac); // foil - bd - ac
	
	return add(add((ac << (halfSize * 2)), bd), (subt << halfSize)); // (ac << (halfSize * 2)) + bd + (subt << halfSize)
	
}

size_t getLength (std::bitset<MAX_BIT> a) {
	size_t len = 0;
	while (a.to_string().find("1") != std::string::npos) {
		a >>= 1; // bit shift right until it equalls 0
		len++;
	}
	return len;
}


void mb2 (std::string& str) {
	unsigned carry = 0; // this is digit by digit multiplication
	for (int i = str.length() - 1; i >= 0; --i) {
		unsigned ch = str[i] - '0';
		ch = ch * 2 + carry;
		if (ch > 9) {
			carry = 1;
			ch = ch % 10;
		} else carry = 0;
		str[i] = ch + '0';
	}
	
	if (carry != 0)
		str.insert(str.begin(), carry + '0');
}

std::string bitset2str (std::bitset<MAX_BIT> bit) {
	std::string str = "0";
	for (int i = getLength(bit) - 1; i >= 0; --i) {
		mb2 (str); // multiply numerical string by 2
		str[str.length() - 1] += bit[i];
	}
	return str;
}

namespace me { // not using std::max
	template <typename T>
	T max (T a, T b) {
		return (a > b)? a : b;
	}
}

std::bitset<MAX_BIT> sub (const std::bitset<MAX_BIT>& x, std::bitset<MAX_BIT> y) {
	y.flip(); // 2's complement 
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

inline std::bitset<MAX_BIT> multiply (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y) {
	if (x.to_ullong() == 1) // if either are 1, ten return other
		return y;
	if (y.to_ullong() == 1)
		return x;
	else
		return std::bitset<MAX_BIT>(0); // if either are 0, return a bitset of 0;
}