#include <bitset>
#include <iostream>

using namespace std;

bitset<32> add (bitset<32> x, bitset<32> y);

int main() {
	bitset<32> a = 18;
	bitset<32> b = 12;
	
	bitset<32> c = add(a, b);
	
	cout << c.to_ulong() << endl; 
}


bitset<32> add (bitset<32> x, bitset<32> y) {
	bitset<32> sum;
	unsigned carry = 0;
	for (size_t i = 0; i < 32; ++i) {
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