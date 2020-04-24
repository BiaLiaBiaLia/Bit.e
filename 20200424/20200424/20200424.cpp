#include<iostream>
using namespace std;

int Getsum(int n, int base) {
	int sum = 0;
	while (n) {
		sum += n % base;
		n /= base;
	}
	return sum;
}

int main() {
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 2; i < n; i++) {
			sum += Getsum(n, i);
		}

		int t, m;
		m = n - 2;
		if (sum < m) {
			t = sum;
			sum = m;
			m = t;
		}

		int a = sum, b = m;

		while (b) {
			t = a % b;
			a = b;
			b = t;
		}
		cout << sum / a << '/' << m / a << endl;
	}

	system("pause");
	return 0;
}