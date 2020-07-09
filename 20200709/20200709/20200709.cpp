#include<iostream>
#include<algorithm>
using namespace std;

struct  Bear
{
	int a;//Õ½¶·Á¦
	int b;//¼¢¶öÖµ
	int num;
};

int Compare(Bear aa, Bear bb) {
	return aa.a > bb.a;
}

int Compare2(Bear aa, Bear bb) {
	return aa.num < bb.num;
}

int main() {
	int n, m, c[100], l[100] = { 0 }; Bear d[10];
	while (cin >> n >> m) {
		for (int i = 0; i < m; i++) cin >> c[i];
		for (int i = 0; i < n; i++) {
			cin >> d[i].a >> d[i].b;
			d[i].num = i;
		}
		sort(c, c + m);
		sort(d, d + n, Compare);
		for (int i = 0; i < n; i++) {
			int s = d[i].b;
			for (int j = m - 1; j >= 0; j--) {
				if (s >= c[j] && l[j] == 0) {
					s -= c[j];
					l[j] = 1;
				}
			}
			d[i].b = s;
		}
		sort(d, d + n, Compare2);
		for (int i = 0; i < n; i++) {
			cout << d[i].b << endl;
		}
	}

	system("pause");
	return 0;
}