#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

bitset<10> add (bitset<10> x, bitset<10> y);
bitset<10> sub (const bitset<10>& x, bitset<10> y);

size_t getLength (std::bitset<10> a) {
	size_t len = 0;
	while (a.to_string().find("1") != std::string::npos) {
		// cout << a.to_string() << endl;
		a >>= 1;
		len++;
	}
	return len;
}

int main() {
	bitset<10> a = 105;
	bitset<10> b = 8;
	
	bitset<10> cor = 97;
	cout << b.to_string() << endl;
	bitset<10> c = sub(a, b);
	
	cout << c.to_string() << endl;
	cout <<	cor.to_string() << endl;
	cout << c.to_ullong() << endl; 
	cout << cor.to_ullong() << endl; 
}

bitset<10> sub (const bitset<10>& x, bitset<10> y) {
	y.flip();	
	return add(add(x, y), 1);
}

bitset<10> add (bitset<10> x, bitset<10> y) {
	bitset<10> sum;
	unsigned carry = 0;
	for (size_t i = 0; i < 10; ++i) {
		unsigned rawsum = x[i] + y[i] + carry;
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