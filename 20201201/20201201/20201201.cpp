#include <iostream>
#include <string>
#include <vector>
using namespace std;


//两种排序方式
bool sort_dictionary(const vector<string>& str) {
	if (0 == str.size() || 1 == str.size())
		return true;
	for (size_t i = 0; i < str.size() - 1; ++i) {
		if (str[i] > str[i + 1])
			return false;
	}
	return true;
}

bool sort_length(const vector<string>& str) {
	if (0 == str.size() || 1 == str.size())
		return true;
	for (size_t i = 0; i < str.size() - 1; ++i) {
		if (str[i].length() > str[i + 1].length())
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<string> str(n);
		for (auto &e : str)
			cin >> e;

		if (1 == sort_dictionary(str) && 0 == sort_length(str)) {
			cout << "lexicographically" << endl;
			continue;
		}
		else if (0 == sort_dictionary(str) && 1 == sort_length(str)) {
			cout << "lengths" << endl;
			continue;
		}
		else if (1 == sort_dictionary(str) && 1 == sort_length(str)) {
			cout << "both" << endl;
			continue;
		}
		else {
			cout << "none" << endl;
			continue;
		}
	}

	system("pause");
	return 0;
}