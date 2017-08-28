
#include <iostream>
#include <string>

typedef unsigned long long ull;

ull doKM (const ull var1, const ull var2);


int main (int argc, char** argv) {
	using std::cout;
	using std::cin;
	using std::endl;
	
	ull var1, var2;
	
	cout << "Please enter 2 numbers you want to muliply" << endl;
	cout << ":: ";
	cin >> var1;
	cout << endl << ":: ";
	cin >> var2;
	cout << endl;
	
	ull ans = doKM(var1, var2);
	
	cout << "The answer is " << ans << endl;
	
	return 0;
}

ull doKM (const ull var1, const ull var2) {
	// get half sie
	int halfSize = std::to_string(var1).length();
	
	if(halfSize < 10) {
		return var1 * var2;
	}
	
	ull a = var1 / (10 * halfSize), b = var1 % (10 * halfSize);
	ull c = var2 / (10 * halfSize), d = var2 % (10 * halfSize);
	
	/*ull ac = a * c; // Call Karatsuba again for both these
	ull bd = b * d;*/
	ull ac = doKM(a, c);
	ull bd = doKM(b, d);
	
	ull foil = doKM(a + b, c + d);
	
	ull sub = foil - bd - ac;
	
	return sub;
	
	
}