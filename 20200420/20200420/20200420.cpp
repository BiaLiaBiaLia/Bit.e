#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

const int SIZE = 1e5 + 10;
long long num[SIZE] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int size;
		scanf("%d", &size);
		if (i != 0)
			num[i] = num[i - 1] + size;
		else
			num[i] = size;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		long long q;
		scanf("%lld", &q);
		int id = lower_bound(num, num + n, q) - num + 1;
		printf("%d", id);
		if (i != m - 1)
			printf("\n");
	}

	system("pause");
	return 0;
}