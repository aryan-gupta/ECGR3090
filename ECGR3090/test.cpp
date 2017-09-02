#include <string>
#include <bitset>
#include <iostream>

using namespace std;

string db2 (string str);

int main () {
	// bitset<100> a = str2bin("123");
	// cout << a.to_string() << endl;
	// cout << a.to_ulong << endl;
	
	cout << db2("12345");
}

// bitset<100> str2bin (std::string&& str) {
	// bitset<100> ret;
	// while (str != 0) {
	
	// }
	// return ret;
// }

string db2 (string str) {
	int nadd = 0;
	for (char& ch : str) {
		int add = nadd;
		
		if ((ch - '0') % 2 == 1) nadd = 5;
		else nadd = 0;
		
		ch = ((ch - '0') / 2 + add) + '0';
	}
	return str;
}