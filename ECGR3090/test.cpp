#include <string>
#include <bitset>
#include <iostream>

using namespace std;

const size_t MAX_BIN = 200;

void db2 (string& str);
bitset<MAX_BIN> str2bin (std::string&& str);

int main () {
	// bitset<100> a = str2bin("123");
	// cout << a.to_string() << endl;
	// cout << a.to_ulong << endl;
	
	cout << str2bin("9999999999999999999999999999999999999999999999999999").to_string() << endl;
}

bitset<MAX_BIN> str2bin (std::string&& str) {
	bitset<MAX_BIN> ret;
	size_t idx = 0;
	while (str != "") {
		ret[idx++] = (str[str.length() - 1] - '0') % 2;
		db2(str);
		cout << str << endl;
	}
	return ret;
}

void db2 (string& str) {
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