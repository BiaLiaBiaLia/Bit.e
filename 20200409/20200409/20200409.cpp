#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//最长上升子序列
int main() {
	int n;
	while (cin >> n) {
		vector <int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		vector <int> ve(n, 1);
		int res = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (v[i] > v[j])
					ve[i] = max(ve[i], ve[j] + 1);
			}
			res = max(res, ve[i]);
		}
		cout << res << endl;
	}

	system("pause");
	return 0;
}