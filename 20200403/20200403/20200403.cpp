#include <iostream>
#define MAX 83
using namespace std;

//公式算法
//斐波那契数列前n项和=第(n+2)项值-1
int main()
{
	int form, to;
	long long a[MAX] = { 1,1 }, sum = 0;
	while (cin >> form >> to) {
		for (int i = 2; i < (to + 2); ++i) {
			a[i] = a[i - 1] + a[i - 2];
		}
		sum = a[to + 1] - a[form];
		cout << sum << endl;
	}

	system("pause");
	return 0;
}