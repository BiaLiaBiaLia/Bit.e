#include <iostream>
#include <vector>
using namespace std;

//求斐波那契数列前x项和,和小于n
int main() {
	long long int n;
	while (cin >> n) {
		if (n == 1) {
			cout << 0 << endl;
			return 0;
		}

		if (n == 2) {
			cout << 1 << endl;
			return 0;
		}

		long long int f1 = 1, f2 = 1, f = 0;
		long long int res;
		res = f1 + f2;

		while (res < n) {
			f = f1 + f2;
			res += f;
			f1 = f2;
			f2 = f;
		}
		cout << res - f << endl;
	}

	system("pause");
	return 0;
}