
#include <iostream>
#include <string>
#include <cmath>

typedef unsigned long long ull;

ull doKM (const ull var1, const ull var2);
ull pow10(const int power);

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
	// get half sie
	int l1 = std::to_string(var1).length();
	int l2 = std::to_string(var2).length();
	
	if(l1 == 1 || l2 == 1) {
		return var1 * var2;
	}
	
	int halfSize = std::max(l1, l2) / 2;
	
	ull a = var1 / pow10(halfSize), b = var1 % pow10(halfSize);
	ull c = var2 / pow10(halfSize), d = var2 % pow10(halfSize);
	
	ull ac = a * c; // Call Karatsuba again for both these
	ull bd = b * d;
	//ull ac = doKM(a, c);
	//ull bd = doKM(b, d);
	
	ull foil = (a + b) * (c + d);
	//ull foil = doKM(a + b, c + d);
	
	ull sub = foil - bd - ac;
	
	return sub;
	
	
}

ull pow10 (const int power) {
	return std::pow(10, power);
}