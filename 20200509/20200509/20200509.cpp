#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	int pre = 0, last = n - 1;
	int res = 0;
	int tmp = 1;

	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			tmp += 1;
		}
		else {
			res = max(tmp, res);
			tmp = 1;
		}
	}

	if (s[pre] != s[last]) {
		tmp += 1;
		for (int i = 1; i < n - tmp + 1; ++i) {
			if (s[i] == s[i - 1]) {
				res = max(tmp, res);
				break;
			}
			tmp += 1;
		}
	}

	res = max(tmp, res);
	cout << res << endl;

	system("pause");
	return 0;
}