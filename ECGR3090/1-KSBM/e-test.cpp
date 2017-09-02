#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

size_t getLength (std::bitset<32> a) {
	size_t len = 0;
	while (a.to_string().find("1") != std::string::npos) {
		// cout << a.to_string() << endl;
		a >>= 1;
		len++;
	}
	return len;
}

void mb2 (string& str) {
	unsigned carry = 0;
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

string bitset2str (std::bitset<32> bit) {
	string str = "0";
	for (int i = getLength(bit) - 1; i >= 0; --i) {
		mb2 (str);
		str[str.length() - 1] += bit[i];
		cout << str << endl;
	}
	return str;
}

int main() {
	cout << bitset2str(bitset<32>("1100010100")) << endl;
}