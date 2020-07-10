#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	char tar = s[0];
	int num = 1;
	if (s.length() < 2) {
		cout << s;
		return 0;
	}
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == tar)
			++num;
		else {
			if (num == 1) 
				cout << tar;
			else 
				cout << num - 1 << tar;

			tar = s[i];
			num = 1;
		}

		if (i == s.length() - 1) {
			if (num == 1)
				cout << s[i];
			else
				cout << num - 1 << s[i] << endl;
		}
	}
	system("pause");
	return 0;
}