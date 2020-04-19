#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;


int a[105];
int ans[1005][2] = { 0 };

int getmin(int n) {
	int mi = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[mi])
			mi = i;
	}
	return mi;
}

int getmax(int n) {
	int ma = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[ma])
			ma = i;
	}
	return ma;
}

int main() {
	int n, k, j;
	int mi, ma;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (j = 0; j < k; j++) {
		mi = getmin(n);
		ma = getmax(n);
		if (a[ma] - a[mi] < 2) {
			break;
		}
		a[mi] += 1;
		a[ma] -= 1;
		ans[j][0] = ma + 1;
		ans[j][1] = mi + 1;
	}
	int Max = getmax(n);
	int Min = getmin(n);
	printf("%d %d", a[Max] - a[Min], j);
	if (j != 0)
		cout << endl;
	for (int i = 0; i < j; i++) {
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}

	system("pause");
	return 0;
}
