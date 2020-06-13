#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int sum = 0;
	int x;
	vector<int> v;
	cin >> n;
	n *= 2;
	x = n;
	int temp;

	while (n--) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < x / 2; i++) {
		temp = v[0];
		v.erase(v.begin() + 0);
		int j;
		for (j = 0; j < v.size(); j++) {
			if (v[j] == temp) {
				sum += j;
				break;
			}
		}
		v.erase(v.begin() + j);
	}
	cout << sum << endl;

	system("pause");
	return 0;
}