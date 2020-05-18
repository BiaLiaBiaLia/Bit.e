#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, step = 0;
	cin >> n;
	vector<int> couples(2 * n, 0);
	for (int i = 0; i < 2 * n; i++) {
		cin >> couples[i];
	}
	for (int i = n; i > 0; i--) {
		int last = couples[2 * i - 1];
		for (int j = 2 * i - 2; j >= 0; j--) {
			if (couples[j] != last) continue;
			int temp = couples[j];
			step += 2 * i - 1 - j - 1;
			for (int k = j; k < 2 * i - 2; k++) {
				couples[k] = couples[k + 1];
			}
			couples[2 * i - 2] = temp;
		}
	}
	cout << step << endl;

	system("pause");
	return 0;
}
