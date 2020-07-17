#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	vector<int>vec;
	int pos = 1;
	for (size_t i = 1; i < s.size() - 1; ++i) {
		if (s[i] == ',') {
			vec.push_back(stoi(s.substr(pos, i - pos)));
			pos = i + 1;
		}
	}
	vec.push_back(stoi(s.substr(pos, s.size() - pos)));
	if (vec.size() <= 2) {
		cout << vec[0] << endl;
		return 0;
	}
	sort(vec.begin(), vec.end());
	int cnt = 1;
	for (size_t i = 1; i < vec.size(); ++i) {
		if (cnt == vec.size() / 2) {
			cout << vec[i] << endl;
		}
		if (vec[i] == vec[i - 1]) {
			++cnt;
		}
		else {
			cnt = 1;
		}
	}

	system("pause");
	return 0;
}