#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Æ´´ÕÕı·½ĞÎ
int main() {
	vector<int> input(4);

	for (int i = 0; i < 4; ++i)
		cin >> input[i];
	sort(input.begin(), input.end());

	int res = 0, tmp = 0;
	for (int i = 0; i < 4; ++i) {
		tmp += abs(input[i] - input[1]);
	}

	res = tmp;
	tmp = 0;
	for (int i = 0; i < 4; ++i) {
		tmp += abs(input[i] - input[2]);
	}

	res = min(tmp, res);
	cout << res << endl;

	system("pause");
	return 0;
}