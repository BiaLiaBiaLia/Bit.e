#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int father[10005];


int findF(int a) {
	if (father[a] != a) {
		return father[a] = findF(father[a]);
	}
	return a;
}

void merge(int x, int y) {
	int fx = findF(x);
	int fy = findF(y);

	if (fx != fy) {
		father[fx] = fy;
	}
}

int main() {
	int n, ai, m;
	cin >> n >> ai >> m;


	for (int i = 0; i < n; i++) {
		father[i] = i;
	}
	int a, b;
	int ans = 0, sub = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d,%d", &a, &b);
		if (a == ai || b == ai) {
			sub++;//我自己本来认识几个人
		}
		merge(a, b);
	}
	int root = findF(ai);
	for (int i = 0; i < n; i++) {
		if (findF(i) == root) {
			ans++;//我总共认识的人
		}
	}
	cout << ans - sub << endl;

	system("pause");
	return 0;
}
