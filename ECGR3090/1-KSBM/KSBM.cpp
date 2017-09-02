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

typedef unsigned long long ull;
const size_t MAX_BIT = 10000;


namespace me {
	template <typename T> T max (T a, T b);
}

std::bitset<MAX_BIT> karatsuba (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);
std::bitset<MAX_BIT> add (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y);
std::bitset<MAX_BIT> sub (const std::bitset<MAX_BIT>& x, std::bitset<MAX_BIT> y);
std::bitset<MAX_BIT> str2bitset (std::string str);
void db2 (std::string& str);
std::string bitset2str (std::bitset<MAX_BIT> bit);
void mb2 (std::string& str);
size_t getLength (std::bitset<MAX_BIT> a);

int main (int argc, char** argv) {
	std::string var1, var2;
	
	cout << "Please enter 2 numbers you want to muliply. Current limit of answer is (2^" << MAX_BIT << " - 1)" << endl;
	cout << ":: ";
	cin >> var1;
	cout << ":: ";
	cin >> var2;
	
	std::bitset<MAX_BIT> x = str2bitset(var1); // convert both numbers string to binary bitset
	std::bitset<MAX_BIT> y = str2bitset(var2);
	
	std::bitset<MAX_BIT> ans = karatsuba(x, y); // do the karatsuba multiplication
	
	cout << "The answer is " << bitset2str(ans) << endl; // convert it back to a string and output the answer
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

std::bitset<MAX_BIT> karatsuba (const std::bitset<MAX_BIT>& x, const std::bitset<MAX_BIT>& y) {
	using std::bitset;
	
	size_t len1 = getLength(x);
	size_t len2 = getLength(y);
	
	if (len1 <= 1 || len2 <= 1) {
		// Current limitation prevents 2 binary number that are
		// 64 times larger than the other from being multiplied
		// by each other. This is 'cause the larger number cant
		// fit into a ull (64 bits) when the other number will 
		// probebly be a single bit number. (The factor is machine
		// dependent)
		return x.to_ullong() * y.to_ullong(); // multiply it normallt if either one of them is single bit
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
	
	bitset<MAX_BIT> ac = karatsuba(a, c);
	bitset<MAX_BIT> bd = karatsuba(b, d);
	
	bitset<MAX_BIT> foil = karatsuba(add(a, b), add(c, d)); // (a + b) * (c + d)
	
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