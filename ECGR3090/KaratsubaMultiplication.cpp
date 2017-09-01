
#include <iostream>
#include <string>
#include <cmath>

typedef unsigned long long ull;

namespace me {
	// ull pow10 (ull power);
	
	// template <typename T> T max (T a, T b);
	
}

ull doKM (const ull var1, const ull var2);
size_t getLength (ull a);

int main (int argc, char** argv) {
	using std::cout;
	using std::cin;
	using std::endl;
	
	ull var1, var2;
	
	cout << "Please enter 2 numbers you want to muliply" << endl;
	cout << ":: ";
	cin >> var1;
	cout << ":: ";
	cin >> var2;
	
	ull ans = doKM(var1, var2);
	
	cout << "The answer is " << ans << endl;
	
	return 0;
}

ull doKM (const ull var1, const ull var2) {
	// get half size
	size_t len1 = getLength(var1);
	size_t len2 = getLength(var2);
	
	if(len1 == 1 || len2 == 1) {
		return var1 * var2;
	}
	
	size_t halfSize = std::max(len1, len2) / 2;
	
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
	
	ull ac = doKM(a, c);
	ull bd = doKM(b, d);

	ull foil = doKM(a + b, c + d);
	
	ull sub = foil - bd - ac;
	
	ull ans = (ac << (halfSize * 2)) + bd + (sub << halfSize);
	
	return ans;
	
}

size_t getLength (ull a) {
	size_t len = 0;
	while ((a = a >> 1) != 0) {
		++len;
	}
	return ++len;
}

namespace me {
	ull pow10 (ull power) {
		ull ans = 10;
		for (; power > 0; --power) {
			ans *= 10;
		}
	}
}