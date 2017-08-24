
#include <iostream>
#include <string>

typedef ull unsigned long long;

ull doKM (const ull var1, const ull var2);

void main (int argc, char** argv) {
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
}

ull doKM (const ull var1, const ull var2) {
	std::string x = std::to_string(var1), y = std::to_string(var2);
	ull a = var1 / (10 * x.length()), b = var1 % (10 * x.length());
	ull c = var2 / (10 * y.length()), d = var2 % (10 * y.length());
	
	ull ac = a * b;
	ull bd = c * d;
	
	ull foil = (a + b) * (c + d);
	
	uul sub = foil - bd - ac;
	
	
}