#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int res = a / b;
	cout << res;
	a = a % b;
	if (a == 0) return 0;
	cout << '.';
	unordered_map<int, int> map;
	vector<int> arr;
	int i = 0;
	while (a != 0) {
		if (map.find(a) == map.end()) {
			arr.push_back(a * 10 / b);
			map[a] = i;
			i++;
			a = a * 10 % b;
		}
		else {
			int k = map[a];
			for (int j = 0; j < k; j++) cout << arr[j];
			cout << '(';
			for (int j = k; j < i; j++) cout << arr[j];
			cout << ')';
			return 0;
		}
	}
	for (int j = 0; j < i; j++)
		cout << arr[j];

	system("pause");
	return 0;
}